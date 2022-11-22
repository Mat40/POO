#pragma once
#include "DataContext.h"

using namespace BB8Manager_Core_Data;

namespace BB8Manager_Core_Services {
	ref class AbstractService
	{
	protected:
		DataContext dataContext;
	public:
		AbstractService();
	};
}