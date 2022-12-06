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

	Order ServiceOrder::Get(std::string reference) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Ordered, "SELECT * FROM [Ordered] WHERE reference = '" + reference + "'");

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

		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetOrdered, "SELECT reference, Customer.firstname + ' ' + Customer.lastname as name, reference, datedelivery, dateinssuance, datesettlement, settlementbalance, fullprice FROM [Ordered] INNER JOIN [Customer] ON Ordered.id_customer = Customer.id_customer WHERE Customer.firstname LIKE '" + value + "%' OR Customer.lastname LIKE '" + value + "%' OR Ordered.reference LIKE '" + value + "%';");
		return result;
	}

	Order ServiceOrder::Add(Order order) {
		order.SetId(this->dataContext.Insert("INSERT INTO [Ordered] (reference, datedelivery, dateinssuance, datesettlement, settlementbalance, fullprice, id_customer) VALUES ('" + order.GetReference() + "', '" + order.GetDateDelivery() + "', '" + order.GetDateInssuance() + "', '" + order.GetDateSettlement() + "', '" + std::to_string(order.GetSettlementBalance()) + "', '" + std::to_string(order.GetFullprice()) + "', '" + std::to_string(order.GetIdCustomer()) + "')"));
		return order;
	}

	void ServiceOrder::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Hold] WHERE id_order = " + std::to_string(id));
		this->dataContext.Query("DELETE FROM [Ordered] WHERE id_order = " + std::to_string(id));
	}

	std::string ServiceOrder::GetLastOrderRef(std::string reflike) {
		std::string result = this->dataContext.QueryReturn("SELECT TOP 1 reference FROM [Ordered] WHERE reference LIKE '" + reflike + "%' ORDER BY id_order DESC;");
		std::string reference;
		if (result == "") {
			reference = reflike + "1";
		}
		else {
			reference = reflike + std::to_string(std::stoi(result.substr(11, 12)) + 1);
		}
		return reference;
	}

	void ServiceOrder::AddHold(int quantity, int id_order, int id_item) {
		int id = this->dataContext.Insert("INSERT INTO [Hold] (quantity, id_order, id_item) VALUES ('" + std::to_string(quantity) + "', '" + std::to_string(id_order) + "', '" + std::to_string(id_item) + "')");
	}

	void ServiceOrder::UpdateHold(int quantity, int id_order, int id_item) {
		this->dataContext.Query("UPDATE [Hold] SET quantity = '" + std::to_string(quantity) + "' WHERE id_order = '" + std::to_string(id_order) + "' AND id_item = '" + std::to_string(id_item) + "'");
	}

	void ServiceOrder::RemoveHold(int id_order, int id_item) {
		this->dataContext.Query("DELETE FROM [Hold] WHERE id_order = '" + std::to_string(id_order) + "' AND id_item = '" + std::to_string(id_item) + "'");
	}

	int ServiceOrder::GetMaxId()
	{
		std::string result = this->dataContext.QueryReturn("SELECT CASE WHEN(SELECT COUNT(1) FROM [Ordered]) = 0 THEN 1 ELSE IDENT_CURRENT('Ordered') + 1 END AS Current_Identity; ");

		if (std::stoi(result) == NULL)
			throw std::runtime_error("id not found !");
		return std::stoi(result);
	}
	int ServiceOrder::GetHoldAmount(int id_order, int id_item) {
		std::string result = this->dataContext.QueryReturn("SELECT quantity FROM [Hold] WHERE id_order = '" + std::to_string(id_order) + "' AND id_item = '" + std::to_string(id_item) + "';");
		int amount;
		if (result == "") {
			amount = 0;
		}
		else {
			amount = std::stoi(result);
		}
		return amount;
	}
	void ServiceOrder::Update(std::string reference, float totalorderprice, std::string datesettlement, float balance) {
		this->dataContext.Query("UPDATE [Ordered] SET fullprice = '" + std::to_string(totalorderprice) + "', datesettlement = '" + datesettlement +"', settlementbalance = '" + std::to_string(balance) + "'  WHERE reference = '" + reference + "'");
	}

	std::string ServiceOrder::GetAvgPrice()
	{
		return dataContext.QueryReturn("SELECT AVG(fullprice) FROM [Ordered]; ");
	}
	// automatiser pour tester touts les ids prouits
	std::string ServiceOrder::GetStockPriceValueHT()
	{
		return dataContext.QueryReturn("SELECT sum(price_excl_taxes * S.amount) from [Item] I INNER JOIN [Stock] S on S.id_stock = I.id_item ");
	}
	std::string ServiceOrder::GetStockPriceValueTTC()
	{
		return dataContext.QueryReturn("SELECT sum((vat + price_excl_taxes) * S.amount) from [Item] I INNER JOIN [Stock] S on S.id_stock = I.id_item");
	}

	std::string ServiceOrder::GetItemReorderNeeded()
	{
		return dataContext.QueryReturn("select id_stock From [Stock] where amount < reorder_threshold; ");
	}

	std::string ServiceOrder::GetTotalSalesPriceMonth(int mois)
	{
		
		std::string var_return;
		var_return = dataContext.QueryReturn("SELECT SUM(fullprice) FROM [Ordered] where month(datesettlement) = '" + std::to_string(mois) + "'");
		
		if (var_return == "" || var_return == "0" || var_return == " ") {
			return "no value for this month";
		}
		else {
			return var_return;
		}
		//return "value:" + std::to_string(mois) + "<<<<<<<";

	}

	std::string ServiceOrder::GetCustomerTotalSpend(int userid)
	{
		std::string var_return;
		var_return = dataContext.QueryReturn("SELECT sum(fullprice) from [Ordered] where id_customer = '" + std::to_string(userid) + "'"); // 1"); // 


		if (var_return == "") {
			return "no value for this user";
		}
		else {
			return var_return;
		}
	}

}