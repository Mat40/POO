#include "Adress.h"

namespace BB8Manager_Core_Data_DAO {

	Adress::Adress() {}

	Adress::Adress(int id, std::string postalcode, std::string city, std::string streetname, std::string streetnumber, std::string residencename, std::string buildingname, std::string floornumber) {
		this->id = id;
		this->postalcode = postalcode;
		this->city = city;
		this->streetname = streetname;
		this->streetnumber = streetnumber;
		this->residencename = residencename;
		this->buildingname = buildingname;
		this->floornumber = floornumber;
	}

	void Adress::SetId(int id) {
		this->id = id;
	};
	void Adress::SetPostalcode(std::string postalcode) {
		this->postalcode = postalcode;
	};
	void Adress::SetCity(std::string city) {
		this->city = city;
	};
	void Adress::SetStreetname(std::string streetname) {
		this->streetname = streetname;
	};
	void Adress::SetStreetnumber(std::string streetnumber) {
		this->streetnumber = streetnumber;
	};
	void Adress::SetResidencename(std::string residencename) {
		this->residencename = residencename;
	};
	void Adress::SetBuildingname(std::string buildingname) {
		this->buildingname = buildingname;
	};
	void Adress::SetFloornumber(std::string floornumber) {
		this->floornumber = floornumber;
	};

	int Adress::GetId() {
		return this->id;
	};
	std::string Adress::GetPostalcode() {
		return this->postalcode;
	};
	std::string Adress::GetCity() {
		return this->city;
	};
	std::string Adress::GetStreetname() {
		return this->streetname;
	};
	std::string Adress::GetStreetnumber() {
		return this->streetnumber;
	};
	std::string Adress::GetResidencename() {
		return this->residencename;
	};
	std::string Adress::GetBuildingname() {
		return this->buildingname;
	};
	std::string Adress::GetFloornumber() {
		return this->floornumber;
	};
}