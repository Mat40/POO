#include <list>
#include "WholesalePrice.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceWholesalePrice : AbstractService
	{
	public:
		list<WholesalePrice> GetAll();
		WholesalePrice Get(int id);
		WholesalePrice Add(WholesalePrice stock);
		void Remove(int id);
	};
}