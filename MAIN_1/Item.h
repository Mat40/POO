#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Item
	{
	private:
		int id;
		std::string reference;
		std::string name;
		int amount;
		float price_excl_taxes;
		float vat;
		float reduction;
	
	public:
		Item();
		Item(int id, std::string reference, std::string name, int amount, float price_excl_taxes, float vat, float reduction);

		void SetId(int id);
		void SetReference(std::string reference);
		void SetName(std::string name);
		void SetAmount(int amount);
		void SetPriceExclTaxes(float price_excl_taxes);
		void SetVat(float vat);
		void SetReduction(float reduction);

		int GetId();
		std::string GetReference();
		std::string GetName();
		int GetAmount();
		float GetPriceExclTaxes();
		float GetVat();
		float GetReduction();
	};
}