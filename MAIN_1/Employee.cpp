#include "Employee.h"

namespace BB8Manager_Core_Data_DAO {

	Employee::Employee() {}

	Employee::Employee(int id, std::string firstname, std::string lastname, std::string hiringdate, int id_superior, int id_adress) {
		this->id = id;
		this->firstname = firstname;
		this->lastname = lastname;
		this->hiringdate = hiringdate;
		this->id_superior = id_superior;
		this->id_adress = id_adress;
	}

	void Employee::SetId(int id) {
		this->id = id;
	};
	void Employee::SetFirstname(std::string firstname) {
		this->firstname = firstname;
	};
	void Employee::SetLastname(std::string lastname) {
		this->lastname = lastname;
	};
	void Employee::SetHiringdate(std::string hiringdate) {
		this->hiringdate = hiringdate;
	};
	void Employee::SetIdSuperior(int id_superior) {
		this->id_superior = id_superior;
	};
	void Employee::SetIdAdress(int id_adress) {
		this->id_adress = id_adress;
	};

	int Employee::GetId() {
		return this->id;
	};
	std::string Employee::GetFirstname() {
		return this->firstname;
	};
	std::string Employee::GetLastname() {
		return this->lastname;
	};
	std::string Employee::GetHiringdate() {
		return this->hiringdate;
	};
	int Employee::GetIdSuperior() {
		return this->id_superior;
	};
	int Employee::GetIdAdress() {
		return this->id_adress;
	};

}