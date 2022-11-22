#pragma once

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Customer
	/// </summary>
	public ref class CustomerForm : public System::Windows::Forms::Form
	{
	public:
		CustomerForm(void)
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
		~CustomerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelcustomer;
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
			this->labelcustomer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelcustomer
			// 
			this->labelcustomer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelcustomer->AutoSize = true;
			this->labelcustomer->Location = System::Drawing::Point(465, 334);
			this->labelcustomer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelcustomer->Name = L"labelcustomer";
			this->labelcustomer->Size = System::Drawing::Size(84, 16);
			this->labelcustomer->TabIndex = 1;
			this->labelcustomer->Text = L"CUSTOMER";
			// 
			// Customer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 685);
			this->Controls->Add(this->labelcustomer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Customer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Customer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	};
}
