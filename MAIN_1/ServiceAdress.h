#include <list>
#include "Adress.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceAdress : AbstractService
	{
	public:
		std::list<Adress> GetAll();
		Adress Get(int id);
		Adress Add(Adress adress);
		void Remove(int id);
	};
}