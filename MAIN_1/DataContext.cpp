//#include "pch.h"
#include "DataContext.h"

namespace AppUserManager_Core_Data {
	/// <summary>
	/// 
	/// </summary>
	DataContext::DataContext() {
		this->connection = gcnew SqlConnection();
		this->connection->ConnectionString = this->connectionString;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="tableName"></param>
	/// <param name="queryString"></param>
	/// <returns></returns>
	DataRowCollection^ DataContext::Fetch(Tables tableName, std::string queryString) {
		String^ query = gcnew String(queryString.c_str());

		this->connection->Open();

		DataSet^ dataSet = gcnew DataSet();
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(query, this->connection);
		DataTableMapping^ mapper = Mapper(tableName);
		dataAdapter->TableMappings->Add(mapper);
		dataAdapter->Fill(dataSet);

		this->connection->Close();

		return dataSet->Tables[0]->Rows;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="queryString"></param>
	/// <returns></returns>
	int DataContext::Insert(std::string queryString) {
		queryString += " SELECT SCOPE_IDENTITY()";
		String^ query = gcnew String(queryString.c_str());
		SqlCommand^ command = gcnew SqlCommand(query, this->connection);
		command->CommandType = CommandType::Text;

		this->connection->Open();
		Object^ result = command->ExecuteScalar();
		this->connection->Close();

		return std::stoi(this->ToUnmanagedString(result->ToString()));
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="queryString"></param>
	void DataContext::Query(std::string queryString) {
		String^ query = gcnew String(queryString.c_str());
		SqlCommand^ command = gcnew SqlCommand(query, this->connection);
		command->CommandType = CommandType::Text;

		this->connection->Open();
		command->ExecuteNonQuery();
		this->connection->Close();
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="tableName"></param>
	/// <returns></returns>
	DataTableMapping^ DataContext::Mapper(DataContext::Tables tableName) {
		switch (tableName)
		{
		case DataContext::Tables::Users:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Employee");
			map->ColumnMappings->Add("id", "id");
			map->ColumnMappings->Add("firstname", "firstname");
			map->ColumnMappings->Add("lastname", "lastname");
			return map;
		}
		default:
			throw "table not found";
		}
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	std::string DataContext::ToUnmanagedString(String^ value) {
		return marshal_as<std::string>(value);
	}
}