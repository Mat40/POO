#pragma once
#include "ServiceEmployee.h"
#include "ServiceAdress.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de UpdateEmployeeForm
	/// </summary>
	public ref class UpdateEmployeeForm : public System::Windows::Forms::Form
	{

	public:
		ref class Listener abstract
		{
		public:
			virtual void onApplyClicked() = 0;
		};

		Listener^ listener;
		int employeeID;
		int adressID;

		UpdateEmployeeForm(Listener^ listener, Employee employee, Adress adress)
		{
			InitializeComponent();
			this->listener = listener;
			adressID = adress.GetId();
			this->textboxpostalcode->Text = gcnew String(adress.GetPostalcode().c_str());
			this->textboxcity->Text = gcnew String(adress.GetCity().c_str());
			this->textBoxstreetname->Text = gcnew String(adress.GetStreetname().c_str());
			this->textBoxstreetnumber->Text = gcnew String(adress.GetStreetnumber().c_str());
			this->textBoxresidence->Text = gcnew String(adress.GetResidencename().c_str());
			this->textBoxbuilding->Text = gcnew String(adress.GetBuildingname().c_str());
			this->textBoxfloor->Text = gcnew String(adress.GetFloornumber().c_str());

			employeeID = employee.GetId();
			this->textBoxfirstname->Text = gcnew String(employee.GetFirstname().c_str());
			this->textBoxlastname->Text = gcnew String(employee.GetLastname().c_str());

			std::string day = employee.GetHiringdate().substr(0, 2);
			std::string month = employee.GetHiringdate().substr(3, 2);
			std::string year = employee.GetHiringdate().substr(6, 4);

			this->dateTimePickerhiringdate->Value = System::DateTime(std::stoi(year), std::stoi(month), std::stoi(day), 0, 0, 0, 0);

			this->comboBoxsuperior->Refresh();
			this->comboBoxsuperior->DataSource = ServiceEmployee().GetDataSetSuperior()->Tables[0];
			this->comboBoxsuperior->DisplayMember = "Name";
			this->comboBoxsuperior->ValueMember = "ID";

			this->comboBoxsuperior->SelectedValue = employee.GetIdSuperior();
		}
		/*public:

			UpdateEmployeeForm(void)
			{
				InitializeComponent();
			}*/

			/*MAIN1::EmployeeForm^ frm;

			UpdateEmployeeForm(MAIN1::EmployeeForm^ frm)
			{
				InitializeComponent();
				this->frm = frm;
			}*/

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~UpdateEmployeeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelheader;
	protected:
	private: System::Windows::Forms::Button^ btnclose;
	private: System::Windows::Forms::TextBox^ textboxpostalcode;

	private: System::Windows::Forms::TextBox^ textboxcity;
	private: System::Windows::Forms::TextBox^ textBoxstreetname;
	private: System::Windows::Forms::TextBox^ textBoxresidence;
	private: System::Windows::Forms::TextBox^ textBoxbuilding;

	private: bool dragging;
	private: Point offset;


	private: System::Windows::Forms::TextBox^ textBoxstreetnumber;
	private: System::Windows::Forms::TextBox^ textBoxfloor;


	private: System::Windows::Forms::Label^ labelAdress;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBoxsuperior;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerhiringdate;


	private: System::Windows::Forms::TextBox^ textBoxlastname;

	private: System::Windows::Forms::TextBox^ textBoxfirstname;


	private: System::Windows::Forms::Button^ btncancel;
	private: System::Windows::Forms::Button^ btnapply;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateEmployeeForm::typeid));
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->textboxpostalcode = (gcnew System::Windows::Forms::TextBox());
			this->textboxcity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxstreetname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxresidence = (gcnew System::Windows::Forms::TextBox());
			this->textBoxbuilding = (gcnew System::Windows::Forms::TextBox());
			this->textBoxstreetnumber = (gcnew System::Windows::Forms::TextBox());
			this->textBoxfloor = (gcnew System::Windows::Forms::TextBox());
			this->labelAdress = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btncancel = (gcnew System::Windows::Forms::Button());
			this->btnapply = (gcnew System::Windows::Forms::Button());
			this->comboBoxsuperior = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePickerhiringdate = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxlastname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxfirstname = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelheader->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::DimGray;
			this->panelheader->Controls->Add(this->btnclose);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(0, 0);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(600, 28);
			this->panelheader->TabIndex = 2;
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateEmployeeForm::UpdateEmployeeForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateEmployeeForm::UpdateEmployeeForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateEmployeeForm::UpdateEmployeeForm_MouseUp);
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
			this->btnclose->Location = System::Drawing::Point(572, 0);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(28, 28);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"X";
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &UpdateEmployeeForm::btnclose_Click);
			// 
			// textboxpostalcode
			// 
			this->textboxpostalcode->Location = System::Drawing::Point(52, 60);
			this->textboxpostalcode->Margin = System::Windows::Forms::Padding(2);
			this->textboxpostalcode->Name = L"textboxpostalcode";
			this->textboxpostalcode->Size = System::Drawing::Size(151, 20);
			this->textboxpostalcode->TabIndex = 4;
			this->textboxpostalcode->Text = L"Postal Code";
			// 
			// textboxcity
			// 
			this->textboxcity->Location = System::Drawing::Point(225, 60);
			this->textboxcity->Margin = System::Windows::Forms::Padding(2);
			this->textboxcity->Name = L"textboxcity";
			this->textboxcity->Size = System::Drawing::Size(151, 20);
			this->textboxcity->TabIndex = 5;
			this->textboxcity->Text = L"City";
			// 
			// textBoxstreetname
			// 
			this->textBoxstreetname->Location = System::Drawing::Point(404, 60);
			this->textBoxstreetname->Margin = System::Windows::Forms::Padding(2);
			this->textBoxstreetname->Name = L"textBoxstreetname";
			this->textBoxstreetname->Size = System::Drawing::Size(151, 20);
			this->textBoxstreetname->TabIndex = 6;
			this->textBoxstreetname->Text = L"Street Name";
			// 
			// textBoxresidence
			// 
			this->textBoxresidence->Location = System::Drawing::Point(225, 100);
			this->textBoxresidence->Margin = System::Windows::Forms::Padding(2);
			this->textBoxresidence->Name = L"textBoxresidence";
			this->textBoxresidence->Size = System::Drawing::Size(151, 20);
			this->textBoxresidence->TabIndex = 7;
			this->textBoxresidence->Text = L"Residence Name";
			// 
			// textBoxbuilding
			// 
			this->textBoxbuilding->Location = System::Drawing::Point(404, 100);
			this->textBoxbuilding->Margin = System::Windows::Forms::Padding(2);
			this->textBoxbuilding->Name = L"textBoxbuilding";
			this->textBoxbuilding->Size = System::Drawing::Size(151, 20);
			this->textBoxbuilding->TabIndex = 8;
			this->textBoxbuilding->Text = L"Building Name";
			// 
			// textBoxstreetnumber
			// 
			this->textBoxstreetnumber->Location = System::Drawing::Point(52, 100);
			this->textBoxstreetnumber->Margin = System::Windows::Forms::Padding(2);
			this->textBoxstreetnumber->Name = L"textBoxstreetnumber";
			this->textBoxstreetnumber->Size = System::Drawing::Size(151, 20);
			this->textBoxstreetnumber->TabIndex = 9;
			this->textBoxstreetnumber->Text = L"Street Number";
			// 
			// textBoxfloor
			// 
			this->textBoxfloor->Location = System::Drawing::Point(225, 140);
			this->textBoxfloor->Margin = System::Windows::Forms::Padding(2);
			this->textBoxfloor->Name = L"textBoxfloor";
			this->textBoxfloor->Size = System::Drawing::Size(151, 20);
			this->textBoxfloor->TabIndex = 10;
			this->textBoxfloor->Text = L"Floor Number";
			// 
			// labelAdress
			// 
			this->labelAdress->AutoSize = true;
			this->labelAdress->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAdress->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->labelAdress->Location = System::Drawing::Point(220, 10);
			this->labelAdress->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelAdress->Name = L"labelAdress";
			this->labelAdress->Size = System::Drawing::Size(156, 40);
			this->labelAdress->TabIndex = 11;
			this->labelAdress->Text = L"ADRESS";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btncancel);
			this->panel1->Controls->Add(this->btnapply);
			this->panel1->Controls->Add(this->comboBoxsuperior);
			this->panel1->Controls->Add(this->dateTimePickerhiringdate);
			this->panel1->Controls->Add(this->textBoxlastname);
			this->panel1->Controls->Add(this->textBoxfirstname);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->labelAdress);
			this->panel1->Controls->Add(this->textBoxfloor);
			this->panel1->Controls->Add(this->textBoxstreetnumber);
			this->panel1->Controls->Add(this->textBoxbuilding);
			this->panel1->Controls->Add(this->textBoxresidence);
			this->panel1->Controls->Add(this->textBoxstreetname);
			this->panel1->Controls->Add(this->textboxcity);
			this->panel1->Controls->Add(this->textboxpostalcode);
			this->panel1->Location = System::Drawing::Point(1, 28);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(598, 428);
			this->panel1->TabIndex = 12;
			// 
			// btncancel
			// 
			this->btncancel->FlatAppearance->BorderSize = 0;
			this->btncancel->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btncancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncancel->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btncancel->ForeColor = System::Drawing::Color::DimGray;
			this->btncancel->Location = System::Drawing::Point(10, 384);
			this->btncancel->Margin = System::Windows::Forms::Padding(2);
			this->btncancel->Name = L"btncancel";
			this->btncancel->Size = System::Drawing::Size(82, 32);
			this->btncancel->TabIndex = 18;
			this->btncancel->Text = L"CANCEL";
			this->btncancel->UseVisualStyleBackColor = true;
			this->btncancel->Click += gcnew System::EventHandler(this, &UpdateEmployeeForm::btncancel_Click);
			this->btncancel->MouseEnter += gcnew System::EventHandler(this, &UpdateEmployeeForm::btncancel_OnMouseEnter);
			this->btncancel->MouseLeave += gcnew System::EventHandler(this, &UpdateEmployeeForm::btncancel_OnMouseLeave);
			// 
			// btnapply
			// 
			this->btnapply->FlatAppearance->BorderSize = 0;
			this->btnapply->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnapply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnapply->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnapply->ForeColor = System::Drawing::Color::DimGray;
			this->btnapply->Location = System::Drawing::Point(506, 384);
			this->btnapply->Margin = System::Windows::Forms::Padding(2);
			this->btnapply->Name = L"btnapply";
			this->btnapply->Size = System::Drawing::Size(82, 32);
			this->btnapply->TabIndex = 17;
			this->btnapply->Text = L"APPLY";
			this->btnapply->UseVisualStyleBackColor = true;
			this->btnapply->Click += gcnew System::EventHandler(this, &UpdateEmployeeForm::btnapply_Click);
			this->btnapply->MouseEnter += gcnew System::EventHandler(this, &UpdateEmployeeForm::btnapply_OnMouseEnter);
			this->btnapply->MouseLeave += gcnew System::EventHandler(this, &UpdateEmployeeForm::btnapply_OnMouseLeave);
			// 
			// comboBoxsuperior
			// 
			this->comboBoxsuperior->FormattingEnabled = true;
			this->comboBoxsuperior->Location = System::Drawing::Point(404, 280);
			this->comboBoxsuperior->Margin = System::Windows::Forms::Padding(2);
			this->comboBoxsuperior->Name = L"comboBoxsuperior";
			this->comboBoxsuperior->Size = System::Drawing::Size(151, 21);
			this->comboBoxsuperior->TabIndex = 16;
			// 
			// dateTimePickerhiringdate
			// 
			this->dateTimePickerhiringdate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePickerhiringdate->Location = System::Drawing::Point(225, 320);
			this->dateTimePickerhiringdate->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePickerhiringdate->Name = L"dateTimePickerhiringdate";
			this->dateTimePickerhiringdate->Size = System::Drawing::Size(151, 20);
			this->dateTimePickerhiringdate->TabIndex = 15;
			this->dateTimePickerhiringdate->Value = System::DateTime(2022, 11, 25, 0, 0, 0, 0);
			// 
			// textBoxlastname
			// 
			this->textBoxlastname->Location = System::Drawing::Point(225, 280);
			this->textBoxlastname->Margin = System::Windows::Forms::Padding(2);
			this->textBoxlastname->Name = L"textBoxlastname";
			this->textBoxlastname->Size = System::Drawing::Size(151, 20);
			this->textBoxlastname->TabIndex = 14;
			this->textBoxlastname->Text = L"Lastname";
			// 
			// textBoxfirstname
			// 
			this->textBoxfirstname->Location = System::Drawing::Point(52, 280);
			this->textBoxfirstname->Margin = System::Windows::Forms::Padding(2);
			this->textBoxfirstname->Name = L"textBoxfirstname";
			this->textBoxfirstname->Size = System::Drawing::Size(151, 20);
			this->textBoxfirstname->TabIndex = 13;
			this->textBoxfirstname->Text = L"Firstname";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->label1->Location = System::Drawing::Point(203, 230);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 40);
			this->label1->TabIndex = 11;
			this->label1->Text = L"EMPLOYEE";
			// 
			// UpdateEmployeeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 455);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"UpdateEmployeeForm";
			this->Text = L"UpdateEmployeeForm";
			this->Load += gcnew System::EventHandler(this, &UpdateEmployeeForm::UpdateEmployeeForm_Load);
			this->panelheader->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


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

	private: System::Void UpdateEmployeeForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void UpdateEmployeeForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void UpdateEmployeeForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

		   /// <summary>
		   /// Form Load
		   /// </summary>

	private: System::Void UpdateEmployeeForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void btncancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnapply_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(this->textBoxfirstname->Text) || String::IsNullOrWhiteSpace(this->textBoxlastname->Text) || String::IsNullOrWhiteSpace(this->textboxpostalcode->Text) || String::IsNullOrWhiteSpace(this->textboxcity->Text) || String::IsNullOrWhiteSpace(this->textBoxstreetname->Text) || String::IsNullOrWhiteSpace(this->textBoxstreetnumber->Text)){
			Employee employee;
		}
		else {
			Employee employee;

			employee.SetId(employeeID);
			employee.SetFirstname(marshal_as<std::string>(this->textBoxfirstname->Text));
			employee.SetLastname(marshal_as<std::string>(this->textBoxlastname->Text));
			employee.SetHiringdate(marshal_as<std::string>(this->dateTimePickerhiringdate->Text));
			employee.SetIdSuperior(std::stoi(marshal_as<std::string>(this->comboBoxsuperior->SelectedValue->ToString())));

			ServiceEmployee().Update(employee);

			Adress adress;
			adress.SetId(adressID);
			adress.SetPostalcode(marshal_as<std::string>(this->textboxpostalcode->Text));
			adress.SetCity(marshal_as<std::string>(this->textboxcity->Text));
			adress.SetStreetname(marshal_as<std::string>(this->textBoxstreetname->Text));
			adress.SetStreetnumber(marshal_as<std::string>(this->textBoxstreetnumber->Text));

			if (this->textBoxresidence->Text != "") {
				adress.SetResidencename(marshal_as<std::string>(this->textBoxresidence->Text));
			}
			else {
				adress.SetResidencename("");
			}

			if (this->textBoxbuilding->Text != "") {
				adress.SetBuildingname(marshal_as<std::string>(this->textBoxbuilding->Text));
			}
			else {
				adress.SetBuildingname("");
			}

			if (this->textBoxfloor->Text != "") {
				adress.SetFloornumber(marshal_as<std::string>(this->textBoxfloor->Text));
			}
			else {
				adress.SetFloornumber("");
			}

			ServiceAdress().Update(adress);

			//this->MdiParent->refresh_dataGridView();
			this->listener->onApplyClicked();

			this->Close();
		}

	}
	};
}