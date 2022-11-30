#pragma once
#include "ServiceAdress.h"
#include "ServiceOrder.h"
#include "ErrorForm.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de UpdateOrderForm
	/// </summary>
	public ref class UpdateOrderForm : public System::Windows::Forms::Form
	{

	public:
		ref class Listener abstract
		{
		public:
			virtual void onApplyClicked() = 0;
		};

		Listener^ listener;
		ErrorForm^ errorForm;
		int orderID;
		int deliveryID;
		int billingID;

		UpdateOrderForm(Listener^ listener)
		{
			InitializeComponent();
			this->listener = listener;

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~UpdateOrderForm()
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

	private: System::Windows::Forms::DateTimePicker^ dateTimePickerhiringdate;


	private: System::Windows::Forms::TextBox^ textBoxlastname;

	private: System::Windows::Forms::TextBox^ textBoxfirstname;


	private: System::Windows::Forms::Button^ btncancel;
	private: System::Windows::Forms::Button^ btnapply;
	private: System::Windows::Forms::Label^ labelorder;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxfloor2;

	private: System::Windows::Forms::TextBox^ textBoxstreetnumber2;
	private: System::Windows::Forms::TextBox^ textBoxbuilding2;


	private: System::Windows::Forms::TextBox^ textBoxresidence2;

	private: System::Windows::Forms::TextBox^ textBoxstreetname2;

	private: System::Windows::Forms::TextBox^ textBoxcity2;

	private: System::Windows::Forms::TextBox^ textBoxpostalcode2;
	private: System::Windows::Forms::CheckBox^ checkBoxadress;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UpdateOrderForm::typeid));
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
			this->dateTimePickerhiringdate = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxlastname = (gcnew System::Windows::Forms::TextBox());
			this->textBoxfirstname = (gcnew System::Windows::Forms::TextBox());
			this->labelorder = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxfloor2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxstreetnumber2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxbuilding2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxresidence2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxstreetname2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxcity2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxpostalcode2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxadress = (gcnew System::Windows::Forms::CheckBox());
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
			this->panelheader->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(800, 43);
			this->panelheader->TabIndex = 2;
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateOrderForm::UpdateOrderForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateOrderForm::UpdateOrderForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UpdateOrderForm::UpdateOrderForm_MouseUp);
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
			this->btnclose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(37, 34);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"X";
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &UpdateOrderForm::btnclose_Click);
			// 
			// textboxpostalcode
			// 
			this->textboxpostalcode->Location = System::Drawing::Point(69, 74);
			this->textboxpostalcode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textboxpostalcode->Name = L"textboxpostalcode";
			this->textboxpostalcode->Size = System::Drawing::Size(200, 22);
			this->textboxpostalcode->TabIndex = 4;
			this->textboxpostalcode->Text = L"Postal Code";
			// 
			// textboxcity
			// 
			this->textboxcity->Location = System::Drawing::Point(300, 74);
			this->textboxcity->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textboxcity->Name = L"textboxcity";
			this->textboxcity->Size = System::Drawing::Size(200, 22);
			this->textboxcity->TabIndex = 5;
			this->textboxcity->Text = L"City";
			// 
			// textBoxstreetname
			// 
			this->textBoxstreetname->Location = System::Drawing::Point(539, 74);
			this->textBoxstreetname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxstreetname->Name = L"textBoxstreetname";
			this->textBoxstreetname->Size = System::Drawing::Size(200, 22);
			this->textBoxstreetname->TabIndex = 6;
			this->textBoxstreetname->Text = L"Street Name";
			// 
			// textBoxresidence
			// 
			this->textBoxresidence->Location = System::Drawing::Point(300, 123);
			this->textBoxresidence->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxresidence->Name = L"textBoxresidence";
			this->textBoxresidence->Size = System::Drawing::Size(200, 22);
			this->textBoxresidence->TabIndex = 7;
			this->textBoxresidence->Text = L"Residence Name";
			// 
			// textBoxbuilding
			// 
			this->textBoxbuilding->Location = System::Drawing::Point(539, 123);
			this->textBoxbuilding->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxbuilding->Name = L"textBoxbuilding";
			this->textBoxbuilding->Size = System::Drawing::Size(200, 22);
			this->textBoxbuilding->TabIndex = 8;
			this->textBoxbuilding->Text = L"Building Name";
			// 
			// textBoxstreetnumber
			// 
			this->textBoxstreetnumber->Location = System::Drawing::Point(69, 123);
			this->textBoxstreetnumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxstreetnumber->Name = L"textBoxstreetnumber";
			this->textBoxstreetnumber->Size = System::Drawing::Size(200, 22);
			this->textBoxstreetnumber->TabIndex = 9;
			this->textBoxstreetnumber->Text = L"Street Number";
			// 
			// textBoxfloor
			// 
			this->textBoxfloor->Location = System::Drawing::Point(300, 172);
			this->textBoxfloor->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxfloor->Name = L"textBoxfloor";
			this->textBoxfloor->Size = System::Drawing::Size(200, 22);
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
			this->labelAdress->Location = System::Drawing::Point(293, 12);
			this->labelAdress->Name = L"labelAdress";
			this->labelAdress->Size = System::Drawing::Size(193, 49);
			this->labelAdress->TabIndex = 11;
			this->labelAdress->Text = L"BILLING";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->checkBoxadress);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBoxfloor2);
			this->panel1->Controls->Add(this->textBoxstreetnumber2);
			this->panel1->Controls->Add(this->textBoxbuilding2);
			this->panel1->Controls->Add(this->textBoxresidence2);
			this->panel1->Controls->Add(this->textBoxstreetname2);
			this->panel1->Controls->Add(this->textBoxcity2);
			this->panel1->Controls->Add(this->textBoxpostalcode2);
			this->panel1->Controls->Add(this->btncancel);
			this->panel1->Controls->Add(this->btnapply);
			this->panel1->Controls->Add(this->dateTimePickerhiringdate);
			this->panel1->Controls->Add(this->textBoxlastname);
			this->panel1->Controls->Add(this->textBoxfirstname);
			this->panel1->Controls->Add(this->labelorder);
			this->panel1->Controls->Add(this->labelAdress);
			this->panel1->Controls->Add(this->textBoxfloor);
			this->panel1->Controls->Add(this->textBoxstreetnumber);
			this->panel1->Controls->Add(this->textBoxbuilding);
			this->panel1->Controls->Add(this->textBoxresidence);
			this->panel1->Controls->Add(this->textBoxstreetname);
			this->panel1->Controls->Add(this->textboxcity);
			this->panel1->Controls->Add(this->textboxpostalcode);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 54);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1000, 859);
			this->panel1->TabIndex = 12;
			// 
			// btncancel
			// 
			this->btncancel->FlatAppearance->BorderSize = 0;
			this->btncancel->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btncancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncancel->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btncancel->ForeColor = System::Drawing::Color::DimGray;
			this->btncancel->Location = System::Drawing::Point(16, 646);
			this->btncancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btncancel->Name = L"btncancel";
			this->btncancel->Size = System::Drawing::Size(109, 39);
			this->btncancel->TabIndex = 18;
			this->btncancel->Text = L"CANCEL";
			this->btncancel->UseVisualStyleBackColor = true;
			this->btncancel->Click += gcnew System::EventHandler(this, &UpdateOrderForm::btncancel_Click);
			this->btncancel->MouseEnter += gcnew System::EventHandler(this, &UpdateOrderForm::btncancel_OnMouseEnter);
			this->btncancel->MouseLeave += gcnew System::EventHandler(this, &UpdateOrderForm::btncancel_OnMouseLeave);
			// 
			// btnapply
			// 
			this->btnapply->FlatAppearance->BorderSize = 0;
			this->btnapply->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnapply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnapply->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnapply->ForeColor = System::Drawing::Color::DimGray;
			this->btnapply->Location = System::Drawing::Point(678, 646);
			this->btnapply->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnapply->Name = L"btnapply";
			this->btnapply->Size = System::Drawing::Size(109, 39);
			this->btnapply->TabIndex = 17;
			this->btnapply->Text = L"APPLY";
			this->btnapply->UseVisualStyleBackColor = true;
			this->btnapply->Click += gcnew System::EventHandler(this, &UpdateOrderForm::btnapply_Click);
			this->btnapply->MouseEnter += gcnew System::EventHandler(this, &UpdateOrderForm::btnapply_OnMouseEnter);
			this->btnapply->MouseLeave += gcnew System::EventHandler(this, &UpdateOrderForm::btnapply_OnMouseLeave);
			// 
			// dateTimePickerhiringdate
			// 
			this->dateTimePickerhiringdate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePickerhiringdate->Location = System::Drawing::Point(539, 547);
			this->dateTimePickerhiringdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePickerhiringdate->Name = L"dateTimePickerhiringdate";
			this->dateTimePickerhiringdate->Size = System::Drawing::Size(200, 22);
			this->dateTimePickerhiringdate->TabIndex = 15;
			this->dateTimePickerhiringdate->Value = System::DateTime(2022, 11, 25, 0, 0, 0, 0);
			// 
			// textBoxlastname
			// 
			this->textBoxlastname->Location = System::Drawing::Point(300, 547);
			this->textBoxlastname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxlastname->Name = L"textBoxlastname";
			this->textBoxlastname->Size = System::Drawing::Size(200, 22);
			this->textBoxlastname->TabIndex = 14;
			this->textBoxlastname->Text = L"Lastname";
			// 
			// textBoxfirstname
			// 
			this->textBoxfirstname->Location = System::Drawing::Point(69, 547);
			this->textBoxfirstname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxfirstname->Name = L"textBoxfirstname";
			this->textBoxfirstname->Size = System::Drawing::Size(200, 22);
			this->textBoxfirstname->TabIndex = 13;
			this->textBoxfirstname->Text = L"Firstname";
			// 
			// labelorder
			// 
			this->labelorder->AutoSize = true;
			this->labelorder->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelorder->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->labelorder->Location = System::Drawing::Point(271, 485);
			this->labelorder->Name = L"labelorder";
			this->labelorder->Size = System::Drawing::Size(257, 49);
			this->labelorder->TabIndex = 11;
			this->labelorder->Text = L"CUSTOMER";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->label1->Location = System::Drawing::Point(293, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 49);
			this->label1->TabIndex = 26;
			this->label1->Text = L"DELIVERY";
			// 
			// textBoxfloor2
			// 
			this->textBoxfloor2->Location = System::Drawing::Point(300, 410);
			this->textBoxfloor2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxfloor2->Name = L"textBoxfloor2";
			this->textBoxfloor2->Size = System::Drawing::Size(200, 22);
			this->textBoxfloor2->TabIndex = 25;
			this->textBoxfloor2->Text = L"Floor Number";

			// 
			// textBoxstreetnumber2
			// 
			this->textBoxstreetnumber2->Location = System::Drawing::Point(69, 361);
			this->textBoxstreetnumber2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxstreetnumber2->Name = L"textBoxstreetnumber2";
			this->textBoxstreetnumber2->Size = System::Drawing::Size(200, 22);
			this->textBoxstreetnumber2->TabIndex = 24;
			this->textBoxstreetnumber2->Text = L"Street Number";
			// 
			// textBoxbuilding2
			// 
			this->textBoxbuilding2->Location = System::Drawing::Point(539, 361);
			this->textBoxbuilding2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxbuilding2->Name = L"textBoxbuilding2";
			this->textBoxbuilding2->Size = System::Drawing::Size(200, 22);
			this->textBoxbuilding2->TabIndex = 23;
			this->textBoxbuilding2->Text = L"Building Name";
			// 
			// textBoxresidence2
			// 
			this->textBoxresidence2->Location = System::Drawing::Point(300, 361);
			this->textBoxresidence2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxresidence2->Name = L"textBoxresidence2";
			this->textBoxresidence2->Size = System::Drawing::Size(200, 22);
			this->textBoxresidence2->TabIndex = 22;
			this->textBoxresidence2->Text = L"Residence Name";
			// 
			// textBoxstreetname2
			// 
			this->textBoxstreetname2->Location = System::Drawing::Point(539, 312);
			this->textBoxstreetname2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxstreetname2->Name = L"textBoxstreetname2";
			this->textBoxstreetname2->Size = System::Drawing::Size(200, 22);
			this->textBoxstreetname2->TabIndex = 21;
			this->textBoxstreetname2->Text = L"Street Name";
			// 
			// textBoxcity2
			// 
			this->textBoxcity2->Location = System::Drawing::Point(300, 312);
			this->textBoxcity2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxcity2->Name = L"textBoxcity2";
			this->textBoxcity2->Size = System::Drawing::Size(200, 22);
			this->textBoxcity2->TabIndex = 20;
			this->textBoxcity2->Text = L"City";
			// 
			// textBoxpostalcode2
			// 
			this->textBoxpostalcode2->Location = System::Drawing::Point(69, 312);
			this->textBoxpostalcode2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxpostalcode2->Name = L"textBoxpostalcode2";
			this->textBoxpostalcode2->Size = System::Drawing::Size(200, 22);
			this->textBoxpostalcode2->TabIndex = 19;
			this->textBoxpostalcode2->Text = L"Postal Code";
			// 
			// checkBoxadress
			// 
			this->checkBoxadress->AutoSize = true;
			this->checkBoxadress->Location = System::Drawing::Point(541, 174);
			this->checkBoxadress->Name = L"checkBoxadress";
			this->checkBoxadress->Size = System::Drawing::Size(186, 20);
			this->checkBoxadress->TabIndex = 27;
			this->checkBoxadress->Text = L"Use Same Adress for both";
			this->checkBoxadress->UseVisualStyleBackColor = true;
			// 
			// UpdateOrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 730);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"UpdateOrderForm";
			this->Text = L"UpdateOrderForm";
			this->Load += gcnew System::EventHandler(this, &UpdateOrderForm::comboBoxsuperior_Load);
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

	private: System::Void UpdateOrderForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void UpdateOrderForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void UpdateOrderForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

		   /// <summary>
		   /// Form Load
		   /// </summary>

	private: System::Void UpdateOrderForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void comboBoxsuperior_Load(System::Object^ sender, System::EventArgs^ e) {
		//this->comboBoxsuperior->Refresh();
		//this->comboBoxsuperior->DataSource = BB8Manager_Core_Services::ServiceOrder().GetDataSetSuperior()->Tables[0];
		//this->comboBoxsuperior->DisplayMember = "Name";
		//this->comboBoxsuperior->ValueMember = "ID";
	}
	private: System::Void btncancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnapply_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	};
}
