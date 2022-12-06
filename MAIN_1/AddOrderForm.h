#pragma once
#include "AddStockForm.h"
#include "ServiceItem.h"
#include "ServiceOrder.h"
#include "ServiceAdress.h"
#include "ServiceCustomer.h"
#include <iostream>
#include <ctime>
#include <regex>
#include "ErrorForm.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de AddOrderForm
	/// </summary>
	public ref class AddOrderForm : public System::Windows::Forms::Form
	{

	public:
		ref class Listener abstract
		{
		public:
			virtual void onApplyClicked() = 0;
		};

		Listener^ listener;
		ErrorForm^ errorForm;

		AddOrderForm(Listener^ listener)
		{
			InitializeComponent();
			refresh_dataGridView();
			this->listener = listener;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddOrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelheader;
	protected:
	private: System::Windows::Forms::Button^ btnclose;

	private: bool dragging;
	private: Point offset;

	private: System::Windows::Forms::Label^ labelCustomer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btncancel;
	private: System::Windows::Forms::Button^ btnapply;
	private: System::Windows::Forms::Label^ labelitem;
	private: System::Windows::Forms::ComboBox^ comboBoxcustomer;
	private: Bunifu::UI::WinForms::BunifuDataGridView^ dataGridView;





	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddOrderForm::typeid));
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->labelCustomer = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->comboBoxcustomer = (gcnew System::Windows::Forms::ComboBox());
			this->labelitem = (gcnew System::Windows::Forms::Label());
			this->btncancel = (gcnew System::Windows::Forms::Button());
			this->btnapply = (gcnew System::Windows::Forms::Button());
			this->panelheader->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::DimGray;
			this->panelheader->Controls->Add(this->btnclose);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(0, 0);
			this->panelheader->Margin = System::Windows::Forms::Padding(4);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(800, 43);
			this->panelheader->TabIndex = 2;
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddOrderForm::AddOrderForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &AddOrderForm::AddOrderForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AddOrderForm::AddOrderForm_MouseUp);
			// 
			// btnclose
			// 
			this->btnclose->BackColor = System::Drawing::Color::DimGray;
			this->btnclose->FlatAppearance->BorderSize = 0;
			this->btnclose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnclose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnclose->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnclose->ForeColor = System::Drawing::Color::White;
			this->btnclose->Location = System::Drawing::Point(763, 0);
			this->btnclose->Margin = System::Windows::Forms::Padding(4);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(37, 34);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"X";
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &AddOrderForm::btnclose_Click);
			// 
			// labelCustomer
			// 
			this->labelCustomer->AutoSize = true;
			this->labelCustomer->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCustomer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->labelCustomer->Location = System::Drawing::Point(272, 12);
			this->labelCustomer->Name = L"labelCustomer";
			this->labelCustomer->Size = System::Drawing::Size(257, 49);
			this->labelCustomer->TabIndex = 11;
			this->labelCustomer->Text = L"CUSTOMER";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView);
			this->panel1->Controls->Add(this->comboBoxcustomer);
			this->panel1->Controls->Add(this->labelitem);
			this->panel1->Controls->Add(this->btncancel);
			this->panel1->Controls->Add(this->btnapply);
			this->panel1->Controls->Add(this->labelCustomer);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 43);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(800, 610);
			this->panel1->TabIndex = 12;
			// 
			// dataGridView
			// 
			this->dataGridView->AllowCustomTheming = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->dataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->CurrentTheme->AlternatingRowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->CurrentTheme->AlternatingRowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->dataGridView->CurrentTheme->AlternatingRowsStyle->ForeColor = System::Drawing::Color::Black;
			this->dataGridView->CurrentTheme->AlternatingRowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->CurrentTheme->AlternatingRowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView->CurrentTheme->BackColor = System::Drawing::Color::White;
			this->dataGridView->CurrentTheme->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->dataGridView->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->dataGridView->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->dataGridView->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->dataGridView->CurrentTheme->HeaderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView->CurrentTheme->Name = nullptr;
			this->dataGridView->CurrentTheme->RowsStyle->BackColor = System::Drawing::Color::White;
			this->dataGridView->CurrentTheme->RowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->dataGridView->CurrentTheme->RowsStyle->ForeColor = System::Drawing::Color::Black;
			this->dataGridView->CurrentTheme->RowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->CurrentTheme->RowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView->EnableHeadersVisualStyles = false;
			this->dataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->HeaderBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->dataGridView->HeaderBgColor = System::Drawing::Color::Empty;
			this->dataGridView->HeaderForeColor = System::Drawing::Color::White;
			this->dataGridView->Location = System::Drawing::Point(78, 237);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 51;
			this->dataGridView->RowTemplate->Height = 40;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(644, 278);
			this->dataGridView->TabIndex = 28;
			this->dataGridView->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// comboBoxcustomer
			// 
			this->comboBoxcustomer->FormattingEnabled = true;
			this->comboBoxcustomer->Location = System::Drawing::Point(300, 82);
			this->comboBoxcustomer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBoxcustomer->Name = L"comboBoxcustomer";
			this->comboBoxcustomer->Size = System::Drawing::Size(200, 24);
			this->comboBoxcustomer->TabIndex = 27;
			// 
			// labelitem
			// 
			this->labelitem->AutoSize = true;
			this->labelitem->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelitem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->labelitem->Location = System::Drawing::Point(323, 163);
			this->labelitem->Name = L"labelitem";
			this->labelitem->Size = System::Drawing::Size(154, 49);
			this->labelitem->TabIndex = 26;
			this->labelitem->Text = L"ITEMS";
			// 
			// btncancel
			// 
			this->btncancel->FlatAppearance->BorderSize = 0;
			this->btncancel->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btncancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncancel->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btncancel->ForeColor = System::Drawing::Color::DimGray;
			this->btncancel->Location = System::Drawing::Point(12, 560);
			this->btncancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btncancel->Name = L"btncancel";
			this->btncancel->Size = System::Drawing::Size(109, 39);
			this->btncancel->TabIndex = 18;
			this->btncancel->Text = L"CANCEL";
			this->btncancel->UseVisualStyleBackColor = true;
			this->btncancel->Click += gcnew System::EventHandler(this, &AddOrderForm::btncancel_Click);
			this->btncancel->MouseEnter += gcnew System::EventHandler(this, &AddOrderForm::btncancel_OnMouseEnter);
			this->btncancel->MouseLeave += gcnew System::EventHandler(this, &AddOrderForm::btncancel_OnMouseLeave);
			// 
			// btnapply
			// 
			this->btnapply->FlatAppearance->BorderSize = 0;
			this->btnapply->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnapply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnapply->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnapply->ForeColor = System::Drawing::Color::DimGray;
			this->btnapply->Location = System::Drawing::Point(679, 560);
			this->btnapply->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnapply->Name = L"btnapply";
			this->btnapply->Size = System::Drawing::Size(109, 39);
			this->btnapply->TabIndex = 17;
			this->btnapply->Text = L"APPLY";
			this->btnapply->UseVisualStyleBackColor = true;
			this->btnapply->Click += gcnew System::EventHandler(this, &AddOrderForm::btnapply_Click);
			this->btnapply->MouseEnter += gcnew System::EventHandler(this, &AddOrderForm::btnapply_OnMouseEnter);
			this->btnapply->MouseLeave += gcnew System::EventHandler(this, &AddOrderForm::btnapply_OnMouseLeave);
			// 
			// AddOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 653);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AddOrderForm";
			this->Text = L"AddOrderForm";
			this->Load += gcnew System::EventHandler(this, &AddOrderForm::comboBoxcustomer_Load);
			this->panelheader->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: System::Void refresh_dataGridView() {
		this->dataGridView->Refresh();
		this->dataGridView->DataSource = ServiceItem().GetItemDataSet();
		this->dataGridView->DataMember = "Item";
		this->dataGridView->Columns["Reference"]->ReadOnly = true;
		this->dataGridView->Columns["Name"]->ReadOnly = true;
	}


	private: System::Void btnclose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnapply_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btnapply->ForeColor = ColorTranslator::FromHtml("#fac755");
	}

	private: System::Void btnapply_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btnapply->ForeColor = System::Drawing::Color::DimGray;
	}

	private: System::Void btncancel_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btncancel->ForeColor = ColorTranslator::FromHtml("#fac755");
	}

	private: System::Void btncancel_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btncancel->ForeColor = System::Drawing::Color::DimGray;
	}

		   /// <summary>
		   /// Movable Window
		   /// </summary>

	private: System::Void AddOrderForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void AddOrderForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void AddOrderForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

		   /// <summary>
		   /// Form Load
		   /// </summary>

	private: System::Void AddOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void comboBoxcustomer_Load(System::Object^ sender, System::EventArgs^ e) {
		this->comboBoxcustomer->Refresh();
		this->comboBoxcustomer->DataSource = BB8Manager_Core_Services::ServiceCustomer().GetDataSetCustomer()->Tables[0];
		this->comboBoxcustomer->DisplayMember = "Name";
		this->comboBoxcustomer->ValueMember = "ID";
	}
	private: System::Void btncancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnapply_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Inssuance date (Current date)
		char date1[80];
		char date2[80];
		time_t t = time(0);
		strftime(date1, 80, "%Y-%m-%d", localtime(&t));

		// Delivery date (add 5 days to current date)
		tm* tmptr = NULL;
		tmptr = localtime(&t);
		tmptr->tm_mday += 5;
		time_t finaldate = mktime(tmptr);
		strftime(date2, 80, "%Y-%m-%d", localtime(&finaldate));

		std::string dateinssuance = date1;
		std::string datedelivery = date2;

		/////// USELESS AS FUCK
		//// Reformat customer name
		//std::string customername = marshal_as<std::string>(this->comboBoxcustomer->Text->ToString());
		//std::size_t pos = customername.find(" ");
		//std::string firstname = customername.substr(0, pos);
		//std::string lastname = customername.substr(pos, std::string::npos);

		Customer customer = ServiceCustomer().Get(std::stoi(marshal_as<std::string>(this->comboBoxcustomer->SelectedValue->ToString())));
		Adress adress = ServiceAdress().Get(customer.GetIdDeliveryAdress());

		std::string reference = customer.GetFirstname().substr(0, 2) + customer.GetLastname().substr(0, 2) + dateinssuance.substr(0,4) + adress.GetCity().substr(0,3);

		for (int i = 0; i < reference.length(); ++i)
		{
			reference[i] = ::toupper(reference[i]);
		}

		float totalorderprice = 0;

		for (int i = 0; i <= this->dataGridView->RowCount - 2; i++) {
			int itemamount = std::stoi(marshal_as<std::string>(this->dataGridView->Rows[i]->Cells[2]->Value->ToString()));
			if (itemamount > 0) {
				Item item = ServiceItem().Get(marshal_as<std::string>(this->dataGridView->Rows[i]->Cells[0]->Value->ToString()));
				float itemprice = item.GetPriceExclTaxes() * (1 + (item.GetVat() / 100));
				float totalprice = itemprice * itemamount;
				totalorderprice += totalprice;
			}
		}

		// Keep only two numbers after decimal point
		totalorderprice = std::ceil(totalorderprice * 100) / 100;

		if (totalorderprice > 0) {
			Order order;
			order.SetDateInssuance(dateinssuance);
			order.SetDateDelivery(datedelivery);
			order.SetReference(ServiceOrder().GetLastOrderRef(reference));
			order.SetIdCustomer(customer.GetId());
			order.SetFullprice(totalorderprice);
			order.SetSettlementBalance(totalorderprice);
			order.SetDateSettlement(dateinssuance);
			order = ServiceOrder().Add(order);

			for (int i = 0; i <= this->dataGridView->RowCount - 2; i++) {
				int itemamount = std::stoi(marshal_as<std::string>(this->dataGridView->Rows[i]->Cells[2]->Value->ToString()));
				if (itemamount > 0) {
					Item item = ServiceItem().Get(marshal_as<std::string>(this->dataGridView->Rows[i]->Cells[0]->Value->ToString()));
					ServiceOrder().AddHold(itemamount, order.GetId(), item.GetId());
				}
			}

			this->listener->onApplyClicked();

			this->Close();
		}
		else {
			this->errorForm = gcnew ErrorForm("You forgot to add items");
			this->errorForm->Show();
			return;
		}
	}
};
}
