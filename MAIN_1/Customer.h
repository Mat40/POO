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
		int id_billingadress;
		int id_deliveryadress;
	public:
		Customer();
		Customer(int id, std::string firstname, std::string lastname, std::string birthdate);

		void SetId(int id);
		void SetFirstname(std::string firstname);
		void SetLastname(std::string lastname);
		void SetBirthdate(std::string birthdate);
		void SetIdBillingAdress(int id_billingadress);
		void SetIdDeliveryAdress(int id_deliveryadress);

		int GetId();
		std::string GetFirstname();
		std::string GetLastname();
		std::string GetBirthdate();
		int GetIdBillingAdress();
		int GetIdDeliveryAdress();
	};
}