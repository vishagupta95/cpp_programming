/*
Vectors are known as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.

Vector of Vectors is a two-dimensional vector with a variable number of rows where each row is vector. Each index of vector stores a vector which can be traversed and accessed using iterators. It is similar to an Array of Vectors but with dynamic properties.

vector<vector<int>> vec{ { 1, 2, 3 }, 
                         { 4, 5, 6 }, 
                         { 7, 8, 9, 4 } }; 
where vec is the vector of vectors with different
      number of elements in different rows

*/

// C++ program to demonstrate insertion
// into a vector of vectors

#include <iostream>
#include <vector>
using namespace std;

// Defining the rows and columns of
// vector of vectors
#define ROW 4
#define COL 5

int main()
{
	// Initializing the vector of vectors
	vector<vector<int> > vec;

	// Elements to insert in column
	int num = 10;

	// Inserting elements into vector
	for (int i = 0; i < ROW; i++) {
		// Vector to store column elements
		vector<int> v1;

		for (int j = 0; j < COL; j++) {
			v1.push_back(num);
			num += 5;
		}

		// Pushing back above 1D vector
		// to create the 2D vector
		vec.push_back(v1);
	}

	// Displaying the 2D vector
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	return 0;
}


