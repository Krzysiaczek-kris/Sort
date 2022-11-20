#pragma once
#include <vector>
#include <list>

using namespace std;

extern int ptc;
extern int ptc2;
extern int sleep;
extern bool cancelled;


namespace Sort {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->comboBox_sort->SelectedIndex = 0;
			this->textBox_n->Text = "100";
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Generate;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ Sort;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	public: System::Data::DataSet^ dataSet1;
		
	public: System::Data::DataTable^ dataTable1;
	private: System::Data::DataColumn^ dataColumn1;
	private: System::Windows::Forms::Label^ label_method;
	private: System::Windows::Forms::ComboBox^ comboBox_sort;
	private: System::Windows::Forms::Button^ button_Cancel;

	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::Button^ button_Save;
	private: System::Windows::Forms::TextBox^ textBox_n;
	private: System::Windows::Forms::Label^ label_n;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = ( gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea() );
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = ( gcnew System::Windows::Forms::DataVisualization::Charting::Legend() );
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = ( gcnew System::Windows::Forms::DataVisualization::Charting::Series() );
			System::ComponentModel::ComponentResourceManager^ resources = ( gcnew System::ComponentModel::ComponentResourceManager( MyForm::typeid ) );
			this->Generate = ( gcnew System::Windows::Forms::Button() );
			this->chart1 = ( gcnew System::Windows::Forms::DataVisualization::Charting::Chart() );
			this->dataSet1 = ( gcnew System::Data::DataSet() );
			this->dataTable1 = ( gcnew System::Data::DataTable() );
			this->dataColumn1 = ( gcnew System::Data::DataColumn() );
			this->Sort = ( gcnew System::Windows::Forms::Button() );
			this->backgroundWorker1 = ( gcnew System::ComponentModel::BackgroundWorker() );
			this->label_method = ( gcnew System::Windows::Forms::Label() );
			this->comboBox_sort = ( gcnew System::Windows::Forms::ComboBox() );
			this->button_Cancel = ( gcnew System::Windows::Forms::Button() );
			this->button_load = ( gcnew System::Windows::Forms::Button() );
			this->button_Save = ( gcnew System::Windows::Forms::Button() );
			this->textBox_n = ( gcnew System::Windows::Forms::TextBox() );
			this->label_n = ( gcnew System::Windows::Forms::Label() );
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->chart1 ) )->BeginInit();
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataSet1 ) )->BeginInit();
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataTable1 ) )->BeginInit();
			this->SuspendLayout();
			// 
			// Generate
			// 
			this->Generate->Location = System::Drawing::Point( 526, 46 );
			this->Generate->Name = L"Generate";
			this->Generate->Size = System::Drawing::Size( 94, 36 );
			this->Generate->TabIndex = 0;
			this->Generate->Text = L"Generate";
			this->Generate->UseVisualStyleBackColor = true;
			this->Generate->Click += gcnew System::EventHandler( this, &MyForm::Generate_Click );
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add( chartArea1 );
			this->chart1->DataSource = this->dataSet1;
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add( legend1 );
			this->chart1->Location = System::Drawing::Point( 12, 142 );
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->YValueMembers = L"0";
			this->chart1->Series->Add( series1 );
			this->chart1->Size = System::Drawing::Size( 1215, 356 );
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			this->dataSet1->Tables->AddRange( gcnew cli::array< System::Data::DataTable^  >( 1 ) { this->dataTable1 } );
			// 
			// dataTable1
			// 
			this->dataTable1->Columns->AddRange( gcnew cli::array< System::Data::DataColumn^  >( 1 ) { this->dataColumn1 } );
			this->dataTable1->MinimumCapacity = 1;
			this->dataTable1->TableName = L"Value";
			// 
			// dataColumn1
			// 
			this->dataColumn1->ColumnName = L"Value";
			// 
			// Sort
			// 
			this->Sort->Location = System::Drawing::Point( 626, 46 );
			this->Sort->Name = L"Sort";
			this->Sort->Size = System::Drawing::Size( 94, 36 );
			this->Sort->TabIndex = 2;
			this->Sort->Text = L"Sort";
			this->Sort->UseVisualStyleBackColor = true;
			this->Sort->Click += gcnew System::EventHandler( this, &MyForm::Sort_Click );
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler( this, &MyForm::backgroundWorker1_DoWork );
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler( this, &MyForm::backgroundWorker1_ProgressChanged );
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler( this, &MyForm::backgroundWorker1_RunWorkerCompleted );
			// 
			// label_method
			// 
			this->label_method->AutoSize = true;
			this->label_method->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>( 238 ) ) );
			this->label_method->Location = System::Drawing::Point( 320, 12 );
			this->label_method->Name = L"label_method";
			this->label_method->Size = System::Drawing::Size( 200, 22 );
			this->label_method->TabIndex = 3;
			this->label_method->Text = L"Choose sorting method:";
			// 
			// comboBox_sort
			// 
			this->comboBox_sort->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->comboBox_sort->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox_sort->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox_sort->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_sort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox_sort->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>( 238 ) ) );
			this->comboBox_sort->FormattingEnabled = true;
			this->comboBox_sort->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->comboBox_sort->ItemHeight = 20;
			this->comboBox_sort->Items->AddRange( gcnew cli::array< System::Object^  >( 11 ) {
				L"Bubble Sort", L"Insertion Sort", L"Selection Sort",
					L"Cocktail Sort", L"Quick Sort", L"MergeSort", L"Heap Sort", L"Radix Sort", L"Shell Sort", L"Comb Sort", L"Gnome Sort"
			} );
			this->comboBox_sort->Location = System::Drawing::Point( 526, 12 );
			this->comboBox_sort->Name = L"comboBox_sort";
			this->comboBox_sort->Size = System::Drawing::Size( 194, 28 );
			this->comboBox_sort->TabIndex = 4;
			this->comboBox_sort->SelectedIndexChanged += gcnew System::EventHandler( this, &MyForm::comboBox_sort_SelectedIndexChanged );
			// 
			// button_Cancel
			// 
			this->button_Cancel->Location = System::Drawing::Point( 626, 100 );
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size( 94, 36 );
			this->button_Cancel->TabIndex = 5;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			this->button_Cancel->Click += gcnew System::EventHandler( this, &MyForm::button_Cancel_Click );
			// 
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point( 526, 100 );
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size( 94, 36 );
			this->button_load->TabIndex = 6;
			this->button_load->Text = L"Load";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler( this, &MyForm::button_load_Click );
			// 
			// button_Save
			// 
			this->button_Save->Location = System::Drawing::Point( 426, 100 );
			this->button_Save->Name = L"button_Save";
			this->button_Save->Size = System::Drawing::Size( 94, 36 );
			this->button_Save->TabIndex = 7;
			this->button_Save->Text = L"Save";
			this->button_Save->UseVisualStyleBackColor = true;
			this->button_Save->Click += gcnew System::EventHandler( this, &MyForm::button_Save_Click );
			// 
			// textBox_n
			// 
			this->textBox_n->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>( 238 ) ) );
			this->textBox_n->Location = System::Drawing::Point( 193, 50 );
			this->textBox_n->Name = L"textBox_n";
			this->textBox_n->Size = System::Drawing::Size( 111, 27 );
			this->textBox_n->TabIndex = 8;
			this->textBox_n->TextChanged += gcnew System::EventHandler( this, &MyForm::textBox_n_TextChanged );
			// 
			// label_n
			// 
			this->label_n->AutoSize = true;
			this->label_n->Font = ( gcnew System::Drawing::Font( L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>( 238 ) ) );
			this->label_n->Location = System::Drawing::Point( 12, 51 );
			this->label_n->Name = L"label_n";
			this->label_n->Size = System::Drawing::Size( 175, 22 );
			this->label_n->TabIndex = 9;
			this->label_n->Text = L"Number of elements:";
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF( 8, 16 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size( 1239, 510 );
			this->Controls->Add( this->label_n );
			this->Controls->Add( this->textBox_n );
			this->Controls->Add( this->button_Save );
			this->Controls->Add( this->button_load );
			this->Controls->Add( this->button_Cancel );
			this->Controls->Add( this->comboBox_sort );
			this->Controls->Add( this->label_method );
			this->Controls->Add( this->Sort );
			this->Controls->Add( this->chart1 );
			this->Controls->Add( this->Generate );
			this->Icon = ( cli::safe_cast<System::Drawing::Icon^>( resources->GetObject( L"$this.Icon" ) ) );
			this->Name = L"MyForm";
			this->Text = L"Sorting Visualizer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler( this, &MyForm::MyForm_FormClosing );
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler( this, &MyForm::MyForm_DragDrop );
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler( this, &MyForm::MyForm_DragEnter );
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->chart1 ) )->EndInit();
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataSet1 ) )->EndInit();
			( cli::safe_cast<System::ComponentModel::ISupportInitialize^>( this->dataTable1 ) )->EndInit();
			this->ResumeLayout( false );
			this->PerformLayout();

		}
