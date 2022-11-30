#pragma once
#include "ServiceAdress.h"
#include "ServiceEmployee.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de AddEmployeeForm
	/// </summary>
	public ref class AddEmployeeForm : public System::Windows::Forms::Form
	{

	public:
		ref class Listener abstract
		{
		public:
			virtual void onApplyClicked() = 0;
		};

		Listener^ listener;

		AddEmployeeForm(Listener^ listener)
		{
			InitializeComponent();
			this->listener = listener;
		}
	/*public:

		AddEmployeeForm(void)
		{
			InitializeComponent();
		}*/

		/*MAIN1::EmployeeForm^ frm;

		AddEmployeeForm(MAIN1::EmployeeForm^ frm)
		{
			InitializeComponent();
			this->frm = frm;
		}*/

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddEmployeeForm()
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
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddEmployeeForm::typeid));
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
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddEmployeeForm::AddEmployeeForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &AddEmployeeForm::AddEmployeeForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AddEmployeeForm::AddEmployeeForm_MouseUp);
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
			this->btnclose->Click += gcnew System::EventHandler(this, &AddEmployeeForm::btnclose_Click);
			// 
			// textboxpostalcode
			// 
			this->textboxpostalcode->Location = System::Drawing::Point(52, 60);
			this->textboxpostalcode->Margin = System::Windows::Forms::Padding(2);
			this->textboxpostalcode->Name = L"textboxpostalcode";
			this->textboxpostalcode->Size = System::Drawing::Size(151, 20);
			this->textboxpostalcode->TabIndex = 4;
			this->textboxpostalcode->Text = L"Postal Code";
			this->textboxpostalcode->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textboxpostalcode_RemoveText);
			this->textboxpostalcode->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textboxpostalcode_AddText);
			// 
			// textboxcity
			// 
			this->textboxcity->Location = System::Drawing::Point(225, 60);
			this->textboxcity->Margin = System::Windows::Forms::Padding(2);
			this->textboxcity->Name = L"textboxcity";
			this->textboxcity->Size = System::Drawing::Size(151, 20);
			this->textboxcity->TabIndex = 5;
			this->textboxcity->Text = L"City";
			this->textboxcity->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textboxcity_RemoveText);
			this->textboxcity->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textboxcity_AddText);
			// 
			// textBoxstreetname
			// 
			this->textBoxstreetname->Location = System::Drawing::Point(404, 60);
			this->textBoxstreetname->Margin = System::Windows::Forms::Padding(2);
			this->textBoxstreetname->Name = L"textBoxstreetname";
			this->textBoxstreetname->Size = System::Drawing::Size(151, 20);
			this->textBoxstreetname->TabIndex = 6;
			this->textBoxstreetname->Text = L"Street Name";
			this->textBoxstreetname->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxstreetname_RemoveText);
			this->textBoxstreetname->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxstreetname_AddText);
			// 
			// textBoxresidence
			// 
			this->textBoxresidence->Location = System::Drawing::Point(225, 100);
			this->textBoxresidence->Margin = System::Windows::Forms::Padding(2);
			this->textBoxresidence->Name = L"textBoxresidence";
			this->textBoxresidence->Size = System::Drawing::Size(151, 20);
			this->textBoxresidence->TabIndex = 7;
			this->textBoxresidence->Text = L"Residence Name";
			this->textBoxresidence->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxresidence_RemoveText);
			this->textBoxresidence->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxresidence_AddText);
			// 
			// textBoxbuilding
			// 
			this->textBoxbuilding->Location = System::Drawing::Point(404, 100);
			this->textBoxbuilding->Margin = System::Windows::Forms::Padding(2);
			this->textBoxbuilding->Name = L"textBoxbuilding";
			this->textBoxbuilding->Size = System::Drawing::Size(151, 20);
			this->textBoxbuilding->TabIndex = 8;
			this->textBoxbuilding->Text = L"Building Name";
			this->textBoxbuilding->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxbuilding_RemoveText);
			this->textBoxbuilding->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxbuilding_AddText);
			// 
			// textBoxstreetnumber
			// 
			this->textBoxstreetnumber->Location = System::Drawing::Point(52, 100);
			this->textBoxstreetnumber->Margin = System::Windows::Forms::Padding(2);
			this->textBoxstreetnumber->Name = L"textBoxstreetnumber";
			this->textBoxstreetnumber->Size = System::Drawing::Size(151, 20);
			this->textBoxstreetnumber->TabIndex = 9;
			this->textBoxstreetnumber->Text = L"Street Number";
			this->textBoxstreetnumber->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxstreetnumber_RemoveText);
			this->textBoxstreetnumber->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxstreetnumber_AddText);
			// 
			// textBoxfloor
			// 
			this->textBoxfloor->Location = System::Drawing::Point(225, 140);
			this->textBoxfloor->Margin = System::Windows::Forms::Padding(2);
			this->textBoxfloor->Name = L"textBoxfloor";
			this->textBoxfloor->Size = System::Drawing::Size(151, 20);
			this->textBoxfloor->TabIndex = 10;
			this->textBoxfloor->Text = L"Floor Number";
			this->textBoxfloor->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxfloor_RemoveText);
			this->textBoxfloor->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxfloor_AddText);
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
			this->btncancel->Click += gcnew System::EventHandler(this, &AddEmployeeForm::btncancel_Click);
			this->btncancel->MouseEnter += gcnew System::EventHandler(this, &AddEmployeeForm::btncancel_OnMouseEnter);
			this->btncancel->MouseLeave += gcnew System::EventHandler(this, &AddEmployeeForm::btncancel_OnMouseLeave);
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
			this->btnapply->Click += gcnew System::EventHandler(this, &AddEmployeeForm::btnapply_Click);
			this->btnapply->MouseEnter += gcnew System::EventHandler(this, &AddEmployeeForm::btnapply_OnMouseEnter);
			this->btnapply->MouseLeave += gcnew System::EventHandler(this, &AddEmployeeForm::btnapply_OnMouseLeave);
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
			this->textBoxlastname->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxlastname_RemoveText);
			this->textBoxlastname->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxlastname_AddText);
			// 
			// textBoxfirstname
			// 
			this->textBoxfirstname->Location = System::Drawing::Point(52, 280);
			this->textBoxfirstname->Margin = System::Windows::Forms::Padding(2);
			this->textBoxfirstname->Name = L"textBoxfirstname";
			this->textBoxfirstname->Size = System::Drawing::Size(151, 20);
			this->textBoxfirstname->TabIndex = 13;
			this->textBoxfirstname->Text = L"Firstname";
			this->textBoxfirstname->GotFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxfirstname_RemoveText);
			this->textBoxfirstname->LostFocus += gcnew System::EventHandler(this, &AddEmployeeForm::textBoxfirstname_AddText);
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
			// AddEmployeeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 455);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddEmployeeForm";
			this->Text = L"AddEmployeeForm";
			this->Load += gcnew System::EventHandler(this, &AddEmployeeForm::comboBoxsuperior_Load);
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

