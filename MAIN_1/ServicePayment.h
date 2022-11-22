#include <list>
#include "Payment.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServicePayment : AbstractService
	{
	public:
		list<Payment> GetAll();
		Payment Get(int id);
		Payment Add(Payment payment);
		void Remove(int id);
	};
}