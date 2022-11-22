#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Customer
	{
	private:
		int id;
		std::string firstname;
		std::string lastname;
		std::string birthdate;
	public:
		Customer();
		Customer(int id, std::string firstname, std::string lastname, std::string birthdate);

		void SetId(int id);
		void SetFirstname(std::string firstname);
		void SetLastname(std::string lastname);
		void SetBirthdate(std::string birthdate);

		int GetId();
		std::string GetFirstname();
		std::string GetLastname();
		std::string GetBirthdate();
	};
}