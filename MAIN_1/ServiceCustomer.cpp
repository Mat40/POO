//#include "pch.h"
#pragma once
#include "ServiceCustomer.h"

namespace BB8Manager_Core_Services {

	std::list<Customer> ServiceCustomer::GetAll()
	{
		std::list<Customer> customerList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Customer,
			"SELECT * FROM [Customer]");
		for each (DataRow ^ result in results)
		{
			Customer customer;
			customer.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			customer.SetFirstname(this->dataContext.ToUnmanagedString(result["firstname"]->ToString()));
			customer.SetLastname(this->dataContext.ToUnmanagedString(result["lastname"]->ToString()));
			customer.SetBirthdate(this->dataContext.ToUnmanagedString(result["birthdate"]->ToString()));
			customer.SetIdBillingAdress(std::stoi(this->dataContext.ToUnmanagedString(result["id_billingadress"]->ToString())));
			customer.SetIdDeliveryAdress(std::stoi(this->dataContext.ToUnmanagedString(result["id_deliveryadress"]->ToString())));

			customerList.push_back(customer);
		}

		return customerList;
	}

	Customer ServiceCustomer::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Customer, "DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];SELECT Customer.id_customer, firstname, lastname, birthdate, has.id_adress as id_deliveryadress INTO temptable1 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.billing = '1' AND Customer.id_customer = '" + std::to_string(id) + "';SELECT Customer.id_customer, has.id_adress  AS id_billingadress INTO temptable2 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.delivery = '1' AND Customer.id_customer = '" + std::to_string(id) + "';SELECT temptable1.id_customer, temptable1.firstname, temptable1.lastname, birthdate, temptable1.id_deliveryadress, temptable2.id_billingadress FROM temptable1 INNER JOIN temptable2 ON temptable1.id_customer = temptable2.id_customer;DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];");

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Customer customer;

		customer.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		customer.SetFirstname(this->dataContext.ToUnmanagedString(row["firstname"]->ToString()));
		customer.SetLastname(this->dataContext.ToUnmanagedString(row["lastname"]->ToString()));
		customer.SetBirthdate(this->dataContext.ToUnmanagedString(row["birthdate"]->ToString()));
		customer.SetIdBillingAdress(std::stoi(this->dataContext.ToUnmanagedString(row["id_billingadress"]->ToString())));
		customer.SetIdDeliveryAdress(std::stoi(this->dataContext.ToUnmanagedString(row["id_deliveryadress"]->ToString())));


		return customer;
	}

	Customer ServiceCustomer::Add(Customer customer) {
		customer.SetId(this->dataContext.Insert("INSERT INTO [Customer] (firstname, lastname, birthdate) VALUES ('" + customer.GetFirstname() + "', '" + customer.GetLastname() + "', '" + customer.GetBirthdate() + "')"));
		if (customer.GetIdDeliveryAdress() == customer.GetIdBillingAdress()) {
			this->dataContext.Query("INSERT INTO [Has] (id_customer, id_adress, delivery, billing) VALUES ('" + std::to_string(customer.GetId()) + "', '" + std::to_string(customer.GetIdDeliveryAdress()) + "', 1, 1)");
		}
		else {
			this->dataContext.Query("INSERT INTO [Has] (id_customer, id_adress, delivery, billing) VALUES ('" + std::to_string(customer.GetId()) + "', '" + std::to_string(customer.GetIdDeliveryAdress()) + "', 1, 0)");
			this->dataContext.Query("INSERT INTO [Has] (id_customer, id_adress, delivery, billing) VALUES ('" + std::to_string(customer.GetId()) + "', '" + std::to_string(customer.GetIdBillingAdress()) + "', 0, 1)");
		}
		return customer;
	}

	void ServiceCustomer::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Customer] WHERE id_customer = " + std::to_string(id));
		this->dataContext.Query("DELETE FROM [Has] WHERE id_customer = " + std::to_string(id));
	}

	DataSet^ ServiceCustomer::GetDataSet()
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetCustomer, "DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];SELECT Customer.id_customer, firstname, lastname, birthdate, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode as deliveryadress INTO temptable1 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.billing = '1';SELECT Customer.id_customer, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode AS billingadress INTO temptable2 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.delivery = '1';SELECT temptable1.id_customer, temptable1.firstname + ' ' + temptable1.lastname AS customername, birthdate, deliveryadress, billingadress FROM temptable1 INNER JOIN temptable2 ON temptable1.id_customer = temptable2.id_customer;DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];");
		return result;
	}

	DataSet^ ServiceCustomer::GetSearchDataSet(std::string value)
	{
		//DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::Employee, "SELECT * FROM [Employee]");

		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetCustomer, "DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];SELECT Customer.id_customer, firstname, lastname, birthdate, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode as deliveryadress INTO temptable1 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.billing = '1';SELECT Customer.id_customer, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode AS billingadress INTO temptable2 FROM [Customer] JOIN [Has] ON Customer.id_customer = has.id_customer JOIN [Adress] ON has.id_adress = Adress.id_adress WHERE has.delivery = '1';SELECT temptable1.id_customer, temptable1.firstname + ' ' + temptable1.lastname AS customername, birthdate, deliveryadress, billingadress FROM temptable1 INNER JOIN temptable2 ON temptable1.id_customer = temptable2.id_customer WHERE temptable1.firstname LIKE '" + value + "%' OR temptable1.lastname LIKE '" + value + "%';DROP TABLE IF EXISTS [dbo].[temptable1];DROP TABLE IF EXISTS [dbo].[temptable2];");
		return result;
	}

	void ServiceCustomer::Update(Customer customer) {
		this->dataContext.Query("UPDATE [Customer] SET firstname = '" + customer.GetFirstname() + "', lastname = '" + customer.GetLastname() + "', birthdate = '" + customer.GetBirthdate() + "' WHERE id_customer = '" + std::to_string(customer.GetId()) + "'");
	}
}