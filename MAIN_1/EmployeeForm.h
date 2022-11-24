#pragma once

#include "ServiceEmployee.h"

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Employee
	/// </summary>
	public ref class EmployeeForm : public System::Windows::Forms::Form
	{
	public:
		EmployeeForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~EmployeeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: Bunifu::UI::WinForms::BunifuDataGridView^ bunifuDataGridView1;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bunifuDataGridView1 = (gcnew Bunifu::UI::WinForms::BunifuDataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 541);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(233, 116);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EmployeeForm::button1_Click);
			// 
			// bunifuDataGridView1
			// 
			this->bunifuDataGridView1->AllowCustomTheming = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->bunifuDataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->bunifuDataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bunifuDataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bunifuDataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->bunifuDataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::DodgerBlue;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->bunifuDataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->bunifuDataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
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
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->BackColor = System::Drawing::Color::DodgerBlue;
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.75F, System::Drawing::FontStyle::Bold));
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->ForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->CurrentTheme->HeaderStyle->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(204)));
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
			this->bunifuDataGridView1->HeaderBackColor = System::Drawing::Color::DodgerBlue;
			this->bunifuDataGridView1->HeaderBgColor = System::Drawing::Color::Empty;
			this->bunifuDataGridView1->HeaderForeColor = System::Drawing::Color::White;
			this->bunifuDataGridView1->Location = System::Drawing::Point(144, 75);
			this->bunifuDataGridView1->Name = L"bunifuDataGridView1";
			this->bunifuDataGridView1->RowHeadersVisible = false;
			this->bunifuDataGridView1->RowHeadersWidth = 51;
			this->bunifuDataGridView1->RowTemplate->Height = 40;
			this->bunifuDataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->bunifuDataGridView1->Size = System::Drawing::Size(705, 271);
			this->bunifuDataGridView1->TabIndex = 2;
			this->bunifuDataGridView1->Theme = Bunifu::UI::WinForms::BunifuDataGridView::PresetThemes::Light;
			// 
			// EmployeeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1029, 686);
			this->Controls->Add(this->bunifuDataGridView1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EmployeeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Employee";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuDataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->bunifuDataGridView1->Refresh();
		this->bunifuDataGridView1->DataSource = ServiceEmployee().GetDataSet();
		this->bunifuDataGridView1->DataMember = "Employee";
	}
	};
}
