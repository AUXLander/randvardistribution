#pragma once

#include "Actions.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Histogramm : public System::Windows::Forms::Form
	{
	public:
		System::Collections::Generic::List<System::String^>^ list = gcnew System::Collections::Generic::List<System::String^>();

		Histogramm(void)
		{
			InitializeComponent();
		}

	protected:
		~Histogramm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ MainChart;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ selectBox;
	private: System::Windows::Forms::Button^ loadBtn;
	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->MainChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->selectBox = (gcnew System::Windows::Forms::ComboBox());
			this->loadBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainChart))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->MainChart->ChartAreas->Add(chartArea1);
			this->MainChart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainChart->Location = System::Drawing::Point(3, 16);
			this->MainChart->Margin = System::Windows::Forms::Padding(0);
			this->MainChart->Name = L"MainChart";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Series1";
			this->MainChart->Series->Add(series1);
			this->MainChart->Size = System::Drawing::Size(655, 522);
			this->MainChart->TabIndex = 0;
			this->MainChart->Text = L"Histogramm";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->MainChart);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox1->Location = System::Drawing::Point(0, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(661, 541);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Гистограмма";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->Controls->Add(this->selectBox);
			this->panel1->Controls->Add(this->loadBtn);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->MaximumSize = System::Drawing::Size(0, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(661, 45);
			this->panel1->TabIndex = 2;
			// 
			// selectBox
			// 
			this->selectBox->DisplayMember = L"0";
			this->selectBox->FormattingEnabled = true;
			this->selectBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Равномерное распределение", L"Пуассоновское распределение",
					L"Нормальное стандартное распределение"
			});
			this->selectBox->Location = System::Drawing::Point(12, 12);
			this->selectBox->Name = L"selectBox";
			this->selectBox->Size = System::Drawing::Size(559, 21);
			this->selectBox->TabIndex = 1;
			this->selectBox->ValueMember = L"0";
			// 
			// loadBtn
			// 
			this->loadBtn->Location = System::Drawing::Point(577, 10);
			this->loadBtn->Name = L"loadBtn";
			this->loadBtn->Size = System::Drawing::Size(72, 25);
			this->loadBtn->TabIndex = 0;
			this->loadBtn->Text = L"load";
			this->loadBtn->UseVisualStyleBackColor = true;
			this->loadBtn->Click += gcnew System::EventHandler(this, &Histogramm::loadBtn_Click);
			// 
			// Histogramm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(661, 592);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Histogramm";
			this->Text = L"Histogramm";
			this->Load += gcnew System::EventHandler(this, &Histogramm::Histogramm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MainChart))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Histogramm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		Init(this->selectBox);
	}
	private: System::Void loadBtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		LoadData(this->selectBox, this->MainChart);
	}
};
}
