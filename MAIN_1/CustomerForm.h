#pragma once
#include "AddCustomerForm.h"
#include "UpdateCustomerForm.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Customer
	/// </summary>
	public ref class CustomerForm : public System::Windows::Forms::Form
	{

	public:

		AddCustomerForm^ addCustomerForm;
		UpdateCustomerForm^ updateCustomerForm;

		CustomerForm(void)
		{
			InitializeComponent();
			refresh_dataGridView();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~CustomerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		ref class AddCustomerListenerImpl : public AddCustomerForm::Listener
		{
		public:
			AddCustomerListenerImpl(CustomerForm^ parent) : m_parent(parent) {}

			void onApplyClicked() override
			{
				m_parent->refresh_dataGridView();
			}
		private:
			CustomerForm^ m_parent;
		};

		ref class UpdateCustomerListenerImpl : public UpdateCustomerForm::Listener
		{
		public:
			UpdateCustomerListenerImpl(CustomerForm^ parent) : m_parent(parent) {}

			void onApplyClicked() override
			{
				m_parent->refresh_dataGridView();
			}
		private:
			CustomerForm^ m_parent;
		};
		/*public:
			CustomerForm(void)
			{
				InitializeComponent();
				refresh_dataGridView();
			}*/


	private: System::Windows::Forms::FlowLayoutPanel^ customerLayoutPanel;
	private: System::Windows::Forms::Panel^ panelDataGridView;
	private: Bunifu::UI::WinForms::BunifuDataGridView^ dataGridView;

	private: System::Windows::Forms::Button^ btnupdate;
	private: System::Windows::Forms::Button^ btnadd;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ btndelete;
	private: System::Windows::Forms::Button^ btnsearch;
	private: System::Windows::Forms::TextBox^ textBoxsearch;

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomerForm::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->customerLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btnsearch = (gcnew System::Windows::Forms::Button());
			this->textBoxsearch = (gcnew System::Windows::Forms::TextBox());
			this->btndelete = (gcnew System::Windows::Forms::Button());
			this->btnadd = (gcnew System::Windows::Forms::Button());
			this->btnupdate = (gcnew System::Windows::Forms::Button());
			this->panelDataGridView = (gcnew System::Windows::Forms::Panel());
			this->dataGridView = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->customerLayoutPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panelDataGridView->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// customerLayoutPanel
			// 
			this->customerLayoutPanel->Controls->Add(this->panel2);
			this->customerLayoutPanel->Controls->Add(this->panelDataGridView);
			this->customerLayoutPanel->Location = System::Drawing::Point(12, 12);
			this->customerLayoutPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->customerLayoutPanel->Name = L"customerLayoutPanel";
			this->customerLayoutPanel->Size = System::Drawing::Size(1203, 662);
			this->customerLayoutPanel->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->btnsearch);
			this->panel2->Controls->Add(this->textBoxsearch);
			this->panel2->Controls->Add(this->btndelete);
			this->panel2->Controls->Add(this->btnadd);
			this->panel2->Controls->Add(this->btnupdate);
			this->panel2->Location = System::Drawing::Point(3, 2);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1197, 55);
			this->panel2->TabIndex = 0;
			// 
			// btnsearch
			// 
			this->btnsearch->FlatAppearance->BorderSize = 0;
			this->btnsearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnsearch->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F));
			this->btnsearch->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnsearch.Image")));
			this->btnsearch->Location = System::Drawing::Point(367, 6);
			this->btnsearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnsearch->Name = L"btnsearch";
			this->btnsearch->Size = System::Drawing::Size(47, 43);
			this->btnsearch->TabIndex = 4;
			this->btnsearch->UseVisualStyleBackColor = true;
			this->btnsearch->Click += gcnew System::EventHandler(this, &CustomerForm::btnsearch_Click);
			// 
			// textBoxsearch
			// 
			this->textBoxsearch->Location = System::Drawing::Point(16, 16);
			this->textBoxsearch->Margin = System::Windows::Forms::Padding(4);
			this->textBoxsearch->Name = L"textBoxsearch";
			this->textBoxsearch->Size = System::Drawing::Size(343, 22);
			this->textBoxsearch->TabIndex = 3;
			this->textBoxsearch->TextChanged += gcnew System::EventHandler(this, &CustomerForm::textBoxsearch_TextChanged);
			this->textBoxsearch->Enter += gcnew System::EventHandler(this, &CustomerForm::textBoxsearch_Enter);
			this->textBoxsearch->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CustomerForm::textBoxsearch_KeyDown);
			// 
			// btndelete
			// 
			this->btndelete->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->btndelete->FlatAppearance->BorderSize = 0;
			this->btndelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btndelete->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F));
			this->btndelete->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btndelete.Image")));
			this->btndelete->Location = System::Drawing::Point(1120, 6);
			this->btndelete->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btndelete->Name = L"btndelete";
			this->btndelete->Size = System::Drawing::Size(47, 43);
			this->btndelete->TabIndex = 2;
			this->btndelete->UseVisualStyleBackColor = true;
			this->btndelete->Click += gcnew System::EventHandler(this, &CustomerForm::btndelete_Click);
			// 
			// btnadd
			// 
			this->btnadd->FlatAppearance->BorderSize = 0;
			this->btnadd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnadd->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F));
			this->btnadd->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnadd.Image")));
			this->btnadd->Location = System::Drawing::Point(1016, 6);
			this->btnadd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnadd->Name = L"btnadd";
			this->btnadd->Size = System::Drawing::Size(47, 43);
			this->btnadd->TabIndex = 1;
			this->btnadd->UseVisualStyleBackColor = true;
			this->btnadd->Click += gcnew System::EventHandler(this, &CustomerForm::button1_Click);
			// 
			// btnupdate
			// 
			this->btnupdate->FlatAppearance->BorderSize = 0;
			this->btnupdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnupdate->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F));
			this->btnupdate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnupdate.Image")));
			this->btnupdate->Location = System::Drawing::Point(1068, 6);
			this->btnupdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnupdate->Name = L"btnupdate";
			this->btnupdate->Size = System::Drawing::Size(47, 43);
			this->btnupdate->TabIndex = 0;
			this->btnupdate->UseVisualStyleBackColor = true;
			this->btnupdate->Click += gcnew System::EventHandler(this, &CustomerForm::btnupdate_Click);
			// 
			// panelDataGridView
			// 
			this->panelDataGridView->Controls->Add(this->dataGridView);
			this->panelDataGridView->Location = System::Drawing::Point(3, 61);
			this->panelDataGridView->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelDataGridView->Name = L"panelDataGridView";
			this->panelDataGridView->Size = System::Drawing::Size(1200, 597);
			this->panelDataGridView->TabIndex = 0;
			// 
			// dataGridView
			// 
			this->dataGridView->AllowCustomTheming = true;
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle16->ForeColor = System::Drawing::Color::Black;
			this->dataGridView->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle16;
			this->dataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle17->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle17->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
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
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle18->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle18->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle18->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle18;
			this->dataGridView->EnableHeadersVisualStyles = false;
			this->dataGridView->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView->HeaderBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->dataGridView->HeaderBgColor = System::Drawing::Color::Empty;
			this->dataGridView->HeaderForeColor = System::Drawing::Color::White;
			this->dataGridView->Location = System::Drawing::Point(3, 2);
			this->dataGridView->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView->MultiSelect = false;
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->ReadOnly = true;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidth = 51;
			this->dataGridView->RowTemplate->Height = 40;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView->Size = System::Drawing::Size(1195, 592);
			this->dataGridView->TabIndex = 1;
			this->dataGridView->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// CustomerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1227, 686);
			this->Controls->Add(this->customerLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"CustomerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Customer";
			this->customerLayoutPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panelDataGridView->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void refresh_dataGridView() {
		this->dataGridView->Refresh();
		this->dataGridView->DataSource = ServiceCustomer().GetDataSet();
		this->dataGridView->DataMember = "Customer";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->addCustomerForm = gcnew AddCustomerForm(gcnew AddCustomerListenerImpl(this));
		this->addCustomerForm->Show();
	}
	public: System::Void Form1_FormClosed(System::Object^ sender, System::EventArgs^ e)
	{
		refresh_dataGridView();
	}

	private: System::Void btndelete_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView->SelectedRows->Count > 0)
		{
			int selectedrowindex = this->dataGridView->SelectedCells[0]->RowIndex;
			DataGridViewRow^ selectedRow = this->dataGridView->Rows[selectedrowindex];
			int cellValue = std::stoi(marshal_as<std::string>(selectedRow->Cells["ID"]->Value->ToString()));
			Customer customer;
			customer = ServiceCustomer().Get(cellValue);
			ServiceCustomer().Remove(cellValue);
			ServiceAdress().Remove(customer.GetIdBillingAdress());
			ServiceAdress().Remove(customer.GetIdDeliveryAdress());
			refresh_dataGridView();
		}
	}
	private: System::Void btnupdate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView->SelectedRows->Count > 0)
		{
			int selectedrowindex = this->dataGridView->SelectedCells[0]->RowIndex;
			DataGridViewRow^ selectedRow = this->dataGridView->Rows[selectedrowindex];
			int IDcellValue = std::stoi(marshal_as<std::string>(selectedRow->Cells["ID"]->Value->ToString()));

			Customer customer;
			customer = ServiceCustomer().Get(IDcellValue);

			Adress delivery;
			delivery = ServiceAdress().Get(customer.GetIdDeliveryAdress());

			Adress billing;
			billing = ServiceAdress().Get(customer.GetIdBillingAdress());

			this->updateCustomerForm = gcnew UpdateCustomerForm(gcnew UpdateCustomerListenerImpl(this), customer, delivery, billing);
			this->updateCustomerForm->Show();
		}
	}
	private: System::Void btnsearch_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBoxsearch->Text->ToString() != "") {
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = BB8Manager_Core_Services::ServiceCustomer().GetSearchDataSet(marshal_as<std::string>(this->textBoxsearch->Text->ToString()));
			this->dataGridView->DataMember = "Customer";
		}
		else {
			refresh_dataGridView();
		}

	}
	private: System::Void textBoxsearch_Enter(System::Object^ sender, System::EventArgs^ e) {
		this->textBoxsearch->Text = "";
	}
	private: System::Void textBoxsearch_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter)
		{
			btnsearch_Click(this, gcnew EventArgs());
		}
	}
	private: System::Void textBoxsearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBoxsearch->Text->ToString() != "") {
			this->dataGridView->Refresh();
			this->dataGridView->DataSource = ServiceCustomer().GetSearchDataSet(marshal_as<std::string>(this->textBoxsearch->Text->ToString()));
			this->dataGridView->DataMember = "Customer";
		}
		else {
			refresh_dataGridView();
		}
	}
	};
}