#pragma once
#include "ServiceAdress.h"
#include "ServiceItem.h"
#include "ServiceStock.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ComboboxItem {
		String^ _text = "";
		Object^ _value;

		public: ComboboxItem(String^ text, Object^ value)
			{
				_text = text;
				_value = value;
			}

		public: property String^ Text
		{
			String^ get()
			{
				return _text;
			}
			void set(String^ value)
			{
				_text = value;
			}
		}
		public:  property Object^ Value
		{
			Object^ get()
			{
				return _value;
			}
			void set(Object^ value)
			{
				_value = value;
			}
		}
		public:  String^ ToString() override
		{
			return Text;
		}
	};
	

	/// <summary>
	/// Description résumée de AddStockForm
	/// </summary>
	public ref class AddStockForm : public System::Windows::Forms::Form
	{

	public:
		ref class Listener abstract
		{
		public:
			virtual void onApplyClicked() = 0;
		};

		Listener^ listener;

		AddStockForm(Listener^ listener)
		{
			InitializeComponent();
			this->listener = listener;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddStockForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: bool dragging;
	private: Point offset;

	private: System::Windows::Forms::Panel^ panelheader;
	private: System::Windows::Forms::Button^ btnclose;
	private: System::Windows::Forms::TextBox^ textboxname;
	private: System::Windows::Forms::TextBox^ textboxlot;
	private: System::Windows::Forms::TextBox^ textBoxprice;
	private: System::Windows::Forms::TextBox^ textBoxreorder;
	private: System::Windows::Forms::TextBox^ textBoxstock;
	private: System::Windows::Forms::Label^ labelItem;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btncancel;
	private: System::Windows::Forms::Button^ btnapply;
	private: System::Windows::Forms::ComboBox^ comboBoxreduction;
	private: System::Windows::Forms::ComboBox^ comboBoxvat;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddStockForm::typeid));
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->textboxname = (gcnew System::Windows::Forms::TextBox());
			this->textboxlot = (gcnew System::Windows::Forms::TextBox());
			this->textBoxprice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxreorder = (gcnew System::Windows::Forms::TextBox());
			this->textBoxstock = (gcnew System::Windows::Forms::TextBox());
			this->labelItem = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btncancel = (gcnew System::Windows::Forms::Button());
			this->btnapply = (gcnew System::Windows::Forms::Button());
			this->comboBoxvat = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxreduction = (gcnew System::Windows::Forms::ComboBox());
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
			this->panelheader->Size = System::Drawing::Size(600, 35);
			this->panelheader->TabIndex = 2;
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddStockForm::AddStockForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &AddStockForm::AddStockForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &AddStockForm::AddStockForm_MouseUp);
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
			this->btnclose->Click += gcnew System::EventHandler(this, &AddStockForm::btnclose_Click);
			// 
			// textboxname
			// 
			this->textboxname->Location = System::Drawing::Point(52, 60);
			this->textboxname->Margin = System::Windows::Forms::Padding(2);
			this->textboxname->Name = L"textboxname";
			this->textboxname->Size = System::Drawing::Size(151, 20);
			this->textboxname->TabIndex = 4;
			this->textboxname->Text = L"Name";
			this->textboxname->GotFocus += gcnew System::EventHandler(this, &AddStockForm::textboxname_RemoveText);
			this->textboxname->LostFocus += gcnew System::EventHandler(this, &AddStockForm::textboxname_AddText);
			// 
			// textboxlot
			// 
			this->textboxlot->Location = System::Drawing::Point(225, 60);
			this->textboxlot->Margin = System::Windows::Forms::Padding(2);
			this->textboxlot->Name = L"textboxlot";
			this->textboxlot->Size = System::Drawing::Size(151, 20);
			this->textboxlot->TabIndex = 5;
			this->textboxlot->Text = L"Lot";
			this->textboxlot->GotFocus += gcnew System::EventHandler(this, &AddStockForm::textboxlot_RemoveText);
			this->textboxlot->LostFocus += gcnew System::EventHandler(this, &AddStockForm::textboxlot_AddText);
			// 
			// textBoxprice
			// 
			this->textBoxprice->Location = System::Drawing::Point(404, 60);
			this->textBoxprice->Margin = System::Windows::Forms::Padding(2);
			this->textBoxprice->Name = L"textBoxprice";
			this->textBoxprice->Size = System::Drawing::Size(151, 20);
			this->textBoxprice->TabIndex = 6;
			this->textBoxprice->Text = L"Price (exclude taxes)";
			this->textBoxprice->GotFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxprice_RemoveText);
			this->textBoxprice->LostFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxprice_AddText);
			// 
			// textBoxreorder
			// 
			this->textBoxreorder->Location = System::Drawing::Point(225, 100);
			this->textBoxreorder->Margin = System::Windows::Forms::Padding(2);
			this->textBoxreorder->Name = L"textBoxreorder";
			this->textBoxreorder->Size = System::Drawing::Size(151, 20);
			this->textBoxreorder->TabIndex = 7;
			this->textBoxreorder->Text = L"Reorder Threshold";
			this->textBoxreorder->GotFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxreorder_RemoveText);
			this->textBoxreorder->LostFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxreorder_AddText);
			// 
			// textBoxstock
			// 
			this->textBoxstock->Location = System::Drawing::Point(52, 100);
			this->textBoxstock->Margin = System::Windows::Forms::Padding(2);
			this->textBoxstock->Name = L"textBoxstock";
			this->textBoxstock->Size = System::Drawing::Size(151, 20);
			this->textBoxstock->TabIndex = 9;
			this->textBoxstock->Text = L"Stock";
			this->textBoxstock->GotFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxstock_RemoveText);
			this->textBoxstock->LostFocus += gcnew System::EventHandler(this, &AddStockForm::textBoxstock_AddText);
			// 
			// labelItem
			// 
			this->labelItem->AutoSize = true;
			this->labelItem->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->labelItem->Location = System::Drawing::Point(250, 10);
			this->labelItem->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelItem->Name = L"labelItem";
			this->labelItem->Size = System::Drawing::Size(101, 40);
			this->labelItem->TabIndex = 11;
			this->labelItem->Text = L"ITEM";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBoxreduction);
			this->panel1->Controls->Add(this->comboBoxvat);
			this->panel1->Controls->Add(this->btncancel);
			this->panel1->Controls->Add(this->btnapply);
			this->panel1->Controls->Add(this->labelItem);
			this->panel1->Controls->Add(this->textBoxstock);
			this->panel1->Controls->Add(this->textBoxreorder);
			this->panel1->Controls->Add(this->textBoxprice);
			this->panel1->Controls->Add(this->textboxlot);
			this->panel1->Controls->Add(this->textboxname);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 35);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(600, 215);
			this->panel1->TabIndex = 12;
			// 
			// btncancel
			// 
			this->btncancel->FlatAppearance->BorderSize = 0;
			this->btncancel->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btncancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncancel->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btncancel->ForeColor = System::Drawing::Color::DimGray;
			this->btncancel->Location = System::Drawing::Point(11, 172);
			this->btncancel->Margin = System::Windows::Forms::Padding(2);
			this->btncancel->Name = L"btncancel";
			this->btncancel->Size = System::Drawing::Size(82, 32);
			this->btncancel->TabIndex = 18;
			this->btncancel->Text = L"CANCEL";
			this->btncancel->UseVisualStyleBackColor = true;
			this->btncancel->Click += gcnew System::EventHandler(this, &AddStockForm::btncancel_Click);
			this->btncancel->MouseEnter += gcnew System::EventHandler(this, &AddStockForm::btncancel_OnMouseEnter);
			this->btncancel->MouseLeave += gcnew System::EventHandler(this, &AddStockForm::btncancel_OnMouseLeave);
			// 
			// btnapply
			// 
			this->btnapply->FlatAppearance->BorderSize = 0;
			this->btnapply->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnapply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnapply->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnapply->ForeColor = System::Drawing::Color::DimGray;
			this->btnapply->Location = System::Drawing::Point(507, 172);
			this->btnapply->Margin = System::Windows::Forms::Padding(2);
			this->btnapply->Name = L"btnapply";
			this->btnapply->Size = System::Drawing::Size(82, 32);
			this->btnapply->TabIndex = 17;
			this->btnapply->Text = L"APPLY";
			this->btnapply->UseVisualStyleBackColor = true;
			this->btnapply->Click += gcnew System::EventHandler(this, &AddStockForm::btnapply_Click);
			this->btnapply->MouseEnter += gcnew System::EventHandler(this, &AddStockForm::btnapply_OnMouseEnter);
			this->btnapply->MouseLeave += gcnew System::EventHandler(this, &AddStockForm::btnapply_OnMouseLeave);
			// 
			// comboBoxvat
			// 
			this->comboBoxvat->FormattingEnabled = true;
			this->comboBoxvat->Location = System::Drawing::Point(404, 100);
			this->comboBoxvat->Margin = System::Windows::Forms::Padding(2);
			this->comboBoxvat->Name = L"comboBoxvat";
			this->comboBoxvat->Size = System::Drawing::Size(151, 21);
			this->comboBoxvat->TabIndex = 21;
			this->comboBoxvat->Text = L"Vat";
			// 
			// comboBoxreduction
			// 
			this->comboBoxreduction->FormattingEnabled = true;
			this->comboBoxreduction->Location = System::Drawing::Point(225, 140);
			this->comboBoxreduction->Margin = System::Windows::Forms::Padding(2);
			this->comboBoxreduction->Name = L"comboBoxreduction";
			this->comboBoxreduction->Size = System::Drawing::Size(151, 21);
			this->comboBoxreduction->TabIndex = 22;
			this->comboBoxreduction->Text = L"Discount";
			// 
			// AddStockForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 250);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"AddStockForm";
			this->Text = L"AddStockForm";
			this->Load += gcnew System::EventHandler(this, &AddStockForm::comboBox_Load);
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

	private: System::Void AddStockForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void AddStockForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void AddStockForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

		   /// <summary>
		   /// Placeholder Textbox
		   /// </summary>

	private: System::Void textboxname_RemoveText(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textboxname->Text == "Name")
			this->textboxname->Text = "";
	}

	private: System::Void textboxname_AddText(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(this->textboxname->Text))
			this->textboxname->Text = "Name";
	}
	
	private: System::Void textboxlot_RemoveText(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textboxlot->Text == "Lot")
			this->textboxlot->Text = "";
	}

	private: System::Void textboxlot_AddText(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(this->textboxlot->Text))
			this->textboxlot->Text = "Lot";
	}

	private: System::Void textBoxprice_RemoveText(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textBoxprice->Text == "Price (exclude taxes)")
			this->textBoxprice->Text = "";
	}

	private: System::Void textBoxprice_AddText(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(this->textBoxprice->Text))
			this->textBoxprice->Text = "Price (exclude taxes)";
	}

	private: System::Void textBoxstock_RemoveText(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textBoxstock->Text == "Stock")
			this->textBoxstock->Text = "";
	}

	private: System::Void textBoxstock_AddText(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(this->textBoxstock->Text))
			this->textBoxstock->Text = "Stock";
	}

	private: System::Void textBoxreorder_RemoveText(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->textBoxreorder->Text == "Reorder Threshold")
			this->textBoxreorder->Text = "";
	}

	private: System::Void textBoxreorder_AddText(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(this->textBoxreorder->Text))
			this->textBoxreorder->Text = "Reorder Threshold";
	}


		   /// <summary>
		   /// Form Load
		   /// </summary>

	private: System::Void AddStockForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void comboBox_Load(System::Object^ sender, System::EventArgs^ e) {

		comboBoxreduction->Items->Clear();
		comboBoxvat->Items->Clear();
		for (int i = 0; i <= 100; i += 10) {
			comboBoxreduction->Items->Add(gcnew ComboboxItem(i + "% Discount", i));
			comboBoxvat->Items->Add(gcnew ComboboxItem(i + "% VAT", i));
		}
	}
	private: System::Void btncancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnapply_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textboxname->Text != "Name" && this->textboxlot->Text != "Lot" && this->textBoxprice->Text != "Price (exclude taxes)" && this->textBoxstock->Text != "Stock" && this->textBoxreorder->Text != "Reorder Threshold") {
			Item item;
			item.SetReference(std::string("PR_A") + std::to_string(ServiceItem().GetMaxId()));
			item.SetName(marshal_as<std::string>(this->textboxname->Text));
			item.SetAmount(std::stoi(marshal_as<std::string>(this->textboxlot->Text)));
			item.SetPriceExclTaxes(std::stof(marshal_as<std::string>(this->textBoxprice->Text)));

			item.SetVat(std::stof(marshal_as<std::string>((safe_cast<ComboboxItem^>(comboBoxvat->SelectedItem))->Value->ToString())));
			item.SetReduction(std::stof(marshal_as<std::string>((safe_cast<ComboboxItem^>(comboBoxreduction->SelectedItem))->Value->ToString())));
			item = ServiceItem().Add(item);

			Stock stock;
			stock.SetIdItem(item.GetId());
			stock.SetAmount(std::stoi(marshal_as<std::string>(this->textBoxstock->Text)));
			stock.SetReorderThreshold(std::stoi(marshal_as<std::string>(this->textBoxreorder->Text)));
			stock = ServiceStock().Add(stock);

			this->listener->onApplyClicked();
			this->Close();
		}
	}
};
}
