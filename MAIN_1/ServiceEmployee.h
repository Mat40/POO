#include <list>
#include "Employee.h"
#include "AbstractService.h"

using namespace std;
using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceEmployee : AbstractService
	{
	public:
		list<Employee> GetAll();
		Employee Get(int id);
		Employee Add(Employee employee);
		void Remove(int id);
	};
}