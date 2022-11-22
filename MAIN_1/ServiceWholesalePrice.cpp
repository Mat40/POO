#include "ServiceWholesalePrice.h"

namespace BB8Manager_Core_Services {

	list<WholesalePrice> ServiceWholesalePrice::GetAll()
	{
		list<WholesalePrice> wholesalepriceList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::WholesalePrice,
			"SELECT * FROM [WholesalePrice]");
		for each (DataRow ^ result in results)
		{
			WholesalePrice wholesaleprice;
			wholesaleprice.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			wholesaleprice.SetItemAmount(std::stoi(this->dataContext.ToUnmanagedString(result["itemamount"]->ToString())));
			wholesaleprice.SetPriceExlcTaxes(std::stof(this->dataContext.ToUnmanagedString(result["price_excl_taxes"]->ToString())));
			
			wholesalepriceList.push_back(wholesaleprice);
		}

		return wholesalepriceList;
	}

	WholesalePrice ServiceWholesalePrice::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::WholesalePrice, "SELECT * FROM [WholesalePrice] WHERE id = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		WholesalePrice wholesaleprice;

		wholesaleprice.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		wholesaleprice.SetItemAmount(std::stoi(this->dataContext.ToUnmanagedString(row["itemamount"]->ToString())));
		wholesaleprice.SetPriceExlcTaxes(std::stof(this->dataContext.ToUnmanagedString(row["price_excl_taxes"]->ToString())));

		return wholesaleprice;
	}

	WholesalePrice ServiceWholesalePrice::Add(WholesalePrice wholesaleprice) {
		this->dataContext.Insert("INSERT INTO [WholesalePrice] (itemamount, price_excl_taxes) VALUES ('" + std::to_string(wholesaleprice.GetItemAmount()) + "', '" + std::to_string(wholesaleprice.GetPriceExlcTaxes()) + "')");
		return wholesaleprice;
	}

	void ServiceWholesalePrice::Remove(int id) {
		this->dataContext.Query("DELETE FROM [WholesalePrice] WHERE id = " + std::to_string(id));
	}
}