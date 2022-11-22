#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Order
	{
	private:
		int id;
		std::string reference;
		std::string datedelivery;
		std::string dateinssuance;
		std::string datesettlement;
		float settlementbalance;
		int id_customer;
	public:
		Order();
		Order(int id, std::string reference, std::string datedelivery, std::string dateinssuance, std::string datesettlement, float settlementbalance, int id_customer);

		void SetId(int id);
		void SetReference(std::string reference);
		void SetDateDelivery(std::string datedelivery);
		void SetDateInssuance(std::string dateinssuance);
		void SetDateSettlement(std::string datesettlement);
		void SetSettlementBalance(float settlementbalance);
		void SetIdCustomer(int id_customer);

		int GetId();
		std::string GetReference();
		std::string GetDateDelivery();
		std::string GetDateInssuance();
		std::string GetDateSettlement();
		float GetSettlementBalance();
		int GetIdCustomer();
	};
}