#include "MyForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace Sort;
using namespace std;

[STAThreadAttribute]

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault( false );
	Sort::MyForm form;
	Application::Run( % form );

	return 0;
}
//global variables
int n = 100;
vector<int> v( n );
int a = 10;
int b = 250;

bool cancelled = false;
bool generated = false;

enum SortMethod {
	Bubble, Insertion, Selection, Cocktail, Quick, Merge, Heap, Radix, Shell, Comb, Gnome
};
SortMethod sortMethod = Bubble;

Void Sort::MyForm::comboBox_sort_SelectedIndexChanged( Object^ sender, EventArgs^ e ) {
	sortMethod = (SortMethod)comboBox_sort->SelectedIndex;

	return Void();
}
void updateDataSet( Data::DataSet^ dataSet1, vector<int> v )
{
	dataSet1->Tables[0]->Rows->Clear();

	for ( int i = 0; i < v.size(); i++ )
	{
		dataSet1->Tables[0]->Rows->Add( v[i] );
	}
}
Void Sort::MyForm::Generate_Click( Object^ sender, EventArgs^ e )
{
	if ( backgroundWorker1->IsBusy ) {
		MessageBox::Show( "Please wait for the current operation to finish" );
		return Void();
	}
	if ( !n  ) {
		MessageBox::Show( "You can't generate 0 elements" );
		return Void();
	}
	v.resize( n );
	//generate random numbers
	for ( int i = 0; i < n; i++ )
	{
		v[i] = rand() % ( b - a + 1 ) + a;
	}
	updateDataSet( dataSet1, v );
	chart1->ChartAreas[0]->AxisY->Maximum = 1.01 * b;
	chart1->Series[0]->Points->DataBind( dataSet1->Tables[0]->DefaultView, "", "Value", "" );
	cancelled = false;
	generated = true;

	return Void();
}

