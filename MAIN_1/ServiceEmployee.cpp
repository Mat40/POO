#include "ServiceEmployee.h"

namespace BB8Manager_Core_Services {

	list<Employee> ServiceEmployee::GetAll()
	{
		list<Employee> employeeList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Employee,
			"SELECT * FROM [Employee]");
		for each (DataRow ^ result in results)
		{
			Employee employee;
			employee.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
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
		return this->dataContext.GetDataset(DataContext::Tables::Employee,
			"SELECT * FROM [Employee]");
	}

	Employee ServiceEmployee::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Employee, "SELECT * FROM [Employee] WHERE id = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Employee employee;

		employee.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		employee.SetFirstname(this->dataContext.ToUnmanagedString(row["firstname"]->ToString()));
		employee.SetLastname(this->dataContext.ToUnmanagedString(row["lastname"]->ToString()));
		employee.SetHiringdate(this->dataContext.ToUnmanagedString(row["hiringdate"]->ToString()));
		employee.SetIdSuperior(std::stoi(this->dataContext.ToUnmanagedString(row["id_superior"]->ToString())));
		employee.SetIdAdress(std::stoi(this->dataContext.ToUnmanagedString(row["id_adress"]->ToString())));

		return employee;
	}

	Employee ServiceEmployee::Add(Employee employee) {
		this->dataContext.Insert("INSERT INTO [Employee] (firstname, lastname, hiringdate, id_superior, id_adress) VALUES ('" + employee.GetFirstname() + "', '" + employee.GetLastname() + "', '" + employee.GetHiringdate() + "', '" + std::to_string(employee.GetIdSuperior()) + "', '" + std::to_string(employee.GetIdAdress()) + "')");
		return employee;
	}

	void ServiceEmployee::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Employee] WHERE id = " + std::to_string(id));
	}
}