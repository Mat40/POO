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
	private: System::Windows::Forms::DataGridView^ EmployeeDataGridView;
	private: System::Windows::Forms::Button^ btnadd;
	private: System::Windows::Forms::Button^ btnupdate;
	private: System::Windows::Forms::Button^ btndelete;

	private: BB8Manager_Core_Services::ServiceEmployee^ serviceEmployee;
	private: System::Data::DataSet^ employeeDataSet;
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
			this->EmployeeDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->btnadd = (gcnew System::Windows::Forms::Button());
			this->btnupdate = (gcnew System::Windows::Forms::Button());
			this->btndelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EmployeeDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// EmployeeDataGridView
			// 
			this->EmployeeDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->EmployeeDataGridView->Location = System::Drawing::Point(373, 33);
			this->EmployeeDataGridView->Name = L"EmployeeDataGridView";
			this->EmployeeDataGridView->RowHeadersWidth = 51;
			this->EmployeeDataGridView->RowTemplate->Height = 24;
			this->EmployeeDataGridView->Size = System::Drawing::Size(628, 616);
			this->EmployeeDataGridView->TabIndex = 0;
			// 
			// btnadd
			// 
			this->btnadd->Location = System::Drawing::Point(93, 179);
			this->btnadd->Name = L"btnadd";
			this->btnadd->Size = System::Drawing::Size(179, 57);
			this->btnadd->TabIndex = 1;
			this->btnadd->Text = L"Add";
			this->btnadd->UseVisualStyleBackColor = true;
			// 
			// btnupdate
			// 
			this->btnupdate->Location = System::Drawing::Point(93, 282);
			this->btnupdate->Name = L"btnupdate";
			this->btnupdate->Size = System::Drawing::Size(179, 57);
			this->btnupdate->TabIndex = 2;
			this->btnupdate->Text = L"Update";
			this->btnupdate->UseVisualStyleBackColor = true;
			// 
			// btndelete
			// 
			this->btndelete->Location = System::Drawing::Point(93, 395);
			this->btndelete->Name = L"btndelete";
			this->btndelete->Size = System::Drawing::Size(179, 57);
			this->btndelete->TabIndex = 3;
			this->btndelete->Text = L"Delete";
			this->btndelete->UseVisualStyleBackColor = true;
			// 
			// EmployeeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 685);
			this->Controls->Add(this->btndelete);
			this->Controls->Add(this->btnupdate);
			this->Controls->Add(this->btnadd);
			this->Controls->Add(this->EmployeeDataGridView);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EmployeeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Employee";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->EmployeeDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
