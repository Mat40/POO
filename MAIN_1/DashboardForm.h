#pragma once
#include "ServiceOrder.h"
#include "ServiceCustomer.h"
#include "ServiceItem.h"
#include "AddStockForm.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Dashboard
	/// </summary>
	public ref class DashboardForm : public System::Windows::Forms::Form
	{
	public:
		DashboardForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//

			this->comboBox1->Items->Add(gcnew ComboboxItem("Janvier", 01));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Février", 02));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Mars", 03));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Avril", 04));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Mai", 05));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Juin", 06));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Juillet", 07));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Aout", 8));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Septembre", 9));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Octobre", 10));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Novembre", 11));
			this->comboBox1->Items->Add(gcnew ComboboxItem("Decembre", 12));

			this->comboBox2->Refresh();
			this->comboBox2->DataSource = BB8Manager_Core_Services::ServiceCustomer().GetDataSetCustomer()->Tables[0];
			this->comboBox2->DisplayMember = "Name";
			this->comboBox2->ValueMember = "ID";

			this->label4->Text = gcnew String(ServiceOrder().GetAvgPrice().c_str());
			this->label5->Text = gcnew String(ServiceOrder().GetStockPriceValueTTC().c_str());
			this->label6->Text = gcnew String(ServiceOrder().GetStockPriceValueHT().c_str());

			this->bunifuDataGridView1->Refresh();
			this->bunifuDataGridView1->DataSource = BB8Manager_Core_Services::ServiceItem().GetSoldOut();
			this->bunifuDataGridView1->DataMember = "Item";

			this->bunifuDataGridView2->Refresh();
			this->bunifuDataGridView2->DataSource = BB8Manager_Core_Services::ServiceItem().GetMostSold();
			this->bunifuDataGridView2->DataMember = "Item";

			this->bunifuDataGridView3->Refresh();
			this->bunifuDataGridView3->DataSource = BB8Manager_Core_Services::ServiceItem().GetLeastSold();
			this->bunifuDataGridView3->DataMember = "Item";
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~DashboardForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView1;
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView2;
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView3;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;


	protected:

	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->bunifuDataGridView2 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->bunifuDataGridView3 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView3))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(-14, -44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(347, 128);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Panier moyen : ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(-4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(338, 56);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Valeur du stock TTC :";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(-4, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(338, 56);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Valeur du stock HT : ";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label4->Location = System::Drawing::Point(528, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(159, 29);
			this->label4->TabIndex = 4;
			this->label4->Text = L"panier moyen";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label5->Location = System::Drawing::Point(838, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 29);
			this->label5->TabIndex = 5;
			this->label5->Text = L"stock TTC";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label6->Location = System::Drawing::Point(838, 73);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(108, 29);
			this->label6->TabIndex = 6;
			this->label6->Text = L"stock HT";
			// 
			// label7
			// 
			this->label7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label7->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->label7->Location = System::Drawing::Point(314, 396);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(276, 60);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Produit a reaprovisonner : ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label8->Location = System::Drawing::Point(340, 17);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 29);
			this->label8->TabIndex = 8;
			this->label8->Text = L"...";
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label9->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(0, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(334, 65);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Montant total des achats pour le client : ";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18));
			this->label11->Location = System::Drawing::Point(340, 36);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 29);
			this->label11->TabIndex = 14;
			this->label11->Text = L"...";
			// 
			// label12
			// 
			this->label12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label12->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->label12->Location = System::Drawing::Point(17, 9);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(272, 60);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Top 10 des produits les plus vendus";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label13->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->label13->Location = System::Drawing::Point(17, 281);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(276, 60);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Top 10 des produits les moins vendus";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(345, 0);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(130, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"Month to choose";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(345, 0);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(130, 21);
			this->comboBox2->TabIndex = 16;
			this->comboBox2->Text = L"User to choose";
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::DimGray;
			this->button1->Location = System::Drawing::Point(505, 0);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 32);
			this->button1->TabIndex = 17;
			this->button1->Text = L"APPLY";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DashboardForm::btnapply1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &DashboardForm::btnapply1_OnMouseEnter);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &DashboardForm::btnapply1_OnMouseLeave);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::DimGray;
			this->button2->Location = System::Drawing::Point(505, 0);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button1";
			this->button2->Size = System::Drawing::Size(82, 40);
			this->button2->TabIndex = 17;
			this->button2->Text = L"APPLY";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DashboardForm::btnapply2_Click);
			this->button2->MouseEnter += gcnew System::EventHandler(this, &DashboardForm::btnapply2_OnMouseEnter);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &DashboardForm::btnapply2_OnMouseLeave);
			// 
			// bunifuDataGridView1
			// 
			this->bunifuDataGridView1->AllowCustomTheming = true;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->bunifuDataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bunifuDataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bunifuDataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->bunifuDataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bunifuDataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->bunifuDataGridView1->ColumnHeadersHeight = 40;
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView1->CurrentTheme->AlternatingRowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->CurrentTheme->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->Name = nullptr;
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView1->CurrentTheme->RowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bunifuDataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->bunifuDataGridView1->EnableHeadersVisualStyles = false;
			this->bunifuDataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView1->HeaderBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView1->HeaderBgColor = System::Drawing::Color::Empty;
			this->bunifuDataGridView1->HeaderForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->Location = System::Drawing::Point(614, 355);
			this->bunifuDataGridView1->Name = L"bunifuDataGridView1";
			this->bunifuDataGridView1->RowHeadersVisible = false;
			this->bunifuDataGridView1->RowTemplate->Height = 40;
			this->bunifuDataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->bunifuDataGridView1->Size = System::Drawing::Size(276, 183);
			this->bunifuDataGridView1->TabIndex = 20;
			this->bunifuDataGridView1->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// bunifuDataGridView2
			// 
			this->bunifuDataGridView2->AllowCustomTheming = true;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle4;
			this->bunifuDataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bunifuDataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bunifuDataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->bunifuDataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bunifuDataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->bunifuDataGridView2->ColumnHeadersHeight = 40;
			this->bunifuDataGridView2->CurrentTheme->AlternatingRowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView2->CurrentTheme->AlternatingRowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView2->CurrentTheme->AlternatingRowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView2->CurrentTheme->AlternatingRowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView2->CurrentTheme->AlternatingRowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView2->CurrentTheme->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView2->CurrentTheme->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView2->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView2->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView2->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView2->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView2->CurrentTheme->HeaderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView2->CurrentTheme->Name = nullptr;
			this->bunifuDataGridView2->CurrentTheme->RowsStyle->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView2->CurrentTheme->RowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView2->CurrentTheme->RowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView2->CurrentTheme->RowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView2->CurrentTheme->RowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bunifuDataGridView2->DefaultCellStyle = dataGridViewCellStyle6;
			this->bunifuDataGridView2->EnableHeadersVisualStyles = false;
			this->bunifuDataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView2->HeaderBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView2->HeaderBgColor = System::Drawing::Color::Empty;
			this->bunifuDataGridView2->HeaderForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView2->Location = System::Drawing::Point(17, 72);
			this->bunifuDataGridView2->Name = L"bunifuDataGridView2";
			this->bunifuDataGridView2->RowHeadersVisible = false;
			this->bunifuDataGridView2->RowTemplate->Height = 40;
			this->bunifuDataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->bunifuDataGridView2->Size = System::Drawing::Size(263, 183);
			this->bunifuDataGridView2->TabIndex = 21;
			this->bunifuDataGridView2->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// bunifuDataGridView3
			// 
			this->bunifuDataGridView3->AllowCustomTheming = true;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle7;
			this->bunifuDataGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bunifuDataGridView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bunifuDataGridView3->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->bunifuDataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle8->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bunifuDataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle8;
			this->bunifuDataGridView3->ColumnHeadersHeight = 40;
			this->bunifuDataGridView3->CurrentTheme->AlternatingRowsStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView3->CurrentTheme->AlternatingRowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView3->CurrentTheme->AlternatingRowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView3->CurrentTheme->AlternatingRowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView3->CurrentTheme->AlternatingRowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView3->CurrentTheme->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView3->CurrentTheme->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView3->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView3->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView3->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView3->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView3->CurrentTheme->HeaderStyle->SelectionForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView3->CurrentTheme->Name = nullptr;
			this->bunifuDataGridView3->CurrentTheme->RowsStyle->BackColor = System::Drawing::Color::White;
			this->bunifuDataGridView3->CurrentTheme->RowsStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView3->CurrentTheme->RowsStyle->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView3->CurrentTheme->RowsStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView3->CurrentTheme->RowsStyle->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle9->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle9->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->bunifuDataGridView3->DefaultCellStyle = dataGridViewCellStyle9;
			this->bunifuDataGridView3->EnableHeadersVisualStyles = false;
			this->bunifuDataGridView3->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->bunifuDataGridView3->HeaderBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->bunifuDataGridView3->HeaderBgColor = System::Drawing::Color::Empty;
			this->bunifuDataGridView3->HeaderForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView3->Location = System::Drawing::Point(13, 355);
			this->bunifuDataGridView3->Name = L"bunifuDataGridView3";
			this->bunifuDataGridView3->RowHeadersVisible = false;
			this->bunifuDataGridView3->RowTemplate->Height = 40;
			this->bunifuDataGridView3->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->bunifuDataGridView3->Size = System::Drawing::Size(276, 183);
			this->bunifuDataGridView3->TabIndex = 22;
			this->bunifuDataGridView3->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(319, 9);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(589, 285);
			this->flowLayoutPanel1->TabIndex = 24;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(323, 117);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(585, 63);
			this->panel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(322, 62);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(586, 59);
			this->panel2->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(322, 9);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(586, 56);
			this->panel3->TabIndex = 0;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(232)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label10->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label10->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(-13, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(348, 49);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Chiffre d\'affaire sur le mois : ";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label10);
			this->panel4->Controls->Add(this->comboBox1);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Controls->Add(this->label8);
			this->panel4->Location = System::Drawing::Point(322, 180);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(586, 55);
			this->panel4->TabIndex = 25;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label9);
			this->panel5->Controls->Add(this->comboBox2);
			this->panel5->Controls->Add(this->button2);
			this->panel5->Controls->Add(this->label11);
			this->panel5->Location = System::Drawing::Point(322, 229);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(586, 65);
			this->panel5->TabIndex = 26;
			// 
			// DashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 557);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->bunifuDataGridView3);
			this->Controls->Add(this->bunifuDataGridView2);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->flowLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"DashboardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnapply1_Click(System::Object^ sender, System::EventArgs^ e) {
		int var_tampon;
		var_tampon = std::stoi(marshal_as <std::string>(safe_cast<ComboboxItem^>(comboBox1->SelectedItem)->Value->ToString()));
		this->label8->Text = gcnew String(ServiceOrder().GetTotalSalesPriceMonth(var_tampon).c_str());
	}
	private: System::Void btnapply1_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
			   this->button1->ForeColor = ColorTranslator::FromHtml("#fac755");
	}
	private: System::Void btnapply1_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
			this->button1->ForeColor = System::Drawing::Color::DimGray;
	}
	private: System::Void btnapply2_Click(System::Object^ sender, System::EventArgs^ e) {
		int var_tampon;
		var_tampon = std::stoi(marshal_as <std::string>(comboBox2->SelectedValue->ToString()));
		this->label11->Text = gcnew String(ServiceOrder().GetCustomerTotalSpend(var_tampon).c_str());
	}
	private: System::Void btnapply2_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->button2->ForeColor = ColorTranslator::FromHtml("#fac755");
	}
	private: System::Void btnapply2_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->button2->ForeColor = System::Drawing::Color::DimGray;
	}
};
}
