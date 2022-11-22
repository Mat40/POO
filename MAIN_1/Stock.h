#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Stock
	{
	private:
		int id;
		int amount;
		int reorderthreshold;
		int id_item;

	public:
		Stock();
		Stock(int id, int amount, int reorderthreshold, int id_item);

		void SetId(int id);
		void SetAmount(int amount);
		void SetReorderThreshold(int reorderthreshold);
		void SetIdItem(int id_item);

		int GetId();
		int GetAmount();
		int GetReorderThreshold();
		int GetIdItem();
	};
}