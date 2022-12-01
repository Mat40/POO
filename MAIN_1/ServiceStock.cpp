#pragma once
#include "ServiceStock.h"

namespace BB8Manager_Core_Services {

	std::list<Stock> ServiceStock::GetAll()
	{
		std::list<Stock> stockList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Stock,
			"SELECT * FROM [Stock]");
		for each (DataRow ^ result in results)
		{
			Stock stock;
			stock.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			stock.SetAmount(std::stoi(this->dataContext.ToUnmanagedString(result["amount"]->ToString())));
			stock.SetReorderThreshold(std::stoi(this->dataContext.ToUnmanagedString(result["reorderthreshold"]->ToString())));
			stock.SetIdItem(std::stoi(this->dataContext.ToUnmanagedString(result["id_item"]->ToString())));

			stockList.push_back(stock);
		}

		return stockList;
	}

	Stock ServiceStock::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Stock, "SELECT * FROM [Stock] WHERE id_item = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Stock stock;

		stock.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		stock.SetAmount(std::stoi(this->dataContext.ToUnmanagedString(row["amount"]->ToString())));
		stock.SetReorderThreshold(std::stoi(this->dataContext.ToUnmanagedString(row["reorder_threshold"]->ToString())));
		stock.SetIdItem(std::stoi(this->dataContext.ToUnmanagedString(row["id_item"]->ToString())));

		return stock;
	}

	Stock ServiceStock::Add(Stock stock) {
		stock.SetId(this->dataContext.Insert("INSERT INTO [Stock] (amount, reorder_threshold, id_item) VALUES ('" + std::to_string(stock.GetAmount()) + "', '" + std::to_string(stock.GetReorderThreshold()) + "', '" + std::to_string(stock.GetIdItem()) + "')"));
		return stock;
	}

	void ServiceStock::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Stock] WHERE id_item = " + std::to_string(id));
	}

	void ServiceStock::Update(Stock stock) {
		this->dataContext.Query("UPDATE [Stock] SET amount = '" + std::to_string(stock.GetAmount()) + "', reorder_threshold = '" + std::to_string(stock.GetReorderThreshold()) + "' WHERE id_stock = '" + std::to_string(stock.GetIdItem()) + "'");
	}
}