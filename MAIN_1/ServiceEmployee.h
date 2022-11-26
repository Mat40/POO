#include <list>
#include "Employee.h"
#include "AbstractService.h"

using namespace BB8Manager_Core_Data_DAO;
using namespace BB8Manager_Core_Services;

namespace BB8Manager_Core_Services {
	ref class ServiceEmployee : AbstractService
	{
	public:
		ServiceEmployee(void);
		std::list<Employee> GetAll();
		DataSet^ GetDataSet();
		DataSet^ GetDataSetSuperior();
		Employee Get(int id);
		Employee Add(Employee employee);
		void Remove(int id);
	};
}