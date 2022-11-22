#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class WholesalePrice
	{
	private:
		int id;
		int itemamount;
		float price_excl_taxes;

	public:
		WholesalePrice();
		WholesalePrice(int id, int itemamount, float price_excl_taxes);

		void SetId(int id);
		void SetItemAmount(int itemamount);
		void SetPriceExlcTaxes(float price_excl_taxes);

		int GetId();
		int GetItemAmount();
		float GetPriceExlcTaxes();
	};
}