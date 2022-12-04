#include "MyForm.h"
#include<algorithm>

using namespace std;
using namespace Sort;

int sleep, ptc, ptc2;

int max_v( vector<int>& v )
{
	int max = v[0];
	for ( int i = 1; i < v.size(); i++ )
	{
		if ( v[i] > max )
		{
			max = v[i];
		}
	}
	return max;
}
int min_v( vector<int>& v )
{
	int min = v[0];
	for ( int i = 1; i < v.size(); i++ )
	{
		if ( v[i] < min )
		{
			min = v[i];
		}
	}
	return min;
}

Void Sort::MyForm::BubbleSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	for ( int i = 0; i < v.size(); i++ ) {
		if ( backgroundWorker1->CancellationPending ) return;
		int j;
		for ( j = 0; j < v.size() - i - 1; j++ ) {
			if ( v[j] > v[j + 1] )
			{
				swap( v[j], v[j + 1] );
			}
		}
		ptc = j;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep );
	}
	return Void();
}
Void Sort::MyForm::InsertionSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	for ( int i = 1; i < v.size(); i++ )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		int j = i;
		while ( j > 0 && v[j - 1] > v[j] )
		{
			swap( v[j], v[j - 1] );
			j--;
		}
		ptc = i;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 1.5 );
	}

	return Void();
}
Void Sort::MyForm::SelectionSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	for ( int i = 0; i < v.size(); i++ )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		int min = i;
		for ( int j = i + 1; j < v.size(); j++ )
		{
			if ( v[j] < v[min] )
			{
				min = j;
			}
		}
		swap( v[i], v[min] );
		ptc = i;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep );
	}
	return Void();
}
Void Sort::MyForm::CocktailSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int left = 0;
	int right = v.size() - 1;
	while ( left < right )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		for ( int i = left; i < right; i++ )
		{
			if ( v[i] > v[i + 1] )
			{
				swap( v[i], v[i + 1] );
			}
			
		}
		ptc2 = right--;
		for ( int i = right; i > left; i-- )
		{
			if ( v[i - 1] > v[i] )
			{
				swap( v[i - 1], v[i] );
			}
			
		}
		ptc = left++;
		backgroundWorker1->ReportProgress( ( left + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep );

	}
	return Void();
}

Void Sort::MyForm::QuickSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r )
{
	int i = l;
	int j = r;
	int x = v[( l + r ) / 2];
	do
	{
		if ( backgroundWorker1->CancellationPending ) return;
		while ( v[i] < x )
		{
			i++;
		}
		while ( v[j] > x )
		{
			j--;
		}
		if ( i <= j )
		{
			swap( v[i], v[j] );
			i++;
			j--;
		}
		ptc = i;
		ptc2 = j;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep );
	} while ( i <= j );
	if ( i < r )
	{
		QuickSort( sender, e, v, i, r );
	}
	if ( l < j )
	{
		QuickSort( sender, e, v, l, j );
	}

	return Void();
}

Void Sort::MyForm::MergeSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r )
{
	if ( l < r )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		int m = ( l + r ) / 2;
		MergeSort( sender, e, v, l, m );
		MergeSort( sender, e, v, m + 1, r );
		Merge( sender, e, v, l, m, r );
	}
	return Void();
}
Void Sort::MyForm::Merge( Object^ sender, EventArgs^ e, vector<int>& v, int l, int m, int r )
{
	if ( backgroundWorker1->CancellationPending ) return;
	int i = l;
	int j = m + 1;
	int k = 0;
	vector<int> temp( r - l + 1 );
	while ( i <= m && j <= r )
	{
		if ( v[i] < v[j] )
		{
			temp[k] = v[i];
			i++;
		}
		else
		{
			temp[k] = v[j];
			j++;
		}
		k++;
	}
	while ( i <= m )
	{
		temp[k] = v[i];
		i++;
		k++;
	}
	while ( j <= r )
	{
		temp[k] = v[j];
		j++;
		k++;
	}
	for ( int i = l; i <= r; i++ )
	{
		v[i] = temp[i - l];
	}
	ptc = i;
	backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
	Threading::Thread::Sleep( sleep );
	return Void();
}
Void Sort::MyForm::HeapSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	for ( int i = v.size() / 2 - 1; i >= 0; i-- )
	{
		ptc = i;
		Heapify( sender, e, v, v.size(), i );
	}
	sleep *= 0.5;
	for ( int i = v.size() - 1; i >= 0; i-- )
	{
		ptc = i;
		if ( backgroundWorker1->CancellationPending ) return;
		swap( v[0], v[i] );
		Heapify( sender, e, v, i, 0 );
	}

	return Void();
}
Void Sort::MyForm::Heapify( Object^ sender, EventArgs^ e, vector<int>& v, int n, int i )
{
	if ( backgroundWorker1->CancellationPending ) return;
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if ( l < n && v[l] > v[largest] )
	{
		largest = l;
	}
	if ( r < n && v[r] > v[largest] )
	{
		largest = r;
	}
	if ( largest != i )
	{
		swap( v[i], v[largest] );
		Heapify( sender, e, v, n, largest );
	}
	ptc2 = largest;
	backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
	Threading::Thread::Sleep( sleep * 0.5 );
	return Void();
}
Void Sort::MyForm::RadixSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int max = max_v( v );
	
	for ( int exp = 1; max / exp > 0; exp *= 10 )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		CountingSort2( sender, e, v, exp );
	}
	return Void();
}
Void Sort::MyForm::CountingSort2( Object^ sender, EventArgs^ e, vector<int>& v, int exp )
{
	vector<int> count( 10, 0 );
	for ( int i = 0; i < v.size(); i++ )
	{
		count[( v[i] / exp ) % 10]++;
	}
	for ( int i = 1; i < count.size(); i++ )
	{
		count[i] += count[i - 1];
	}
	vector<int> output( v.size() );
	for ( int i = v.size() - 1; i >= 0; i-- )
	{
		output[count[( v[i] / exp ) % 10] - 1] = v[i];
		count[( v[i] / exp ) % 10]--;
	}
	for ( int i = 0; i < v.size(); i++ )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		v[i] = output[i];
		ptc = i;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 0.6 );
	}

	return Void();
}
Void Sort::MyForm::ShellSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	for ( int gap = v.size() / 2; gap > 0; gap /= 2 )
	{
		for ( int i = gap; i < v.size(); i++ )
		{
			int temp = v[i];
			int j;
			for ( j = i; j >= gap && v[j - gap] > temp; j -= gap )
			{
				if ( backgroundWorker1->CancellationPending ) return;
				v[j] = v[j - gap];
			}
			v[j] = temp;
			ptc = i;
			ptc2 = j;
			backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
			Threading::Thread::Sleep( sleep * 0.8 );
		}
	}
	return Void();
}

