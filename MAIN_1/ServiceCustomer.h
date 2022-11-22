#include <list>
#include "Customer.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceCustomer : AbstractService
	{
	public:
		list<Customer> GetAll();
		Customer Get(int id);
		Customer Add(Customer customer);
		void Remove(int id);
	};
}