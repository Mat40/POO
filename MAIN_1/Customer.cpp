#include "Customer.h"

namespace BB8Manager_Core_Data_DAO {

	Customer::Customer() {}

	Customer::Customer(int id, std::string firstname, std::string lastname, std::string birthdate) {
		this->id = id;
		this->firstname = firstname;
		this->lastname = lastname;
		this->birthdate = birthdate;
	}

	void Customer::SetId(int id) {
		this->id = id;
	};
	void Customer::SetFirstname(std::string firstname) {
		this->firstname = firstname;
	};
	void Customer::SetLastname(std::string lastname) {
		this->lastname = lastname;
	};
	void Customer::SetBirthdate(std::string birthdate) {
		this->birthdate = birthdate;
	};

	int Customer::GetId() {
		return this->id;
	};
	std::string Customer::GetFirstname() {
		return this->firstname;
	};
	std::string Customer::GetLastname() {
		return this->lastname;
	};
	std::string Customer::GetBirthdate() {
		return this->birthdate;
	};

}