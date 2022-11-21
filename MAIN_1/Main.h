#pragma once
#include "Customer.h"
#include "Employee.h"
#include "Dashboard.h"
#include "Stock.h"
#include "Order.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		//void loadform(System::Object^ Form) {
		//	if (this->mainpanel->Controls->Count > 0) {
		//		this->mainpanel->Controls->RemoveAt(0);
		//	}
		//	System::Windows::Forms::Form^ f = gcnew System::Windows::Forms::Form();
		//	f->TopLevel = false;
		//	f->Dock = DockStyle::Fill;
		//	this->mainpanel->Controls->Add(f);
		//	this->mainpanel->Tag = f;
		//	f->Show();
		//}

		void loadform(System::Windows::Forms::Form^ form) {
			if (this->mainpanel->Controls->Count > 0) {
				this->mainpanel->Controls->RemoveAt(0);
			}

			form->TopLevel = false;
			form->Dock = DockStyle::Fill;
			this->mainpanel->Controls->Add(form);
			this->mainpanel->Tag = form;
			form->Show();
		}

		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelside;
	private: System::Windows::Forms::Panel^ panelheader;
	private: System::Windows::Forms::Panel^ mainpanel;
	private: System::Windows::Forms::Button^ btnstock;
	private: System::Windows::Forms::Button^ btnorder;
	private: System::Windows::Forms::Button^ btnemployee;
	private: System::Windows::Forms::Button^ btncustomer;
	private: System::Windows::Forms::Button^ btndashboard;
	private: System::Windows::Forms::Button^ btnclose;
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
			this->panelside = (gcnew System::Windows::Forms::Panel());
			this->btnstock = (gcnew System::Windows::Forms::Button());
			this->btndashboard = (gcnew System::Windows::Forms::Button());
			this->btnorder = (gcnew System::Windows::Forms::Button());
			this->btncustomer = (gcnew System::Windows::Forms::Button());
			this->btnemployee = (gcnew System::Windows::Forms::Button());
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->mainpanel = (gcnew System::Windows::Forms::Panel());
			this->panelside->SuspendLayout();
			this->panelheader->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelside
			// 
			this->panelside->BackColor = System::Drawing::Color::DimGray;
			this->panelside->Controls->Add(this->btnstock);
			this->panelside->Controls->Add(this->btndashboard);
			this->panelside->Controls->Add(this->btnorder);
			this->panelside->Controls->Add(this->btncustomer);
			this->panelside->Controls->Add(this->btnemployee);
			this->panelside->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelside->Location = System::Drawing::Point(0, 37);
			this->panelside->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelside->Name = L"panelside";
			this->panelside->Size = System::Drawing::Size(267, 574);
			this->panelside->TabIndex = 0;
			this->panelside->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::panel1_Paint);
			// 
			// btnstock
			// 
			this->btnstock->BackColor = System::Drawing::Color::DimGray;
			this->btnstock->FlatAppearance->BorderSize = 0;
			this->btnstock->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnstock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnstock->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnstock->ForeColor = System::Drawing::Color::White;
			this->btnstock->Location = System::Drawing::Point(0, 340);
			this->btnstock->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnstock->Name = L"btnstock";
			this->btnstock->Size = System::Drawing::Size(267, 37);
			this->btnstock->TabIndex = 4;
			this->btnstock->Text = L"Stock";
			this->btnstock->UseVisualStyleBackColor = false;
			this->btnstock->Click += gcnew System::EventHandler(this, &Main::btnstock_Click);
			// 
			// btndashboard
			// 
			this->btndashboard->BackColor = System::Drawing::Color::DimGray;
			this->btndashboard->FlatAppearance->BorderSize = 0;
			this->btndashboard->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btndashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btndashboard->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btndashboard->ForeColor = System::Drawing::Color::White;
			this->btndashboard->Location = System::Drawing::Point(0, 162);
			this->btndashboard->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btndashboard->Name = L"btndashboard";
			this->btndashboard->Size = System::Drawing::Size(267, 37);
			this->btndashboard->TabIndex = 0;
			this->btndashboard->Text = L"Dashboard";
			this->btndashboard->UseVisualStyleBackColor = false;
			this->btndashboard->Click += gcnew System::EventHandler(this, &Main::btndashboard_Click);
			// 
			// btnorder
			// 
			this->btnorder->BackColor = System::Drawing::Color::DimGray;
			this->btnorder->FlatAppearance->BorderSize = 0;
			this->btnorder->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnorder->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnorder->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnorder->ForeColor = System::Drawing::Color::White;
			this->btnorder->Location = System::Drawing::Point(0, 295);
			this->btnorder->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnorder->Name = L"btnorder";
			this->btnorder->Size = System::Drawing::Size(267, 37);
			this->btnorder->TabIndex = 3;
			this->btnorder->Text = L"Order";
			this->btnorder->UseVisualStyleBackColor = false;
			this->btnorder->Click += gcnew System::EventHandler(this, &Main::btnorder_Click);
			// 
			// btncustomer
			// 
			this->btncustomer->BackColor = System::Drawing::Color::DimGray;
			this->btncustomer->FlatAppearance->BorderSize = 0;
			this->btncustomer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btncustomer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncustomer->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btncustomer->ForeColor = System::Drawing::Color::White;
			this->btncustomer->Location = System::Drawing::Point(0, 207);
			this->btncustomer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btncustomer->Name = L"btncustomer";
			this->btncustomer->Size = System::Drawing::Size(267, 37);
			this->btncustomer->TabIndex = 1;
			this->btncustomer->Text = L"Customer";
			this->btncustomer->UseVisualStyleBackColor = false;
			this->btncustomer->Click += gcnew System::EventHandler(this, &Main::btncustomer_Click);
			// 
			// btnemployee
			// 
			this->btnemployee->BackColor = System::Drawing::Color::DimGray;
			this->btnemployee->FlatAppearance->BorderSize = 0;
			this->btnemployee->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnemployee->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnemployee->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnemployee->ForeColor = System::Drawing::Color::White;
			this->btnemployee->Location = System::Drawing::Point(0, 251);
			this->btnemployee->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnemployee->Name = L"btnemployee";
			this->btnemployee->Size = System::Drawing::Size(267, 37);
			this->btnemployee->TabIndex = 2;
			this->btnemployee->Text = L"Employee";
			this->btnemployee->UseVisualStyleBackColor = false;
			this->btnemployee->Click += gcnew System::EventHandler(this, &Main::btnemployee_Click);
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::DimGray;
			this->panelheader->Controls->Add(this->btnclose);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(0, 0);
			this->panelheader->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(1131, 37);
			this->panelheader->TabIndex = 1;
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
			this->btnclose->Location = System::Drawing::Point(1091, 0);
			this->btnclose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(40, 37);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"X";
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &Main::btnclose_Click);
			// 
			// mainpanel
			// 
			this->mainpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpanel->Location = System::Drawing::Point(267, 37);
			this->mainpanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->mainpanel->Name = L"mainpanel";
			this->mainpanel->Size = System::Drawing::Size(864, 574);
			this->mainpanel->TabIndex = 2;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1131, 611);
			this->Controls->Add(this->mainpanel);
			this->Controls->Add(this->panelside);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Main";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->panelside->ResumeLayout(false);
			this->panelheader->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Dashboard());
		resetButtons_Click();
		allButtons_Click(this->btndashboard);
	}
	private: System::Void customerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void employeeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btndashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Dashboard());
		resetButtons_Click();
		allButtons_Click(this->btndashboard);
	}
	private: System::Void btncustomer_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Customer());
		resetButtons_Click();
		allButtons_Click(this->btncustomer);
	}
	private: System::Void btnemployee_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Employee());
		resetButtons_Click();
		allButtons_Click(this->btnemployee);
	}
	private: System::Void btnorder_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Order());
		resetButtons_Click();
		allButtons_Click(this->btnorder);
	}
	private: System::Void btnstock_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew Stock());
		resetButtons_Click();
		allButtons_Click(this->btnstock);
	}
	private: System::Void btnclose_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void resetButtons_Click()
	{
		this->btndashboard->BackColor = Color::DimGray;
		this->btncustomer->BackColor = Color::DimGray;
		this->btnemployee->BackColor = Color::DimGray;
		this->btnorder->BackColor = Color::DimGray;
		this->btnstock->BackColor = Color::DimGray;
	}
	private: System::Void allButtons_Click(System::Windows::Forms::Button^ senderBtn)
	{
		senderBtn->BackColor = Color::Gray;
	}
};
}
