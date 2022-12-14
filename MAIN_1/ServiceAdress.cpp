//#include "pch.h"
#pragma once
#include "ServiceAdress.h"

namespace BB8Manager_Core_Services {

	std::list<Adress> ServiceAdress::GetAll()
	{
		std::list<Adress> adressList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Adress,
			"SELECT * FROM [Adress]");
		for each (DataRow ^ result in results)
		{
			Adress adress;
			adress.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id_adress"]->ToString())));
			adress.SetPostalcode(this->dataContext.ToUnmanagedString(result["postalcode"]->ToString()));
			adress.SetCity(this->dataContext.ToUnmanagedString(result["city"]->ToString()));
			adress.SetStreetname(this->dataContext.ToUnmanagedString(result["streetname"]->ToString()));
			adress.SetStreetnumber(this->dataContext.ToUnmanagedString(result["streetnumber"]->ToString()));
			adress.SetResidencename(this->dataContext.ToUnmanagedString(result["residencename"]->ToString()));
			adress.SetBuildingname(this->dataContext.ToUnmanagedString(result["buildingname"]->ToString()));
			adress.SetFloornumber(this->dataContext.ToUnmanagedString(result["floornumber"]->ToString()));

			adressList.push_back(adress);
		}

		return adressList;
	}

	Adress ServiceAdress::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Adress, "SELECT * FROM [Adress] WHERE id_adress = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Adress adress;

		adress.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id_adress"]->ToString())));
		adress.SetPostalcode(this->dataContext.ToUnmanagedString(row["postalcode"]->ToString()));
		adress.SetCity(this->dataContext.ToUnmanagedString(row["city"]->ToString()));
		adress.SetStreetname(this->dataContext.ToUnmanagedString(row["streetname"]->ToString()));
		adress.SetStreetnumber(this->dataContext.ToUnmanagedString(row["streetnumber"]->ToString()));
		adress.SetResidencename(this->dataContext.ToUnmanagedString(row["residencename"]->ToString()));
		adress.SetBuildingname(this->dataContext.ToUnmanagedString(row["buildingname"]->ToString()));
		adress.SetFloornumber(this->dataContext.ToUnmanagedString(row["floornumber"]->ToString()));

		return adress;
	}

	Adress ServiceAdress::Add(Adress adress) {
		adress.SetId(this->dataContext.Insert("INSERT INTO [Adress] (postalcode, city, streetname, streetnumber, residencename, buildingname, floornumber) VALUES ('" + adress.GetPostalcode() + "', '" + adress.GetCity() + "', '" + adress.GetStreetname() + "', '" + adress.GetStreetnumber() + "', '" + adress.GetResidencename() + "', '" + adress.GetBuildingname() + "', '" + adress.GetFloornumber() + "')"));
		return adress;
	}

	void ServiceAdress::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Adress] WHERE id_adress = " + std::to_string(id));
	}

	void ServiceAdress::Update(Adress adress) {
		this->dataContext.Query("UPDATE [Adress] SET postalcode = '" + adress.GetPostalcode() + "', city = '" + adress.GetCity() + "', streetname = '" + adress.GetStreetname() + "', streetnumber = '" + adress.GetStreetnumber() + "', residencename = '" + adress.GetResidencename() + "', buildingname = '" + adress.GetBuildingname() + "', floornumber = '" + adress.GetFloornumber() + "' WHERE id_adress = '" + std::to_string(adress.GetId()) + "'");
	}
}