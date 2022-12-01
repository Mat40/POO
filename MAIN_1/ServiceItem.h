#pragma once
#include <list>
#include "Item.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceItem : AbstractService
	{
	public:
		std::list<Item> GetAll();
		DataSet^ GetDataSet();
		DataSet^ GetSearchDataSet(std::string value);
		Item Get(std::string ref);
		int GetMaxId();
		Item Add(Item item);
		void Remove(int id);
		void Update(Item item);
	};
}