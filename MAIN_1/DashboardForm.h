#pragma once
#include "ServiceOrder.h"
#include <typeinfo>
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

			this->label4->Text = gcnew String(ServiceOrder().avg_ordered().c_str());
			this->label5->Text = gcnew String(ServiceOrder().panier_TTC().c_str());
			this->label6->Text = gcnew String(ServiceOrder().panier_HT().c_str());
			this->label8->Text = gcnew String(ServiceOrder().reaprovisionnement().c_str()); // metrre tout les produits tableau

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
	private: System::Windows::Forms::Label^ labeldashboard;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label11;



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
			this->labeldashboard = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labeldashboard
			// 
			this->labeldashboard->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labeldashboard->AutoSize = true;
			this->labeldashboard->Location = System::Drawing::Point(390, 33);
			this->labeldashboard->Name = L"labeldashboard";
			this->labeldashboard->Size = System::Drawing::Size(75, 13);
			this->labeldashboard->TabIndex = 0;
			this->labeldashboard->Text = L"DASHBOARD";
			this->labeldashboard->Click += gcnew System::EventHandler(this, &DashboardForm::labeldashboard_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(278, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Panier moyen : ";
			this->label1->Click += gcnew System::EventHandler(this, &DashboardForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(250, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Valeur du stock TTC :";
			this->label2->Click += gcnew System::EventHandler(this, &DashboardForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(250, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Valeur du stock HT : ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(497, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 4;
			this->label4->Click += gcnew System::EventHandler(this, &DashboardForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(497, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 5;
			this->label5->Click += gcnew System::EventHandler(this, &DashboardForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(500, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 6;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(230, 206);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(131, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Produit a reaprovisonner : ";
			this->label7->Click += gcnew System::EventHandler(this, &DashboardForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(406, 260);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 8;
			this->label8->Click += gcnew System::EventHandler(this, &DashboardForm::label8_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(220, 260);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(138, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Chiffre d\'affaire sur le mois : ";
			this->label10->Click += gcnew System::EventHandler(this, &DashboardForm::label10_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(364, 257);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"Month to choose";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &DashboardForm::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(538, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DashboardForm::button1_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(377, 366);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 14;
			// 
			// DashboardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 557);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labeldashboard);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"DashboardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labeldashboard_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int var_tampon;
		var_tampon = std::stoi ( marshal_as <std::string>(safe_cast<ComboboxItem^>(comboBox1->SelectedItem)->Value->ToString()));
		this->label11->Text = gcnew String(ServiceOrder().vente_mois(var_tampon).c_str());

	}
	};
}
