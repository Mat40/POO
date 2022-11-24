#include <list>
#include "Stock.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceStock : AbstractService
	{
	public:
		list<Stock> GetAll();
		Stock Get(int id);
		Stock Add(Stock stock);
		void Remove(int id);
	};
}