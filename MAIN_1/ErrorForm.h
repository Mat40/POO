#pragma once
#include <string>

namespace MAIN1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de ErrorForm
	/// </summary>
	public ref class ErrorForm : public System::Windows::Forms::Form
	{
	public:
		ErrorForm(std::string text)
		{
			InitializeComponent();
			this->textBoxerror->Text = gcnew String(text.c_str());
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ErrorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnclose;
	protected:
	private: System::Windows::Forms::Panel^ panelheader;
	private: System::Windows::Forms::Button^ btnok;
	private: System::Windows::Forms::Button^ btnhelp;
	private: System::Windows::Forms::TextBox^ textBoxerror;

	
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
			this->btnclose = (gcnew System::Windows::Forms::Button());
			this->panelheader = (gcnew System::Windows::Forms::Panel());
			this->btnok = (gcnew System::Windows::Forms::Button());
			this->btnhelp = (gcnew System::Windows::Forms::Button());
			this->textBoxerror = (gcnew System::Windows::Forms::TextBox());
			this->panelheader->SuspendLayout();
			this->SuspendLayout();
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
			this->btnclose->Location = System::Drawing::Point(413, 0);
			this->btnclose->Margin = System::Windows::Forms::Padding(4);
			this->btnclose->Name = L"btnclose";
			this->btnclose->Size = System::Drawing::Size(37, 34);
			this->btnclose->TabIndex = 5;
			this->btnclose->Text = L"X";
			this->btnclose->UseVisualStyleBackColor = false;
			this->btnclose->Click += gcnew System::EventHandler(this, &ErrorForm::btnclose_Click);
			// 
			// panelheader
			// 
			this->panelheader->BackColor = System::Drawing::Color::DimGray;
			this->panelheader->Controls->Add(this->btnclose);
			this->panelheader->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelheader->Location = System::Drawing::Point(0, 0);
			this->panelheader->Margin = System::Windows::Forms::Padding(4);
			this->panelheader->Name = L"panelheader";
			this->panelheader->Size = System::Drawing::Size(450, 37);
			this->panelheader->TabIndex = 3;
			// 
			// btnok
			// 
			this->btnok->FlatAppearance->BorderSize = 0;
			this->btnok->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnok->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnok->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnok->ForeColor = System::Drawing::Color::DimGray;
			this->btnok->Location = System::Drawing::Point(335, 208);
			this->btnok->Name = L"btnok";
			this->btnok->Size = System::Drawing::Size(103, 30);
			this->btnok->TabIndex = 4;
			this->btnok->Text = L"CLOSE";
			this->btnok->UseVisualStyleBackColor = true;
			this->btnok->Click += gcnew System::EventHandler(this, &ErrorForm::btnok_Click);
			this->btnok->MouseEnter += gcnew System::EventHandler(this, &ErrorForm::btnok_OnMouseEnter);
			this->btnok->MouseLeave += gcnew System::EventHandler(this, &ErrorForm::btnok_OnMouseLeave);
			// 
			// btnhelp
			// 
			this->btnhelp->FlatAppearance->BorderSize = 0;
			this->btnhelp->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->btnhelp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnhelp->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->btnhelp->ForeColor = System::Drawing::Color::DimGray;
			this->btnhelp->Location = System::Drawing::Point(12, 208);
			this->btnhelp->Name = L"btnhelp";
			this->btnhelp->Size = System::Drawing::Size(103, 30);
			this->btnhelp->TabIndex = 5;
			this->btnhelp->Text = L"HELP";
			this->btnhelp->UseVisualStyleBackColor = true;
			this->btnhelp->MouseEnter += gcnew System::EventHandler(this, &ErrorForm::btnhelp_OnMouseEnter);
			this->btnhelp->MouseLeave += gcnew System::EventHandler(this, &ErrorForm::btnhelp_OnMouseLeave);
			// 
			// textBoxerror
			// 
			this->textBoxerror->AcceptsReturn = true;
			this->textBoxerror->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxerror->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBoxerror->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->textBoxerror->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->textBoxerror->Location = System::Drawing::Point(35, 75);
			this->textBoxerror->Multiline = true;
			this->textBoxerror->Name = L"textBoxerror";
			this->textBoxerror->ReadOnly = true;
			this->textBoxerror->Size = System::Drawing::Size(380, 90);
			this->textBoxerror->TabIndex = 6;
			// 
			// ErrorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 250);
			this->Controls->Add(this->textBoxerror);
			this->Controls->Add(this->btnhelp);
			this->Controls->Add(this->btnok);
			this->Controls->Add(this->panelheader);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ErrorForm";
			this->Text = L"ErrorForm";
			this->panelheader->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnok_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnclose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnok_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btnok->ForeColor = ColorTranslator::FromHtml("#fac755");
	}

	private: System::Void btnok_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btnok->ForeColor = System::Drawing::Color::DimGray;
	}

	private: System::Void btnhelp_OnMouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btnhelp->ForeColor = ColorTranslator::FromHtml("#fac755");
	}

	private: System::Void btnhelp_OnMouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btnhelp->ForeColor = System::Drawing::Color::DimGray;
	}
};
}
