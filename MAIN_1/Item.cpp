#include "Item.h"

namespace BB8Manager_Core_Data_DAO {
	Item::Item()
	{
	}

	Item::Item(int id, std::string reference, std::string name, int amount, float price_excl_taxes, float vat, float reduction)
	{
		this->id = id;
		this->reference = reference;
		this->name = name;
		this->amount = amount;
		this->price_excl_taxes = price_excl_taxes;
		this->vat = vat;
		this->reduction = reduction;
	}

	void Item::SetId(int id)
	{
		this->id = id;
	}
	void Item::SetReference(std::string reference)
	{
		this->reference = reference;
	}
	void Item::SetName(std::string name)
	{
		this->name = name;
	}
	void Item::SetAmount(int amount)
	{
		this->amount = amount;
	}
	void Item::SetPriceExclTaxes(float price_excl_taxes)
	{
		this->price_excl_taxes = price_excl_taxes;
	}
	void Item::SetVat(float vat)
	{
		this->vat = vat;
	}
	void Item::SetReduction(float reduction)
	{
		this->reduction = reduction;
	}
	int Item::GetId()
	{
		return this->id;
	}
	std::string Item::GetReference()
	{
		return this->reference;
	}
	std::string Item::GetName()
	{
		return this->name;
	}
	int Item::GetAmount()
	{
		return this->amount;
	}
	float Item::GetPriceExclTaxes()
	{
		return this->price_excl_taxes;
	}
	float Item::GetVat()
	{
		return this->vat;
	}
	float Item::GetReduction()
	{
		return this->reduction;
	}
}