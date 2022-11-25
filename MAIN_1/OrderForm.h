#pragma once

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Order
	/// </summary>
	public ref class OrderForm : public System::Windows::Forms::Form
	{
	public:
		OrderForm(void)
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
		~OrderForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelorder;
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
			this->labelorder = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelorder
			// 
			this->labelorder->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelorder->AutoSize = true;
			this->labelorder->Location = System::Drawing::Point(589, 335);
			this->labelorder->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelorder->Name = L"labelorder";
			this->labelorder->Size = System::Drawing::Size(56, 16);
			this->labelorder->TabIndex = 1;
			this->labelorder->Text = L"ORDER";
			// 
			// OrderForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1227, 686);
			this->Controls->Add(this->labelorder);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"OrderForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Order";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