private: System::Void AddEmployeeForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}

private: System::Void AddEmployeeForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}

private: System::Void AddEmployeeForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}

/// <summary>
/// Placeholder Textbox
/// </summary>

private: System::Void textboxpostalcode_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textboxpostalcode->Text == "Postal Code")
		this->textboxpostalcode->Text = "";
}

private: System::Void textboxpostalcode_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textboxpostalcode->Text))
		this->textboxpostalcode->Text = "Postal Code";
}

private: System::Void textboxcity_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textboxcity->Text == "City")
		this->textboxcity->Text = "";
}

private: System::Void textboxcity_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textboxcity->Text))
		this->textboxcity->Text = "City";
}

private: System::Void textBoxstreetname_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxstreetname->Text == "Street Name")
		this->textBoxstreetname->Text = "";
}

private: System::Void textBoxstreetname_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxstreetname->Text))
		this->textBoxstreetname->Text = "Street Name";
}

private: System::Void textBoxstreetnumber_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxstreetnumber->Text == "Street Number")
		this->textBoxstreetnumber->Text = "";
}

private: System::Void textBoxstreetnumber_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxstreetnumber->Text))
		this->textBoxstreetnumber->Text = "Street Number";
}

private: System::Void textBoxresidence_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxresidence->Text == "Residence Name")
		this->textBoxresidence->Text = "";
}

