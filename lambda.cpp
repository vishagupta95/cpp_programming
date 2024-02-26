#include <bits/stdc++.h>
using namespace std;

/*
c++ 11 introduced lambda expression to allow us write an inline function which can
be used for short snippets of code that are not going to be reuse and not worth naming. 
In its simplest form lambda expression can be defined as follows: 

[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 

[](){}                // An empty lambda, which does and returns nothing
int a = 0;                       // Define an integer variable
auto f = []()   { return a*9; }; // Error: 'a' cannot be accessed
auto f = [a]()  { return a*9; }; // OK, 'a' is "captured" by value
auto f = [&a]() { return a++; }; // OK, 'a' is "captured" by reference

int multiplier = 5;
auto timesFive = [multiplier](int a) { return a * multiplier; }; 
std::out << timesFive(2); // Prints 10

multiplier = 15;
std::out << timesFive(2); // Still prints 2*5 == 10

// We can also pass a lambda object as the comparator
    // and reuse the lambda multiple times
    auto compare = [](const Base &a, const Base &b) {
                     return a.variable < b.variable;};
    std::sort(std::begin(deque), std::end(deque), compare);
    std::sort(std::begin(array), std::end(array), compare);
    list.sort(compare);
    flist.sort(compare);


*/

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
