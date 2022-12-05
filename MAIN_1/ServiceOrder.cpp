#pragma once
#include "ServiceOrder.h"

namespace BB8Manager_Core_Services {

	std::list<Order> ServiceOrder::GetAll()
	{
		std::list<Order> orderList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Ordered,
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
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Ordered, "SELECT * FROM [Order] WHERE id = " + std::to_string(id));

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

	DataSet^ ServiceOrder::GetDataSet()
	{
		//DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::Employee, "SELECT * FROM [Employee]");

		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetOrdered, "SELECT reference, Customer.firstname + ' ' + Customer.lastname as name, datedelivery, dateinssuance, datesettlement, settlementbalance, fullprice FROM [Ordered] INNER JOIN [Customer] ON Ordered.id_customer = Customer.id_customer; ");
		return result;
	}

	DataSet^ ServiceOrder::GetSearchDataSet(std::string value)
	{
		//DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::Employee, "SELECT * FROM [Employee]");

		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetOrdered, "SELECT reference, Customer.firstname + ' ' + Customer.lastname as name, reference, datedelivery, dateinssuance, datesettlement, settlementbalance, fullprice FROM [Ordered] INNER JOIN [Customer] ON Ordered.id_customer = Customer.id_customer WHERE Customer.firstname LIKE '" + value + "%' OR Customer.lastname LIKE '" + value + "%';");
		return result;
	}

	Order ServiceOrder::Add(Order order) {
		this->dataContext.Insert("INSERT INTO [Order] (reference, datedelivery, dateinssuance, datesettlement, settlementbalance, id_customer) VALUES ('" + order.GetReference() + "', '" + order.GetDateDelivery() + "', '" + order.GetDateInssuance() + "', '" + order.GetDateSettlement() + "', '" + std::to_string(order.GetSettlementBalance()) + "', '" + std::to_string(order.GetIdCustomer()) + "')");
		return order;
	}

	void ServiceOrder::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Order] WHERE id = " + std::to_string(id));
	}
	std::string ServiceOrder::avg_ordered()
	{
		return dataContext.Query_return("SELECT AVG(fullprice) FROM [Ordered]; ");
	}
	// automatiser pour tester touts les ids prouits
	std::string ServiceOrder::panier_HT()
	{
		return dataContext.Query_return("SELECT sum(price_excl_taxes * S.amount) from [Item] I INNER JOIN [Stock] S on S.id_stock = I.id_item ");
	}
	std::string ServiceOrder::panier_TTC()
	{
	return dataContext.Query_return("SELECT sum((vat + price_excl_taxes) * S.amount) from [Item] I INNER JOIN [Stock] S on S.id_stock = I.id_item");
	}

	std::string ServiceOrder::reaprovisionnement()
	{
		return dataContext.Query_return("select id_stock From [Stock] where amount < reorder_threshold; ");
	}

	std::string ServiceOrder::vente_mois(int mois)
	{
		return dataContext.Query_return("SELECT SUM(fullprice) FROM [Ordered] where month(datesettlement) = 09;");
	}
}
