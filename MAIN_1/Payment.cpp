#include "Payment.h"
namespace BB8Manager_Core_Data_DAO {
	Payment::Payment()
	{
	}
	Payment::Payment(int id, std::string datepayment, std::string meanpayment, float amountpayment, int id_order)
	{
		this->id = id;
		this->datepayment = datepayment;
		this->meanpayment = meanpayment;
		this->amountpayment = amountpayment;
		this->id_order = id_order;
	}
	void Payment::SetId(int id)
	{
		this->id = id;
	}
	void Payment::SetDatePayment(std::string datepayment)
	{
		this->datepayment = datepayment;
	}
	void Payment::SetMeanPayment(std::string meanpayment)
	{
		this->meanpayment = meanpayment;
	}
	void Payment::SetAmountPayment(float amountpayment)
	{
		this->amountpayment = amountpayment;
	}
	void Payment::SetIdOrder(int id_order)
	{
		this->id_order = id_order;
	}
	int Payment::GetId()
	{
		return this->id;
	}
	std::string Payment::GetDatePayment()
	{
		return this->datepayment;
	}
	std::string Payment::GetMeanPayment()
	{
		return this->meanpayment;
	}
	float Payment::GetAmountPayment()
	{
		return this->amountpayment;
	}
	int Payment::GetIdOrder()
	{
		return this->id_order;
	}
}
