#include <list>
#include "Order.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceOrder : AbstractService
	{
	public:
		list<Order> GetAll();
		Order Get(int id);
		Order Add(Order order);
		void Remove(int id);
	};
}