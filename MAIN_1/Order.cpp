#include "Order.h"

namespace BB8Manager_Core_Data_DAO {
	Order::Order()
	{
	}
	Order::Order(int id, std::string reference, std::string datedelivery, std::string dateinssuance, std::string datesettlement, float settlementbalance, int id_customer)
	{
		this->id = id;
		this->reference = reference;
		this->datedelivery = datedelivery;
		this->dateinssuance = dateinssuance;
		this->datesettlement = datesettlement;
		this->settlementbalance = settlementbalance;
		this->id_customer = id_customer;
	}
	void Order::SetId(int id)
	{
		this->id = id;
	}
	void Order::SetReference(std::string reference)
	{
		this->reference = reference;
	}
	void Order::SetDateDelivery(std::string datedelivery)
	{
		this->datedelivery = datedelivery;
	}
	void Order::SetDateInssuance(std::string dateinssuance)
	{
		this->dateinssuance = dateinssuance;
	}
	void Order::SetDateSettlement(std::string datesettlement)
	{
		this->datesettlement = datesettlement;
	}
	void Order::SetSettlementBalance(float settlementbalance)
	{
		this->settlementbalance = settlementbalance;
	}
	void Order::SetIdCustomer(int id_customer)
	{
		this->id_customer = id_customer;
	}
	int Order::GetId()
	{
		return this->id;
	}
	std::string Order::GetReference()
	{
		return this->reference;
	}
	std::string Order::GetDateDelivery()
	{
		return this->datedelivery;
	}
	std::string Order::GetDateInssuance()
	{
		return this->dateinssuance;
	}
	std::string Order::GetDateSettlement()
	{
		return this->datesettlement;
	}
	float Order::GetSettlementBalance()
	{
		return this->settlementbalance;
	}
	int Order::GetIdCustomer()
	{
		return this->id_customer;
	}
}