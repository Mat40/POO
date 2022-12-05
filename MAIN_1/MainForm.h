#pragma once
#include "CustomerForm.h"
#include "EmployeeForm.h"
#include "DashboardForm.h"
#include "StockForm.h"
#include "OrderForm.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Main
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	private: System::Windows::Forms::Timer^ timerpanelside;
	private: System::Windows::Forms::Panel^ panellogo;

	private: System::Windows::Forms::Panel^ panelbutton;

	private: System::Windows::Forms::Panel^ panelmenubtn;

	private: System::Windows::Forms::Button^ btnmenu;
	private: System::Windows::Forms::Button^ btnsettings;
	private: System::Windows::Forms::Button^ btnminimized;

	private: System::Windows::Forms::Button^ btnmaximized;

	public:

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

		bool sidebarExpend;

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
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ panelside;
	private: System::Windows::Forms::Panel^ panelheader;
	private: System::Windows::Forms::Panel^ mainpanel;
	private: System::Windows::Forms::Button^ btnstock;
	private: System::Windows::Forms::Button^ btnorder;
	private: System::Windows::Forms::Button^ btnemployee;
	private: System::Windows::Forms::Button^ btncustomer;
	private: System::Windows::Forms::Button^ btndashboard;
	private: System::Windows::Forms::Button^ btnclose;
	private: System::Windows::Forms::PictureBox^ pictureBoxLogo;
	private: System::ComponentModel::IContainer^ components;

	private: bool dragging;
	private: Point offset;

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->panelside = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panelmenubtn = (gcnew System::Windows::Forms::Panel());
			this->btnmenu = (gcnew System::Windows::Forms::Button());
			this->panelbutton = (gcnew System::Windows::Forms::Panel());
			this->btnsettings = (gcnew System::Windows::Forms::Button());
			this->btnstock = (gcnew System::Windows::Forms::Button());
			this->btnemployee = (gcnew System::Windows::Forms::Button());
			this->btndashboard = (gcnew System::Windows::Forms::Button());
			this->btncustomer = (gcnew System::Windows::Forms::Button());
			this->btnorder = (gcnew System::Windows::Forms::Button());
			this->panellogo = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxLogo = (gcnew System::Windows::Forms::PictureBox());
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnminimized = (gcnew System::Windows::Forms::Button());
			this->btnmaximized = (gcnew System::Windows::Forms::Button());
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->mainpanel = (gcnew System::Windows::Forms::Panel());
			this->timerpanelside = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelside->SuspendLayout();
			this->panelmenubtn->SuspendLayout();
			this->panelbutton->SuspendLayout();
			this->panellogo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->BeginInit();
			this->panelheader->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelside
			// 
			this->panelside->BackColor = System::Drawing::Color::DimGray;
			this->panelside->Controls->Add(this->panelmenubtn);
			this->panelside->Controls->Add(this->panelbutton);
			this->panelside->Controls->Add(this->panellogo);
			this->panelside->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelside->Location = System::Drawing::Point(0, 34);
			this->panelside->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelside->MaximumSize = System::Drawing::Size(251, 720);
			this->panelside->MinimumSize = System::Drawing::Size(53, 720);
			this->panelside->Name = L"panelside";
			this->panelside->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->panelside->Size = System::Drawing::Size(53, 720);
			this->panelside->TabIndex = 0;
			this->panelside->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			// 
			// panelmenubtn
			// 
			this->panelmenubtn->Controls->Add(this->btnmenu);
			this->panelmenubtn->Location = System::Drawing::Point(3, 2);
			this->panelmenubtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelmenubtn->Name = L"panelmenubtn";
			this->panelmenubtn->Size = System::Drawing::Size(247, 103);
			this->panelmenubtn->TabIndex = 0;
			// 
			// btnmenu
			// 
			this->btnmenu->BackColor = System::Drawing::Color::DimGray;
			this->btnmenu->FlatAppearance->BorderSize = 0;
			this->btnmenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnmenu->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F));
			this->btnmenu->ForeColor = System::Drawing::Color::White;
			this->btnmenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnmenu.Image")));
			this->btnmenu->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnmenu->Location = System::Drawing::Point(-3, 34);
			this->btnmenu->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnmenu->Name = L"btnmenu";
			this->btnmenu->Size = System::Drawing::Size(251, 37);
			this->btnmenu->TabIndex = 0;
			this->btnmenu->Text = L"MENU";
			this->btnmenu->UseVisualStyleBackColor = false;
			this->btnmenu->Click += gcnew System::EventHandler(this, &MainForm::btnmenu_Click);
			// 
			// panelbutton
			// 
			this->panelbutton->Controls->Add(this->btnsettings);
			this->panelbutton->Controls->Add(this->btnstock);
			this->panelbutton->Controls->Add(this->btnemployee);
			this->panelbutton->Controls->Add(this->btndashboard);
			this->panelbutton->Controls->Add(this->btncustomer);
			this->panelbutton->Controls->Add(this->btnorder);
			this->panelbutton->Location = System::Drawing::Point(3, 109);
			this->panelbutton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelbutton->Name = L"panelbutton";
			this->panelbutton->Size = System::Drawing::Size(247, 443);
			this->panelbutton->TabIndex = 1;
			// 
			// btnsettings
			// 
			this->btnsettings->BackColor = System::Drawing::Color::DimGray;
			this->btnsettings->FlatAppearance->BorderSize = 0;
			this->btnsettings->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnsettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnsettings->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnsettings->ForeColor = System::Drawing::Color::White;
			this->btnsettings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnsettings.Image")));
			this->btnsettings->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnsettings->Location = System::Drawing::Point(-3, 357);
			this->btnsettings->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnsettings->Name = L"btnsettings";
			this->btnsettings->Size = System::Drawing::Size(253, 37);
			this->btnsettings->TabIndex = 5;
			this->btnsettings->Text = L"SETTINGS";
			this->btnsettings->UseVisualStyleBackColor = false;
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
			this->btnstock->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnstock.Image")));
			this->btnstock->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnstock->Location = System::Drawing::Point(-3, 274);
			this->btnstock->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnstock->Name = L"btnstock";
			this->btnstock->Size = System::Drawing::Size(253, 37);
			this->btnstock->TabIndex = 4;
			this->btnstock->Text = L"STOCK";
			this->btnstock->UseVisualStyleBackColor = false;
			this->btnstock->Click += gcnew System::EventHandler(this, &MainForm::btnstock_Click);
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
			this->btnemployee->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnemployee.Image")));
			this->btnemployee->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnemployee->Location = System::Drawing::Point(-3, 185);
			this->btnemployee->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnemployee->Name = L"btnemployee";
			this->btnemployee->Size = System::Drawing::Size(253, 37);
			this->btnemployee->TabIndex = 2;
			this->btnemployee->Text = L"EMPLOYEE";
			this->btnemployee->UseVisualStyleBackColor = false;
			this->btnemployee->Click += gcnew System::EventHandler(this, &MainForm::btnemployee_Click);
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
			this->btndashboard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btndashboard.Image")));
			this->btndashboard->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btndashboard->Location = System::Drawing::Point(-3, 94);
			this->btndashboard->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btndashboard->Name = L"btndashboard";
			this->btndashboard->Size = System::Drawing::Size(253, 37);
			this->btndashboard->TabIndex = 0;
			this->btndashboard->Text = L"DASHBOARD";
			this->btndashboard->UseVisualStyleBackColor = false;
			this->btndashboard->Click += gcnew System::EventHandler(this, &MainForm::btndashboard_Click);
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
			this->btncustomer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btncustomer.Image")));
			this->btncustomer->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btncustomer->Location = System::Drawing::Point(-3, 139);
			this->btncustomer->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btncustomer->Name = L"btncustomer";
			this->btncustomer->Size = System::Drawing::Size(253, 37);
			this->btncustomer->TabIndex = 1;
			this->btncustomer->Text = L"CUSTOMER";
			this->btncustomer->UseVisualStyleBackColor = false;
			this->btncustomer->Click += gcnew System::EventHandler(this, &MainForm::btncustomer_Click);
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
			this->btnorder->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnorder.Image")));
			this->btnorder->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnorder->Location = System::Drawing::Point(-3, 229);
			this->btnorder->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnorder->Name = L"btnorder";
			this->btnorder->Size = System::Drawing::Size(253, 37);
			this->btnorder->TabIndex = 3;
			this->btnorder->Text = L"ORDER";
			this->btnorder->UseVisualStyleBackColor = false;
			this->btnorder->Click += gcnew System::EventHandler(this, &MainForm::btnorder_Click);
			// 
			// panellogo
			// 
			this->panellogo->Controls->Add(this->pictureBoxLogo);
			this->panellogo->Location = System::Drawing::Point(3, 556);
			this->panellogo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panellogo->Name = L"panellogo";
			this->panellogo->Size = System::Drawing::Size(247, 121);
			this->panellogo->TabIndex = 0;
			// 
			// pictureBoxLogo
			// 
			this->pictureBoxLogo->InitialImage = nullptr;
			this->pictureBoxLogo->Location = System::Drawing::Point(49, 0);
			this->pictureBoxLogo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBoxLogo->Name = L"pictureBoxLogo";
			this->pictureBoxLogo->Size = System::Drawing::Size(144, 121);
			this->pictureBoxLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxLogo->TabIndex = 5;
			this->pictureBoxLogo->TabStop = false;
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::DimGray;
			this->panelheader->Controls->Add(this->btnminimized);
			this->panelheader->Controls->Add(this->btnmaximized);
			this->panelheader->Controls->Add(this->btnclose);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(0, 0);
			this->panelheader->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(1280, 34);
			this->panelheader->TabIndex = 1;
			this->panelheader->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->panelheader->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->panelheader->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// btnminimized
			// 
			this->btnminimized->BackColor = System::Drawing::Color::DimGray;
			this->btnminimized->FlatAppearance->BorderSize = 0;
			this->btnminimized->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->btnminimized->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnminimized->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnminimized->ForeColor = System::Drawing::Color::White;
			this->btnminimized->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnminimized.Image")));
			this->btnminimized->Location = System::Drawing::Point(1168, 0);
			this->btnminimized->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnminimized->Name = L"btnminimized";
			this->btnminimized->Size = System::Drawing::Size(37, 34);
			this->btnminimized->TabIndex = 7;
			this->btnminimized->UseVisualStyleBackColor = false;
			this->btnminimized->Click += gcnew System::EventHandler(this, &MainForm::btnminimized_Click);
			// 
			// btnmaximized
			// 
			this->btnmaximized->BackColor = System::Drawing::Color::DimGray;
			this->btnmaximized->FlatAppearance->BorderSize = 0;
			this->btnmaximized->FlatAppearance->MouseOverBackColor = System::Drawing::Color::DimGray;
			this->btnmaximized->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnmaximized->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnmaximized->ForeColor = System::Drawing::Color::White;
			this->btnmaximized->Location = System::Drawing::Point(1205, 0);
			this->btnmaximized->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnmaximized->Name = L"btnmaximized";
			this->btnmaximized->Size = System::Drawing::Size(37, 34);
			this->btnmaximized->TabIndex = 6;
			this->btnmaximized->UseVisualStyleBackColor = false;
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
			this->btnclose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnclose.Image")));
			this->btnclose->Location = System::Drawing::Point(1243, 0);
			this->btnclose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(37, 34);
			this->btnclose->TabIndex = 5;
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &MainForm::btnclose_Click);
			// 
			// mainpanel
			// 
			this->mainpanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->mainpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpanel->Location = System::Drawing::Point(53, 34);
			this->mainpanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->mainpanel->Name = L"mainpanel";
			this->mainpanel->Size = System::Drawing::Size(1227, 686);
			this->mainpanel->TabIndex = 2;
			// 
			// timerpanelside
			// 
			this->timerpanelside->Interval = 10;
			this->timerpanelside->Tick += gcnew System::EventHandler(this, &MainForm::timerpanelside_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->mainpanel);
			this->Controls->Add(this->panelside);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainForm";
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &MainForm::Main_Load);
			this->panelside->ResumeLayout(false);
			this->panelmenubtn->ResumeLayout(false);
			this->panelbutton->ResumeLayout(false);
			this->panellogo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLogo))->EndInit();
			this->panelheader->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
	/// Movable Window
	/// </summary>

	private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		this->dragging = false;
	}

	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew DashboardForm());
		resetButtons_Click();
		allButtons_Click(this->btndashboard);
		this->pictureBoxLogo->ImageLocation = "C:/Users/matth/OneDrive/Bureau/CESI/2ème année/POO/Livrable 1/VH4.png"; //path to image
		this->dragging = false;
	}
	private: System::Void customerToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void employeeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void btndashboard_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew DashboardForm());
		resetButtons_Click();
		allButtons_Click(this->btndashboard);
	}
	private: System::Void btncustomer_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew CustomerForm());
		resetButtons_Click();
		allButtons_Click(this->btncustomer);
	}
	private: System::Void btnemployee_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew EmployeeForm());
		resetButtons_Click();
		allButtons_Click(this->btnemployee);
	}
	private: System::Void btnorder_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew OrderForm());
		resetButtons_Click();
		allButtons_Click(this->btnorder);
	}
	private: System::Void btnstock_Click(System::Object^ sender, System::EventArgs^ e) {
		loadform(gcnew StockForm());
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

	private: System::Void timerpanelside_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (sidebarExpend) {
			this->panelside->Width -= 10;
			if (this->panelside->Width == this->panelside->MinimumSize.Width) {
				sidebarExpend = false;
				this->timerpanelside->Stop();
			}
		}
		else {
			this->panelside->Width += 10;
			if (this->panelside->Width == this->panelside->MaximumSize.Width) {
				sidebarExpend = true;
				this->timerpanelside->Stop();
			}
		}
	}
	private: System::Void btnmenu_Click(System::Object^ sender, System::EventArgs^ e) {
		this->timerpanelside->Start();
	}
	private: System::Void btnminimized_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Minimized;
	}
	};
}