#pragma endregion
		
	private: Void Generate_Click( Object^ sender, EventArgs^ e );
	private: Void Sort_Click( Object^ sender, EventArgs^ e );
	private: Void backgroundWorker1_DoWork( Object^ sender, DoWorkEventArgs^ e );		
	private: Void backgroundWorker1_ProgressChanged( Object^ sender, ProgressChangedEventArgs^ e );
	private: Void backgroundWorker1_RunWorkerCompleted( Object^ sender, RunWorkerCompletedEventArgs^ e ); 
	private: Void comboBox_sort_SelectedIndexChanged( Object^ sender, EventArgs^ e );
	private: Void button_Cancel_Click( Object^ sender, EventArgs^ e );
	private: System::Void MyForm_FormClosing( System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e );
	private: System::Void button_load_Click( System::Object^ sender, System::EventArgs^ e );
	private: System::Void MyForm_DragDrop( System::Object^ sender, System::Windows::Forms::DragEventArgs^ e );
	private: System::Void MyForm_DragEnter( System::Object^ sender, System::Windows::Forms::DragEventArgs^ e );
	private: System::Void button_Save_Click( System::Object^ sender, System::EventArgs^ e );
	private: System::Void textBox_n_TextChanged( System::Object^ sender, System::EventArgs^ e );
		
	private: Void BubbleSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void InsertionSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void SelectionSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void CocktailSort( Object^ sender, EventArgs^ e, std::vector<int>& v );
	private: Void QuickSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r );
	private: Void MergeSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r );
	private: Void Merge( Object^ sender, EventArgs^ e, std::vector<int>& v, int l, int m, int r );
	private: Void HeapSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void Heapify( Object^ sender, EventArgs^ e, vector<int>& v, int n, int i );
	private: Void RadixSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void CountingSort2( Object^ sender, EventArgs^ e, vector<int>& v, int exp );
	private: Void ShellSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void CombSort( Object^ sender, EventArgs^ e, vector<int>& v );
	private: Void GnomeSort( Object^ sender, EventArgs^ e, vector<int>& v );

			
		
				
			
		




};
}
