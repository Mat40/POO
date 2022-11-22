#pragma once

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Stock
	/// </summary>
	public ref class StockForm : public System::Windows::Forms::Form
	{
	public:
		StockForm(void)
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
		~StockForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelstock;
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
			this->labelstock = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelstock
			// 
			this->labelstock->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->labelstock->AutoSize = true;
			this->labelstock->Location = System::Drawing::Point(465, 334);
			this->labelstock->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelstock->Name = L"labelstock";
			this->labelstock->Size = System::Drawing::Size(52, 16);
			this->labelstock->TabIndex = 1;
			this->labelstock->Text = L"STOCK";
			// 
			// Stock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 685);
			this->Controls->Add(this->labelstock);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Stock";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stock";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
