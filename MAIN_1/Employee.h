#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Employee
	{
	private:
		int id;
		std::string firstname;
		std::string lastname;
		std::string hiringdate;
		int id_superior;
		int id_adress;
	public:
		Employee();
		Employee(int id, std::string firstname, std::string lastname, std::string hiringdate, int id_superior, int id_adress);

		void SetId(int id);
		void SetFirstname(std::string firstname);
		void SetLastname(std::string lastname);
		void SetHiringdate(std::string hiringdate);
		void SetIdSuperior(int id_superior);
		void SetIdAdress(int id_adress);

		int GetId();
		std::string GetFirstname();
		std::string GetLastname();
		std::string GetHiringdate();
		int GetIdSuperior();
		int GetIdAdress();
	};
}