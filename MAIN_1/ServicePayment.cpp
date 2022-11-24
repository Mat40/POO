#include "ServicePayment.h"

namespace BB8Manager_Core_Services {

	list<Payment> ServicePayment::GetAll()
	{
		list<Payment> paymentList;

		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Payment,
			"SELECT * FROM [Payment]");
		for each (DataRow ^ result in results)
		{
			Payment payment;
			payment.SetId(std::stoi(this->dataContext.ToUnmanagedString(result["id"]->ToString())));
			payment.SetDatePayment(this->dataContext.ToUnmanagedString(result["datepayment"]->ToString()));
			payment.SetMeanPayment(this->dataContext.ToUnmanagedString(result["meanpayment"]->ToString()));
			payment.SetAmountPayment(std::stof(this->dataContext.ToUnmanagedString(result["amountpayment"]->ToString())));
			payment.SetIdOrder(std::stoi(this->dataContext.ToUnmanagedString(result["id_order"]->ToString())));

			paymentList.push_back(payment);
		}

		return paymentList;
	}

	Payment ServicePayment::Get(int id) {
		DataRowCollection^ results = this->dataContext.Fetch(DataContext::Tables::Item, "SELECT * FROM [Payment] WHERE id = " + std::to_string(id));

		if (results->Count == 0)
			throw std::runtime_error("adress not found !");

		DataRow^ row = results[0];

		Payment payment;

		payment.SetId(std::stoi(this->dataContext.ToUnmanagedString(row["id"]->ToString())));
		payment.SetDatePayment(this->dataContext.ToUnmanagedString(row["datepayment"]->ToString()));
		payment.SetMeanPayment(this->dataContext.ToUnmanagedString(row["meanpayment"]->ToString()));
		payment.SetAmountPayment(std::stof(this->dataContext.ToUnmanagedString(row["amountpayment"]->ToString())));
		payment.SetIdOrder(std::stoi(this->dataContext.ToUnmanagedString(row["id_order"]->ToString())));

		return payment;
	}

	Payment ServicePayment::Add(Payment payment) {
		this->dataContext.Insert("INSERT INTO [Payment] (datepayment, meanpayment, amountpayment, datesettlement) VALUES ('" + payment.GetDatePayment() + "', '" + payment.GetMeanPayment() + "', '" + std::to_string(payment.GetAmountPayment()) + "', '" + std::to_string(payment.GetIdOrder()) + "')");
		return payment;
	}

	void ServicePayment::Remove(int id) {
		this->dataContext.Query("DELETE FROM [Payment] WHERE id = " + std::to_string(id));
	}
}