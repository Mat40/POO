//#include "pch.h"
#include "DataContext.h"

namespace BB8Manager_Core_Data {
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

	DataSet^ DataContext::GetDataSet(Tables tableName, std::string queryString)
	{
		String^ query = gcnew String(queryString.c_str());

		this->connection->Open();

		DataSet^ dataSet = gcnew DataSet();
		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(query, this->connection);
		DataTableMapping^ mapper = Mapper(tableName);
		dataAdapter->TableMappings->Add(mapper);
		dataAdapter->Fill(dataSet);

		if (tableName == DataContext::Tables::DataSetSuperior) {
			DataRow^ defaultRow = dataSet->Tables[0]->NewRow();
			defaultRow["ID"] = NULL;
			defaultRow["Name"] = "No Superior";
			dataSet->Tables[0]->Rows->InsertAt(defaultRow, 0);
		}

		this->connection->Close();

		return dataSet;
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

	int DataContext::QueryInt(std::string queryString) {
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
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 
	/// </summary>
	/// <param name="Query_return"></param>
	std::string DataContext::Query_return(std::string queryString){
	String^ query = gcnew String(queryString.c_str());
		SqlCommand^ command = gcnew SqlCommand(query, this->connection);
		command->CommandType = CommandType::Text;
		this->connection->Open();
		std::string return_var = marshal_as<std::string>(command->ExecuteScalar()->ToString());
		this->connection->Close();
		return return_var;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="tableName"></param>
	/// <returns></returns>
	DataTableMapping^ DataContext::Mapper(DataContext::Tables tableName) {
		switch (tableName)
		{
		case DataContext::Tables::Adress:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Adress");
			map->ColumnMappings->Add("id_adress", "id_adress");
			map->ColumnMappings->Add("postalcode", "postalcode");
			map->ColumnMappings->Add("city", "city");
			map->ColumnMappings->Add("streetname", "streetname");
			map->ColumnMappings->Add("streetnumber", "streetnumber");
			map->ColumnMappings->Add("residencename", "residencename");
			map->ColumnMappings->Add("buildingname", "buildingname");
			map->ColumnMappings->Add("floornumber", "floornumber");
			return map;
		}
		case DataContext::Tables::Customer:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Customer");
			map->ColumnMappings->Add("id_customer", "id");
			map->ColumnMappings->Add("firstname", "firstname");
			map->ColumnMappings->Add("lastname", "lastname");
			map->ColumnMappings->Add("birthdate", "birthdate");
			map->ColumnMappings->Add("id_deliveryadress", "id_deliveryadress");
			map->ColumnMappings->Add("id_billingadress", "id_billingadress");
			return map;
		}
		case DataContext::Tables::DataSetCustomer:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Customer");
			map->ColumnMappings->Add("id_customer", "ID");
			map->ColumnMappings->Add("customername", "Name");
			map->ColumnMappings->Add("birthdate", "Birth Date");
			map->ColumnMappings->Add("billingadress", "Billing Adress");
			map->ColumnMappings->Add("deliveryadress", "Delivery Adress");
			return map;
		}
		case DataContext::Tables::Employee:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Employee");
			map->ColumnMappings->Add("id_employee", "id_employee");
			map->ColumnMappings->Add("firstname", "firstname");
			map->ColumnMappings->Add("lastname", "lastname");
			map->ColumnMappings->Add("hiringdate", "hiringdate");
			map->ColumnMappings->Add("id_superior", "id_superior");
			map->ColumnMappings->Add("id_adress", "id_adress");
			return map;
		}
		case DataContext::Tables::DataSetEmployee:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Employee");
			map->ColumnMappings->Add("id_employee", "ID");
			map->ColumnMappings->Add("name", "Name");
			map->ColumnMappings->Add("hiringdate", "Hiring Date");
			map->ColumnMappings->Add("superior", "Superior");
			map->ColumnMappings->Add("adress", "Adress");
			return map;
		}
		case DataContext::Tables::DataSetSuperior:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Employee");
			map->ColumnMappings->Add("id_employee", "ID");
			map->ColumnMappings->Add("name", "Name");
			return map;
		}
		case DataContext::Tables::Item:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Item");
			map->ColumnMappings->Add("id_item", "id");
			map->ColumnMappings->Add("reference", "reference");
			map->ColumnMappings->Add("nameproduct", "nameproduct");/////////////////////////
			map->ColumnMappings->Add("amount", "amount");
			map->ColumnMappings->Add("price_excl_taxes", "price_excl_taxes");
			map->ColumnMappings->Add("vat", "vat");
			map->ColumnMappings->Add("reduction", "reduction");
			return map;
		}
		case DataContext::Tables::DataSetItem:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Item");
			map->ColumnMappings->Add("reference", "Reference");
			map->ColumnMappings->Add("name", "Name");
			map->ColumnMappings->Add("lot", "Lot");
			map->ColumnMappings->Add("price", "Price");
			map->ColumnMappings->Add("vat", "VAT (%)");
			map->ColumnMappings->Add("reduction", "Reduction (%)");
			map->ColumnMappings->Add("stock", "Stock");
			map->ColumnMappings->Add("reorder_threshold", "Reorder Threshold");
			return map;
		}
		case DataContext::Tables::Ordered:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Ordered");
			map->ColumnMappings->Add("id_order", "id");
			map->ColumnMappings->Add("reference", "reference");
			map->ColumnMappings->Add("datedelivery", "datedelivery");
			map->ColumnMappings->Add("dateinssuance", "dateinssuance");
			map->ColumnMappings->Add("datesettlement", "datesettlement");
			map->ColumnMappings->Add("settlementbalance", "settlementbalance");
			map->ColumnMappings->Add("id_customer", "id_customer");
			return map;
		}
		case DataContext::Tables::DataSetOrdered:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Ordered");
			map->ColumnMappings->Add("reference", "Reference");
			map->ColumnMappings->Add("name", "Customer");
			map->ColumnMappings->Add("datedelivery", "Delivery Date");
			map->ColumnMappings->Add("dateinssuance", "Inssuance Date");
			map->ColumnMappings->Add("datesettlement", "Settlement Date");
			map->ColumnMappings->Add("settlementbalance", "Balance");
			map->ColumnMappings->Add("fullprice", "Price");
			return map;
		}
		case DataContext::Tables::Payment:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Payment");
			map->ColumnMappings->Add("id_payment", "id");
			map->ColumnMappings->Add("datepayment", "datepayment");
			map->ColumnMappings->Add("meanpayment", "meanpayment");
			map->ColumnMappings->Add("amountpayment", "amountpayment");
			map->ColumnMappings->Add("id_order", "id_order");
			return map;
		}
		case DataContext::Tables::Stock:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "Stock");
			map->ColumnMappings->Add("id_stock", "id");
			map->ColumnMappings->Add("amount", "amount");
			map->ColumnMappings->Add("reorder_threshold", "reorder_threshold");
			map->ColumnMappings->Add("id_item", "id_item");
			return map;
		}
		case DataContext::Tables::WholesalePrice:
		{
			DataTableMapping^ map = gcnew DataTableMapping("Table", "WholesalePrice");
			map->ColumnMappings->Add("id_reduc", "id");
			map->ColumnMappings->Add("itemamount", "itemamount");
			map->ColumnMappings->Add("price_excl_taxes", "price_excl_taxes");
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