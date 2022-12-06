#pragma once
#include <list>
#include "Customer.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceCustomer : AbstractService
	{
	public:
		std::list<Customer> GetAll();
		Customer Get(int id);
		Customer Add(Customer customer);
		void RemoveHas(int id);
		void Remove(int id);
		DataSet^ GetDataSet();
		DataSet^ GetSearchDataSet(std::string value);
		DataSet^ GetDataSetCustomer();
		void Update(Customer customer);
	};
}