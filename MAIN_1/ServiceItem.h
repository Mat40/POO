#include <list>
#include "Item.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceItem : AbstractService
	{
	public:
		list<Item> GetAll();
		Item Get(int id);
		Item Add(Item item);
		void Remove(int id);
	};
}