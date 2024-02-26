#include <iostream>
#include <deque>

/*
A vector is a dynamic array, whose size can be increased, 

As vector and deque both provides a function to push_back the element at the last.
where deque also provides a function push_front to insert the element at the beginning,
 which is bit costly in case of vector.
 */

using namespace std;

void showdata(deque<int> deque1)
{
  deque<int>::iterator it;
  for (it = deque1.begin(); it != deque1.end(); ++it)
    cout << "\t" << *it;
  cout << "\n";
}

int main()
{
  deque<int> myqueue;
  myqueue.push_front(230); // getting data from front
  myqueue.push_front(240); // getting data from front
  myqueue.push_back(250);  // getting data from back
  myqueue.push_back(260);  // getting data from back
  cout << "Deque elements are: ";
  showdata(myqueue);

  return (0);
}
