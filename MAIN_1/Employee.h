#pragma once

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
	public ref class Employee : public System::Windows::Forms::Form
	{
	public:
		Employee(void)
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
		~Employee()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelemployee;
	protected:

	protected:

	protected:

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
			this->labelemployee = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelemployee
			// 
			this->labelemployee->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelemployee->AutoSize = true;
			this->labelemployee->Location = System::Drawing::Point(441, 256);
			this->labelemployee->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelemployee->Name = L"labelemployee";
			this->labelemployee->Size = System::Drawing::Size(80, 16);
			this->labelemployee->TabIndex = 1;
			this->labelemployee->Text = L"EMPLOYEE";
			// 
			// Employee
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1040, 554);
			this->Controls->Add(this->labelemployee);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Employee";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Employee";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
