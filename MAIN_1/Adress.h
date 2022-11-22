#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Adress
	{
	private:
		int id;
		std::string postalcode;
		std::string city;
		std::string streetname;
		std::string streetnumber;
		std::string residencename;
		std::string buildingname;
		std::string floornumber;
	public:
		Adress();
		Adress(int id, std::string postalcode, std::string city, std::string streetname, std::string streetnumber, std::string residencename, std::string buildingname, std::string floornumber);

		void SetId(int id);
		void SetPostalcode(std::string postalcode);
		void SetCity(std::string city);
		void SetStreetname(std::string streetname);
		void SetStreetnumber(std::string streetnumber);
		void SetResidencename(std::string residencename);
		void SetBuildingname(std::string buildingname);
		void SetFloornumber(std::string floornumber);

		int GetId();
		std::string GetPostalcode();
		std::string GetCity();
		std::string GetStreetname();
		std::string GetStreetnumber();
		std::string GetResidencename();
		std::string GetBuildingname();
		std::string GetFloornumber();
	};
}