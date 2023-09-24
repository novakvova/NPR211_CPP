#pragma once

namespace My11UIForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtOne;
	private: System::Windows::Forms::TextBox^ txtTwo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnPlus;
	private: System::Windows::Forms::Label^ lbResult;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtOne = (gcnew System::Windows::Forms::TextBox());
			this->txtTwo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->lbResult = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtOne
			// 
			this->txtOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtOne->Location = System::Drawing::Point(27, 27);
			this->txtOne->Name = L"txtOne";
			this->txtOne->Size = System::Drawing::Size(100, 38);
			this->txtOne->TabIndex = 1;
			// 
			// txtTwo
			// 
			this->txtTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtTwo->Location = System::Drawing::Point(216, 27);
			this->txtTwo->Name = L"txtTwo";
			this->txtTwo->Size = System::Drawing::Size(100, 38);
			this->txtTwo->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(144, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 31);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Op";
			// 
			// btnPlus
			// 
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPlus->Location = System::Drawing::Point(139, 77);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(65, 43);
			this->btnPlus->TabIndex = 4;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = true;
			this->btnPlus->Click += gcnew System::EventHandler(this, &MainForm::btnPlus_Click);
			// 
			// lbResult
			// 
			this->lbResult->AutoSize = true;
			this->lbResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbResult->ForeColor = System::Drawing::Color::Red;
			this->lbResult->Location = System::Drawing::Point(21, 285);
			this->lbResult->Name = L"lbResult";
			this->lbResult->Size = System::Drawing::Size(0, 33);
			this->lbResult->TabIndex = 5;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 336);
			this->Controls->Add(this->lbResult);
			this->Controls->Add(this->btnPlus);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtTwo);
			this->Controls->Add(this->txtOne);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnPlus_Click(System::Object^ sender, System::EventArgs^ e) {

		int a = System::Convert::ToInt32(txtOne->Text);
		int b = System::Convert::ToInt32(txtTwo->Text);
		lbResult->Text = System::Convert::ToString(a+b);
	}
};
}