private: System::Void textBoxresidence_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxresidence->Text))
		this->textBoxresidence->Text = "Residence Name";
}

private: System::Void textBoxbuilding_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxbuilding->Text == "Building Name")
		this->textBoxbuilding->Text = "";
}

private: System::Void textBoxbuilding_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxbuilding->Text))
		this->textBoxbuilding->Text = "Building Name";
}

private: System::Void textBoxfloor_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxfloor->Text == "Floor Number")
		this->textBoxfloor->Text = "";
}

private: System::Void textBoxfloor_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxfloor->Text))
		this->textBoxfloor->Text = "Floor Number";
}

private: System::Void textBoxfirstname_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxfirstname->Text == "Firstname")
		this->textBoxfirstname->Text = "";
}

private: System::Void textBoxfirstname_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxfirstname->Text))
		this->textBoxfirstname->Text = "Firstname";
}

private: System::Void textBoxlastname_RemoveText(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxlastname->Text == "Lastname")
		this->textBoxlastname->Text = "";
}

private: System::Void textBoxlastname_AddText(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrWhiteSpace(this->textBoxlastname->Text))
		this->textBoxlastname->Text = "Lastname";
}

/// <summary>
/// Form Load
/// </summary>

private: System::Void AddEmployeeForm_Load(System::Object^ sender, System::EventArgs^ e) {
	this->dragging = false;
}

private: System::Void comboBoxsuperior_Load(System::Object^ sender, System::EventArgs^ e) {
	this->comboBoxsuperior->Refresh();
	this->comboBoxsuperior->DataSource = BB8Manager_Core_Services::ServiceEmployee().GetDataSetSuperior()->Tables[0];
	this->comboBoxsuperior->DisplayMember = "Name";
	this->comboBoxsuperior->ValueMember = "ID";
}
private: System::Void btncancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnapply_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->textboxpostalcode->Text != "Postal Code" && this->textboxcity->Text != "City" && this->textBoxstreetname->Text != "Street Name" && this->textBoxstreetnumber->Text != "Street Number" && this->textBoxfirstname->Text != "Firstname" && this->textBoxlastname->Text != "Lastname") {
		Adress adress;
		adress.SetPostalcode(marshal_as<std::string>(this->textboxpostalcode->Text));
		adress.SetCity(marshal_as<std::string>(this->textboxcity->Text));
		adress.SetStreetname(marshal_as<std::string>(this->textBoxstreetname->Text));
		adress.SetStreetnumber(marshal_as<std::string>(this->textBoxstreetnumber->Text));

		if (this->textBoxresidence->Text != "Residence Name") {
			adress.SetResidencename(marshal_as<std::string>(this->textBoxresidence->Text));
		}
		else {
			adress.SetResidencename("");
		}

		if (this->textBoxbuilding->Text != "Building Name") {
			adress.SetBuildingname(marshal_as<std::string>(this->textBoxbuilding->Text));
		}
		else {
			adress.SetBuildingname("");
		}

		if (this->textBoxfloor->Text != "Floor Number") {
			adress.SetFloornumber(marshal_as<std::string>(this->textBoxfloor->Text));
		}
		else {
			adress.SetFloornumber("");
		}

		adress = ServiceAdress().Add(adress);

		Employee employee;

		employee.SetFirstname(marshal_as<std::string>(this->textBoxfirstname->Text));
		employee.SetLastname(marshal_as<std::string>(this->textBoxlastname->Text));
		employee.SetHiringdate(marshal_as<std::string>(this->dateTimePickerhiringdate->Text));
		employee.SetIdSuperior(std::stoi(marshal_as<std::string>(this->comboBoxsuperior->SelectedValue->ToString())));
		employee.SetIdAdress(adress.GetId());

		employee = ServiceEmployee().Add(employee);

		//this->MdiParent->refresh_dataGridView();
		this->listener->onApplyClicked();

		this->Close();
	}
}
};
}
