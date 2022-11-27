// compile with: /clr

#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <stdexcept>

#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>
#include <list>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::Common;
using namespace msclr::interop;

namespace BB8Manager_Core_Data {
	ref class DataContext
	{
	public:
		enum class Tables { Adress, Customer, Employee, DataSetEmployee, DataSetSuperior, Item, Order, Payment, Stock, WholesalePrice };

		DataContext();
		DataRowCollection^ Fetch(Tables tableName, std::string queryString);
		DataSet^ GetDataSet(Tables tableName, std::string queryString);
		int Insert(std::string queryString);
		void Query(std::string queryString);
		std::string ToUnmanagedString(String^ value);
	private:
		String^ connectionString =
			"Data Source=DESKTOP-S57J1OI\\MSSQL_MAT;" +
			"Initial Catalog = project_poo_db;" +
			"Persist Security Info = True;" +
			"User ID = sa;" +
			"Password = main_db33";
		SqlConnection^ connection;

		DataTableMapping^ Mapper(Tables tableName);
	};
}

/*
String^ connectionString =
	"Data Source=LAPTOP-HUGO\\MSQL_SERVER;" +
	"Initial Catalog = main_db;" +
	"Persist Security Info = True;" +
	"User ID = sa;" +
	"Password = main_db33";
*/

