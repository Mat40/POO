#include "Stock.h"

namespace BB8Manager_Core_Data_DAO {
	Stock::Stock()
	{
	}
	Stock::Stock(int id, int amount, int reorderthreshold, int id_item)
	{
		this->id = id;
		this->amount = amount;
		this->reorderthreshold = reorderthreshold;
		this->id_item = id_item;
	}
	void Stock::SetId(int id)
	{
		this->id = id;
	}
	void Stock::SetAmount(int amount)
	{
		this->amount = amount;
	}
	void Stock::SetReorderThreshold(int reorderthreshold)
	{
		this->reorderthreshold = reorderthreshold;
	}
	void Stock::SetIdItem(int id_item)
	{
		this->id_item = id_item;
	}
	int Stock::GetId()
	{
		return this->id;
	}
	int Stock::GetAmount()
	{
		return this->amount;
	}
	int Stock::GetReorderThreshold()
	{
		return this->reorderthreshold;
	}
	int Stock::GetIdItem()
	{
		return this->id_item;
	}
}