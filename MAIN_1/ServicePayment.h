#pragma once
#include <list>
#include "Payment.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServicePayment : AbstractService
	{
	public:
		std::list<Payment> GetAll();
		Payment Get(int id);
		Payment Add(Payment payment);
		void Remove(int id);
	};
}