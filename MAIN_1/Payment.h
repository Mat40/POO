#pragma once
#include <string>

namespace BB8Manager_Core_Data_DAO {
	public class Payment
	{
	private:
		int id;
		std::string datepayment;
		std::string meanpayment;
		float amountpayment;
		int id_order;
	public:
		Payment();
		Payment(int id, std::string datepayment, std::string meanpayment, float amountpayment, int id_order);

		void SetId(int id);
		void SetDatePayment(std::string datepayment);
		void SetMeanPayment(std::string meanpayment);
		void SetAmountPayment(float amountpayment);
		void SetIdOrder(int id_order);

		int GetId();
		std::string GetDatePayment();
		std::string GetMeanPayment();
		float GetAmountPayment();
		int GetIdOrder();
	};
}