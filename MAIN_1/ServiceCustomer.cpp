//#include "pch.h"
#include "ServiceCustomer.h"

namespace BB8Manager_Core_Services {

	list<Customer> ServiceCustomer::GetAll()
	{
		list<Customer> customerList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Customer,
			"SELECT * FROM [Customer]");
		for each (DataRow ^ result in results)
		{
			Customer customer;
			customer.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			customer.SetFirstname(this->dataContext.ToUnmanagedString(result["firstname"]->ToString()));
			customer.SetLastname(this->dataContext.ToUnmanagedString(result["lastname"]->ToString()));
			customer.SetBirthdate(this->dataContext.ToUnmanagedString(result["birthdate"]->ToString()));

			customerList.push_back(customer);
		}

		return customerList;
	}

	Customer ServiceCustomer::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Customer, "SELECT * FROM [Customer] WHERE id = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Customer customer;

		customer.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		customer.SetFirstname(this->dataContext.ToUnmanagedString(row["firstname"]->ToString()));
		customer.SetLastname(this->dataContext.ToUnmanagedString(row["lastname"]->ToString()));
		customer.SetBirthdate(this->dataContext.ToUnmanagedString(row["birthdate"]->ToString()));

		return customer;
	}

	Customer ServiceCustomer::Add(Customer customer) {
		this->dataContext.Insert("INSERT INTO [Customer] (firstname, lastname, birthdate) VALUES ('" + customer.GetFirstname() + "', '" + customer.GetLastname() + "', '" + customer.GetBirthdate() + "')");
		return customer;
	}

	void ServiceCustomer::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Customer] WHERE id = " + std::to_string(id));
	}
}