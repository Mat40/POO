#include "ServiceItem.h"

namespace BB8Manager_Core_Services {

	list<Item> ServiceItem::GetAll()
	{
		list<Item> itemList;

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

	Item ServiceItem::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Item, "SELECT * FROM [Item] WHERE id = " + std::to_string(id));

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

	Item ServiceItem::Add(Item item) {
		this->dataContext.Insert("INSERT INTO [Item] (reference, name, amount, price_excl_taxes, vat, reduction) VALUES ('" + item.GetReference() + "', '" + item.GetName() + "', '" + std::to_string(item.GetAmount()) + "', '" + std::to_string(item.GetPriceExclTaxes()) + "', '" + std::to_string(item.GetVat()) + "', '" + std::to_string(item.GetReduction()) + "')");
		return item;
	}

	void ServiceItem::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Item] WHERE id = " + std::to_string(id));
	}
}