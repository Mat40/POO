#pragma once
#include <list>
#include "Order.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceOrder : AbstractService
	{
	public:
		std::list<Order> GetAll();
		Order Get(std::string reference);
		DataSet^ GetDataSet();
		DataSet^ GetSearchDataSet(std::string value);
		Order Add(Order order);
		void Remove(int id);
		std::string GetLastOrderRef(std::string reflike);
		void AddHold(int quantity, int id_order, int id_item);
		void UpdateHold(int quantity, int id_order, int id_item);
		int GetMaxId();
		int GetHoldAmount(int id_order, int id_item);
		void RemoveHold(int id_order, int id_item);
		void Update(std::string reference, float totalorderprice, std::string datesettlement, float balance);

		std::string GetAvgPrice();
		std::string ServiceOrder::GetStockPriceValueHT();
		std::string ServiceOrder::GetStockPriceValueTTC();
		std::string ServiceOrder::GetItemReorderNeeded();
		std::string ServiceOrder::GetTotalSalesPriceMonth(int mois);
		std::string ServiceOrder::GetCustomerTotalSpend(int userid);
	};
}