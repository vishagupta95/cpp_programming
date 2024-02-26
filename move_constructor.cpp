#include <iostream>
#include <string>
using namespace std;

/*
 *A move constructor, on the other hand, can simply "move" the data by 
 taking ownership of the pointer that refers to the data, leaving the data
 itself where it resides. The new object now points at the original data, and
 the source object is modified to no longer point at the data. The data itself is 
 left untouched.

 A move constructor allows the resources owned by an rvalue object to be moved into an lvalue without creating its copy. An rvalue is an 
 expression that does not have  any memory address, and an lvalue is an expression with a memory address.

 int &j = 20;
 The above code snippet will give an error because, in C++, a variable cannot be referenced to a temporary object. The correct way to do 
 it is to create and rvalue reference using && :

 int &&j = 20;
 Temporary objects are often created during the execution of a C++ program.
 *
*/
class Names{
private:
    string* name;
public:
    Names(string place_name){
        cout << "Overloaded constructor" << endl;
        name = new string;
        *name = place_name;
    }
    //copy constructor
    Names(Names& cpy){
        cout << "Copy constructor" << endl;
        name = new string;
        *name = *cpy.name;
    }
    //assignment 
    Names& operator =(const Names& cpy){
        cout << "Assignment operator" << endl;
        name = new string;
        *name = *cpy.name;
        return *this;
    }
	 // Move constructor
    // It will simply shift the resources,
    // without creating a copy
    //move constructor
	//With the move constructor, the copy of the temporary object of cpym is avoided
    Names(Names&& cpym){
        cout << "Copy move constructor" << endl;
        name = cpym.name;
        cpym.name = NULL;
    }
    //move assignment operator
    Names& operator=(Names&& cpym){
        cout << "Copy assignment operator" << endl;
        delete name;
        name = cpym.name;
        cpym.name = NULL;
        return *this;
    }
    //destructor
    ~Names(){
        cout << "Deallocating memory" << endl;
        delete [] name;
    }
};

int main(){
    Names nme("Bob");
    Names copin("something");
    copin = nme;
    system("pause");
    return 0;
}


public:
    MyIntArray() = default;

    MyIntArray(int size) {
        arr = new int[size];
        this->size = size;
        for(int i = 0; i < size; ++i) {
            arr[i] = i;
        }
    }

    // copy constructor
    MyIntArray(const MyIntArray &src) {
        // allocate a new copy of the array...
        arr = new int[src.size];
        size = src.size;
        for(int i = 0; i < src.size; ++i) {
            arr[i] = src.arr[i];
        }
    }

    // move constructor
    MyIntArray(MyIntArray &&src) {
        // just swap the array pointers...
        src.swap(*this);
    }

    ~MyIntArray() {
        delete[] arr;
    }

    // copy assignment operator
    MyIntArray& operator=(const MyIntArray &rhs) {
        if (&rhs != this) {
            MyIntArray temp(rhs); // copies the array
            temp.swap(*this);
        }
        return *this;
    }

    // move assignment operator
    MyIntArray& operator=(MyIntArray &&rhs) {
        MyIntArray temp(std::move(rhs)); // moves the array
        temp.swap(*this);
        return *this;
    }

    /*
    or, the above 2 operators can be implemented as 1 operator, like below.
    This allows the caller to decide whether to construct the rhs parameter
    using its copy constructor or move constructor...

    MyIntArray& operator=(MyIntArray rhs) {
        rhs.swap(*this);
        return *this;
    }
    */

    void swap(MyIntArray &other) {
        // swap the array pointers...
        std::swap(arr, other.arr);
        std::swap(size, other.size);
    }
}; 
