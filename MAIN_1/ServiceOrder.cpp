#include "ServiceOrder.h"

namespace BB8Manager_Core_Services {

	list<Order> ServiceOrder::GetAll()
	{
		list<Order> orderList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Order,
			"SELECT * FROM [Order]");
		for each (DataRow ^ result in results)
		{
			Order order;
			order.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			order.SetReference(this->dataContext.ToUnmanagedString(result["reference"]->ToString()));
			order.SetDateDelivery(this->dataContext.ToUnmanagedString(result["datedelivery"]->ToString()));
			order.SetDateInssuance(this->dataContext.ToUnmanagedString(result["dateinssuance"]->ToString()));
			order.SetDateSettlement(this->dataContext.ToUnmanagedString(result["datesettlement"]->ToString()));
			order.SetSettlementBalance(std::stof(this->dataContext.ToUnmanagedString(result["settlementbalance"]->ToString())));
			order.SetIdCustomer(std::stoi(this->dataContext.ToUnmanagedString(result["id_customer"]->ToString())));

			orderList.push_back(order);
		}

		return orderList;
	}

	Order ServiceOrder::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Item, "SELECT * FROM [Order] WHERE id = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Order order;

		order.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		order.SetReference(this->dataContext.ToUnmanagedString(row["reference"]->ToString()));
		order.SetDateDelivery(this->dataContext.ToUnmanagedString(row["datedelivery"]->ToString()));
		order.SetDateInssuance(this->dataContext.ToUnmanagedString(row["dateinssuance"]->ToString()));
		order.SetDateSettlement(this->dataContext.ToUnmanagedString(row["datesettlement"]->ToString()));
		order.SetSettlementBalance(std::stof(this->dataContext.ToUnmanagedString(row["settlementbalance"]->ToString())));
		order.SetIdCustomer(std::stoi(this->dataContext.ToUnmanagedString(row["id_customer"]->ToString())));

		return order;
	}

	Order ServiceOrder::Add(Order order) {
		this->dataContext.Insert("INSERT INTO [Order] (reference, datedelivery, dateinssuance, datesettlement, settlementbalance, id_customer) VALUES ('" + order.GetReference() + "', '" + order.GetDateDelivery() + "', '" + order.GetDateInssuance() + "', '" + order.GetDateSettlement() + "', '" + std::to_string(order.GetSettlementBalance()) + "', '" + std::to_string(order.GetIdCustomer()) + "')");
		return order;
	}

	void ServiceOrder::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Order] WHERE id = " + std::to_string(id));
	}
}