Void MyForm::backgroundWorker1_DoWork( Object^ sender, DoWorkEventArgs^ e ) {
	switch ( sortMethod ) {
	case 0: BubbleSort( sender, e, v );
		break;
	case 1: InsertionSort( sender, e, v );
		break;
	case 2: SelectionSort( sender, e, v );
		break;
	case 3: CocktailSort( sender, e, v );
		break;
	case 4: QuickSort( sender, e, v, 0, v.size() - 1 );
		break;
	case 5: MergeSort( sender, e, v, 0, v.size() - 1 );
		break;
	case 6: HeapSort( sender, e, v );
		break;
	case 7: RadixSort( sender, e, v );
		break;
	case 8: ShellSort( sender, e, v );
		break;
	case 9: CombSort( sender, e, v );
		break;
	case 10: GnomeSort( sender, e, v );
		break;

	default: break;
	}

	return Void();
}
Void Sort::MyForm::backgroundWorker1_ProgressChanged( Object^ sender, ProgressChangedEventArgs^ e )
{
	updateDataSet( dataSet1, v );
	chart1->Series[0]->Points->DataBindY( dataSet1->Tables[0]->DefaultView, "Value" );

	if ( cancelled ) return;
	if ( ptc < 0 || ptc >= v.size() ) return;
	chart1->Series[0]->Points[ptc]->Color = Color::FromArgb( 209, 20, 83 );
	
	if ( sortMethod == 3 || sortMethod == 8 || sortMethod == 9 ) {
		if ( !ptc || ptc2 < 0 || ptc2 >= v.size() ) return;
		chart1->Series[0]->Points[ptc2]->Color = Color::FromArgb( 209, 20, 83 );
	}
	
	return Void();
}
Void Sort::MyForm::backgroundWorker1_RunWorkerCompleted( Object^ sender, RunWorkerCompletedEventArgs^ e )
{
	//8A2BE2

	chart1->Series[0]->Points->DataBindY( dataSet1->Tables[0]->DefaultView, "Value" );

	return Void();
}
bool issorted( vector<int> v1 )
{
	for ( int i = 0; i < v1.size() - 1; i++ )
	{
		if ( v1[i] > v1[i + 1] ) return false;
	}
	return true;
}
int sleeptime( int size ) {
	
	if ( size <= 10 ) return 420;
	if ( size <= 25 ) return 250;
	if ( size <= 50 ) return 180;
	if ( size <= 100 ) return 69;
	if ( size <= 250 ) return 35;
	if ( size <= 500 ) return 15;
	if ( size <= 1000 ) return 7;
	return 3;
	
}
Void Sort::MyForm::Sort_Click( Object^ sender, EventArgs^ e )
{
	if ( !generated ) {
		MessageBox::Show( "You can't sort an empty array" );
		return Void();
	}
	if ( issorted( v ) ) {
		MessageBox::Show( "The array is already sorted" );
		return Void();
	}
	if ( backgroundWorker1->IsBusy ) {
		MessageBox::Show( "Please wait for the current operation to finish" );
		return Void();
	}

	sleep = sleeptime( v.size() );

	if ( cancelled ) MessageBox::Show( "Sorting will be performed from the beginning" );

	backgroundWorker1->RunWorkerAsync();

	return Void();
}
Void Sort::MyForm::button_Cancel_Click( Object^ sender, EventArgs^ e )
{
	if ( backgroundWorker1->IsBusy ) {
		backgroundWorker1->CancelAsync();
		cancelled = true;
	}

	return Void();
}
System::Void Sort::MyForm::MyForm_FormClosing( System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e )
{
	backgroundWorker1->CancelAsync();

	return System::Void();
}
System::Void Sort::MyForm::button_load_Click( System::Object^ sender, System::EventArgs^ e )
{
	v.clear();

	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;
	
	if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK ) {
		
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader( openFileDialog1->FileName );
		String^ line;
		while ( ( line = sr->ReadLine() ) != nullptr ) {
			v.push_back( Convert::ToInt32( line ) );
		}
		sr->Close();
	}
	n = v.size();
	updateDataSet( dataSet1, v );
	chart1->Series[0]->Points->DataBind( dataSet1->Tables[0]->DefaultView, "", "Value", "" );
	cancelled = false;
	generated = true;
	return System::Void();
}
System::Void Sort::MyForm::MyForm_DragDrop( System::Object^ sender, System::Windows::Forms::DragEventArgs^ e )
{
	v.clear();
	Array^ f = (Array^)e->Data->GetData( DataFormats::FileDrop );
	if ( f->GetLength( 0 ) != 1 ) {
		MessageBox::Show( "You can only drop 1 file at time" );
		return System::Void();
	}
	String^ b = (String^)f->GetValue( 0 );

	if ( !b->EndsWith( ".txt" ) ) {
		MessageBox::Show( "Only txt files are allowed" );
		return System::Void();
	}
	
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader( b );
	String^ line;
	while ( ( line = sr->ReadLine() ) != nullptr ) {
		v.push_back( Convert::ToInt32( line ) );
	}
	sr->Close();
	n = v.size();
	updateDataSet( dataSet1, v );
	chart1->Series[0]->Points->DataBind( dataSet1->Tables[0]->DefaultView, "", "Value", "" );
	cancelled = false;
	generated = true;
	
	return System::Void();
}
System::Void Sort::MyForm::MyForm_DragEnter( System::Object^ sender, System::Windows::Forms::DragEventArgs^ e )
{
	if ( e->Data->GetDataPresent( DataFormats::FileDrop ) ) {
		e->Effect = DragDropEffects::Copy;
	}
	else {
		e->Effect = DragDropEffects::None;
	}
	return System::Void();
}
System::Void Sort::MyForm::button_Save_Click( System::Object^ sender, System::EventArgs^ e )
{
	if ( !generated ) {
		MessageBox::Show( "You can't save an empty array" );
		return System::Void();
	}

	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
	saveFileDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	saveFileDialog1->FilterIndex = 1;
	saveFileDialog1->RestoreDirectory = true;
	
	if ( saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK ) {
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter( saveFileDialog1->FileName );
		for ( int i = 0; i < n; i++ ) {
			sw->WriteLine( v[i] );
		}
		sw->Close();
	}
	
	return System::Void();
}
int stringToNumber( string s ) {
	int a = 0;
	//if string is empty set a to 0
	if ( s.empty() ) return a;
	bool isNeg = false;
	//if string is negative
	if ( s.at( 0 ) == '-' )
	{
		isNeg = true;
		s.erase( 0, 1 );
	}
	if ( s.empty() )
	{
		a = 0;
		return a;
	}
	//remove any sign after .
	for ( int i = 0; i < s.length(); i++ )
	{
		if ( s.at( i ) == '.' )
		{
			s.erase( i + 1, s.length() - i );
			break;
		}
	}
	if ( s.empty() )
	{
		a = 0;
		return a;
	}
	//remove any signs expect digits
	for ( int i = 0; i < s.length(); i++ )
	{
		if ( !isdigit( s.at( i ) ) )
		{
			s.erase( i, 1 );
			i--;
		}
	}
	if ( s.empty() )
	{
		a = 0;
		return a;
	}
	
	a = stoi( s );

	return a;
}
System::Void Sort::MyForm::textBox_n_TextChanged( System::Object^ sender, System::EventArgs^ e )
{

	n = stringToNumber( msclr::interop::marshal_as<std::string>( textBox_n->Text ) );
	
	if ( n > 1250 ) {
		MessageBox::Show( "1250 is max size for animation to handle (n will be set to 1250)" );
		n = 1250;
	}
	
	return System::Void();
}




