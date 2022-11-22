#include "WholesalePrice.h"

namespace BB8Manager_Core_Data_DAO {
	WholesalePrice::WholesalePrice()
	{
	}
	WholesalePrice::WholesalePrice(int id, int itemamount, float price_excl_taxes)
	{
		this->id = id;
		this->itemamount = itemamount;
		this->price_excl_taxes = price_excl_taxes;
	}
	void WholesalePrice::SetId(int id)
	{
		this->id = id;
	}
	void WholesalePrice::SetItemAmount(int itemamount)
	{
		this->itemamount = itemamount;
	}
	void WholesalePrice::SetPriceExlcTaxes(float price_excl_taxes)
	{
		this->price_excl_taxes = price_excl_taxes;
	}
	int WholesalePrice::GetId()
	{
		return this->id;
	}
	int WholesalePrice::GetItemAmount()
	{
		return this->itemamount;
	}
	float WholesalePrice::GetPriceExlcTaxes()
	{
		return this->price_excl_taxes;
	}
}