int getNextGap( int gap )
{
	gap = ( gap * 10 ) / 13;
	if ( gap < 1 )
	{
		return 1;
	}
	return gap;
}
Void Sort::MyForm::CombSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int gap = v.size();
	bool swapped = true;
	while ( gap != 1 || swapped == true )
	{
		gap = getNextGap( gap );
		swapped = false;
		for ( int i = 0; i < v.size() - gap; i++ )
		{
			if ( backgroundWorker1->CancellationPending ) return;
			if ( v[i] > v[i + gap] )
			{
				swap( v[i], v[i + gap] );
				swapped = true;
			}
			ptc = i;
			ptc2 = i + gap;
			backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
			Threading::Thread::Sleep( sleep* 0.3 );
		}
	}
	return Void();
}

Void Sort::MyForm::GnomeSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int index = 0;
	while ( index < v.size() )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		if ( index == 0 )
		{
			index++;
		}
		if ( v[index] >= v[index - 1] )
		{
			index++;
		}
		else
		{
			swap( v[index], v[index - 1] );
			index--;
		}
		ptc = index;
		backgroundWorker1->ReportProgress( ( index + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 0.2 );
	}
	return Void();
}

int Sort::MyForm::Partition( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r )
{
	int pivot = v[r];
	int i = l - 1;
	for ( int j = l; j <= r - 1; j++ )
	{
		if ( backgroundWorker1->CancellationPending ) return 0;
		if ( v[j] <= pivot )
		{
			i++;
			swap( v[i], v[j] );
		}
		ptc = j;
		ptc2 = i;
		backgroundWorker1->ReportProgress( ( j + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 0.2 );
	}
	swap( v[i + 1], v[r] );
	return i + 1;
}
Void Sort::MyForm::IntroSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r, int depth )
{
	if ( backgroundWorker1->CancellationPending ) return;
	if ( l < r )
	{
		if ( depth == 0 )
		{
			HeapSort( sender, e, v );
		}
		else
		{
			int p = Partition( sender, e, v, l, r );
			IntroSort( sender, e, v, l, p - 1, depth - 1 );
			IntroSort( sender, e, v, p + 1, r, depth - 1 );
		}
	}
	
	return Void();
}
//ins sort used in timsort
Void Sort::MyForm::insSort( Object^ sender, EventArgs^ e, vector<int>& v, int l, int r )
{
	for ( int i = l + 1; i <= r; i++ )
	{
		int temp = v[i];
		int j = i - 1;
		while ( j >= l && v[j] > temp )
		{
			if ( backgroundWorker1->CancellationPending ) return;
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
		ptc = i;
		ptc2 = j;
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 0.2 );
	}
	return Void();
}
Void Sort::MyForm::TimSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int n = v.size();
	int minRun = 32;
	for ( int i = 0; i < n; i += minRun )
	{
		insSort( sender, e, v, i, min( ( i + 31 ), ( n - 1 ) ) );
	}
	for ( int size = minRun; size < n; size = 2 * size )
	{
		for ( int left = 0; left < n; left += 2 * size )
		{
			int mid = left + size - 1;
			int right = min( ( left + 2 * size - 1 ), ( n - 1 ) );
			Merge( sender, e, v, left, mid, right );
		}
	}
	
	return Void();
}
Void Sort::MyForm::CubeSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int n = v.size();
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			if ( backgroundWorker1->CancellationPending ) return;
			if ( v[i] > v[j] )
			{
				swap( v[i], v[j] );
			}
			ptc = i;
		}
		backgroundWorker1->ReportProgress( ( i + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( sleep * 0.5 );
	}
	return Void();
}

Void Sort::MyForm::BogoSort( Object^ sender, EventArgs^ e, vector<int>& v )
{
	int shuf = 0;
	while ( !issorted( v ) )
	{
		if ( backgroundWorker1->CancellationPending ) return;
		int j = rand() % v.size();
		int k = rand() % v.size();
		swap( v[j], v[k] );
		ptc = j;
		ptc2 = k;
		backgroundWorker1->ReportProgress( ( j + 1 ) * 100 / v.size() );
		Threading::Thread::Sleep( 1 );
		shuf++;
	}
	MessageBox::Show( "Number of shuffles: " + shuf );
	return Void();
}