#pragma once
#include "ServiceEmployee.h"
#include "ServiceAdress.h"

namespace BB8Manager_Core_Services {
	ServiceEmployee::ServiceEmployee(void) {
	
	}

	std::list<Employee> ServiceEmployee::GetAll()
	{
		std::list<Employee> employeeList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Employee, "SELECT * FROM [Employee]");
		for each (DataRow ^ result in results)
		{
			Employee employee;
			employee.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id_employee"]->ToString())));
			employee.SetFirstname(this->dataContext.ToUnmanagedString(result["firstname"]->ToString()));
			employee.SetLastname(this->dataContext.ToUnmanagedString(result["lastname"]->ToString()));
			employee.SetHiringdate(this->dataContext.ToUnmanagedString(result["hiringdate"]->ToString()));
			employee.SetIdSuperior(std::stoi(this->dataContext.ToUnmanagedString(result["id_superior"]->ToString())));
			employee.SetIdAdress(std::stoi(this->dataContext.ToUnmanagedString(result["id_adress"]->ToString())));

			employeeList.push_back(employee);
		}

		return employeeList;
	}

	DataSet^ ServiceEmployee::GetDataSet()
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetEmployee, "SELECT Employee.id_employee, Employee.firstname + ' ' + Employee.lastname as name, Employee.hiringdate, Superior.firstname + ' ' + Superior.lastname as superior, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode as adress FROM [Employee] INNER JOIN [Adress] ON Employee.id_adress = Adress.id_adress LEFT JOIN [Employee] as Superior ON Employee.id_superior = Superior.id_employee; ");
		return result;
	}

	DataSet^ ServiceEmployee::GetSearchDataSet(std::string value)
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetEmployee, "SELECT Employee.id_employee, Employee.firstname + ' ' + Employee.lastname as name, Employee.hiringdate, Superior.firstname + ' ' + Superior.lastname as superior, streetnumber + ' ' + streetname + ' ' + city + ' ' + postalcode as adress FROM [Employee] INNER JOIN [Adress] ON Employee.id_adress = Adress.id_adress LEFT JOIN [Employee] as Superior ON Employee.id_superior = Superior.id_employee WHERE Employee.firstname LIKE '" + value + "%' OR Employee.lastname LIKE '" + value + "%';");
		return result;
	}

	DataSet^ ServiceEmployee::GetDataSetSuperior()
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetSuperior, "SELECT Employee.id_employee, Employee.firstname + ' ' + Employee.lastname as name FROM [Employee];");
		return result;
	}

	Employee ServiceEmployee::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Employee, "SELECT * FROM [Employee] WHERE id_employee = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Employee employee;

		employee.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id_employee"]->ToString())));
		employee.SetFirstname(this->dataContext.ToUnmanagedString(row["firstname"]->ToString()));
		employee.SetLastname(this->dataContext.ToUnmanagedString(row["lastname"]->ToString()));
		employee.SetHiringdate(this->dataContext.ToUnmanagedString(row["hiringdate"]->ToString()));
		if (this->dataContext.ToUnmanagedString(row["id_superior"]->ToString()) == "") {
			employee.SetIdSuperior(NULL);
		}
		else {
			employee.SetIdSuperior(std::stoi(this->dataContext.ToUnmanagedString(row["id_superior"]->ToString())));
		}
		employee.SetIdAdress(std::stoi(this->dataContext.ToUnmanagedString(row["id_adress"]->ToString())));

		return employee;
	}

	Employee ServiceEmployee::Add(Employee employee) {
		employee.SetId(this->dataContext.Insert("INSERT INTO [Employee] (firstname, lastname, hiringdate, id_superior, id_adress) VALUES ('" + employee.GetFirstname() + "', '" + employee.GetLastname() + "', '" + employee.GetHiringdate() + "', '" + std::to_string(employee.GetIdSuperior()) + "', '" + std::to_string(employee.GetIdAdress()) + "')"));
		return employee;
	}

	void ServiceEmployee::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Employee] WHERE id_employee = " + std::to_string(id));
	}

	void ServiceEmployee::Update(Employee employee) {
		this->dataContext.Query("UPDATE [Employee] SET firstname = '" + employee.GetFirstname() + "', lastname = '" + employee.GetLastname() + "', hiringdate = '" + employee.GetHiringdate() + "', id_superior = '" + std::to_string(employee.GetIdSuperior()) + "' WHERE id_employee = '" + std::to_string(employee.GetId()) + "'");
	}
}