#include <iostream>
#include <iomanip>
#include <vector>   
#include <stdexcept>

#include "foo.h"

using namespace std;

void outputVector( const vector< int > & ); // display the vector

void test_cplusplus_11(void)
{
	vector< int > integers1 = {1, 2, 3, 4, 5, 6, 7};

	cout << "Size of vector integers1 is " << integers1.size()
		<< "\nvector after initialization:" << endl;
	outputVector( integers1 );
}

// output vector contents
void outputVector( const vector< int > &array )
{
	for ( int item : array )
		cout << item << " ";
	
	cout << endl;
} 
