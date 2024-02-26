#include <iostream>
#include <vector>
#include <stdlib.h>   /* srand, rand */
#include <algorithm>
using namespace std;

// Helper function to print a vector
void printVector(vector<int> V) {
  for (int i=0; i < V.size(); i++)
    cout << V[i] << " ";
  cout << endl;
}

int main() {
  
  vector<int> V {3, 2, 5, 7, 1, 4, 6}; 

  cout << "Before:\t";
  printVector(V);

  // The third argument to the sort function is a lambda expression
  // that has an empty capture clause, has two parameters a and b,
  // and returns a boolean. The lambda body is just a > b in order
  // to sort the values descendingly.
  sort(V.begin(), V.end(), [](const int& a, const int& b) -> bool
  { 
    return a > b;
  });

  cout << "After:\t";
  printVector(V); 
}
