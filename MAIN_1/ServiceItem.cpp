#pragma once
#include "ServiceItem.h"

namespace BB8Manager_Core_Services {

	std::list<Item> ServiceItem::GetAll()
	{
		std::list<Item> itemList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Item,
			"SELECT * FROM [Item]");
		for each (DataRow ^ result in results)
		{
			Item item;
			item.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			item.SetReference(this->dataContext.ToUnmanagedString(result["reference"]->ToString()));
			item.SetName(this->dataContext.ToUnmanagedString(result["name"]->ToString()));
			item.SetAmount(std::stoi(this->dataContext.ToUnmanagedString(result["amount"]->ToString())));
			item.SetPriceExclTaxes(std::stof(this->dataContext.ToUnmanagedString(result["price_excl_taxes"]->ToString())));
			item.SetVat(std::stof(this->dataContext.ToUnmanagedString(result["vat"]->ToString())));
			item.SetReduction(std::stof(this->dataContext.ToUnmanagedString(result["reduction"]->ToString())));

			itemList.push_back(item);
		}

		return itemList;
	}

	Item ServiceItem::Get(std::string ref) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Item, "SELECT * FROM [Item] WHERE reference = '" + ref + "'; ");

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Item item;

		item.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		item.SetReference(this->dataContext.ToUnmanagedString(row["reference"]->ToString()));
		item.SetName(this->dataContext.ToUnmanagedString(row["name"]->ToString()));
		item.SetAmount(std::stoi(this->dataContext.ToUnmanagedString(row["amount"]->ToString())));
		item.SetPriceExclTaxes(std::stof(this->dataContext.ToUnmanagedString(row["price_excl_taxes"]->ToString())));
		item.SetVat(std::stof(this->dataContext.ToUnmanagedString(row["vat"]->ToString())));
		item.SetReduction(std::stof(this->dataContext.ToUnmanagedString(row["reduction"]->ToString())));

		return item;
	}

	int ServiceItem::GetMaxId()
	{
		int result = this->dataContext.QueryInt("SELECT CASE WHEN(SELECT COUNT(1) FROM [Item]) = 0 THEN 1 ELSE IDENT_CURRENT('Item') + 1 END AS Current_Identity; ");

		if (result == NULL)
			throw std::runtime_error("id not found !");
		return result;
	}

	DataSet^ ServiceItem::GetDataSet()
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetItem, "SELECT reference, name, Item.amount as lot, price_excl_taxes as price, vat, reduction, Stock.amount as stock, reorder_threshold FROM [Item] INNER JOIN [Stock] ON Item.id_item = Stock.id_item; ");
		return result;
	}

	DataSet^ ServiceItem::GetSearchDataSet(std::string value)
	{
		DataSet^ result = this->dataContext.GetDataSet(DataContext::Tables::DataSetItem, "SELECT reference, name, Item.amount as lot, price_excl_taxes as price, vat, reduction, Stock.amount as stock, reorder_threshold FROM [Item] INNER JOIN [Stock] ON Item.id_item = Stock.id_item WHERE Item.reference LIKE '%" + value + "%' OR Item.name LIKE '%" + value + "%';");
		return result;
	}

	Item ServiceItem::Add(Item item) {
		item.SetId(this->dataContext.Insert("INSERT INTO [Item] (reference, name, amount, price_excl_taxes, vat, reduction) VALUES ('" + item.GetReference() + "', '" + item.GetName() + "', '" + std::to_string(item.GetAmount()) + "', '" + std::to_string(item.GetPriceExclTaxes()) + "', '" + std::to_string(item.GetVat()) + "', '" + std::to_string(item.GetReduction()) + "')"));
		return item;
	}

	void ServiceItem::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Item] WHERE id_item = " + std::to_string(id));
	}

	void ServiceItem::Update(Item item) {
		this->dataContext.Query("UPDATE [Item] SET name = '" + item.GetName() + "', amount = '" + std::to_string(item.GetAmount()) + "', price_excl_taxes = '" + std::to_string(item.GetPriceExclTaxes()) + "', vat = '" + std::to_string(item.GetVat()) + "', reduction = '" + std::to_string(item.GetReduction()) + "' WHERE id_item = '" + std::to_string(item.GetId()) + "'");
	}
}