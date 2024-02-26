
#include <iostream>
#include <string.h>
using namespace std;

//Default constructor does only shallow copy.
//Deep copy is possible only with user defined copy constructor.
//MyClass t1, t2; 
//MyClass t3 = t1; // ----> (1) 
//t2 = t1;		 // -----> (2) 
//
//In the above example (1) calls copy constructor and (2) calls assignment operator. 
/*
Foo getFoo(); 
Foo x;   // default constructed 
Foo y(x);  // copy constructed 
Foo z(Foo());   // move constructed 
Foo w(getFoo());  // move constructed 

A copy constructor must leave the source object intact, so it must allocate 
its own copy of the object's data for itself. Both objects now refer to different 
copies of the same data in different areas of memory 

In C++, a Copy Constructor may be called in the following cases: 

When an object of the class is returned by value. 
When an object of the class is passed (to a function) by value as an argument. 
When an object is constructed based on another object of the same class. 
When the compiler generates a temporary object.

A move constructor, on the other hand, can simply "move" the data by 
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

*/
/*When the above code is executed, the move constructor is called instead of the copy constructor. With the move constructor, 
the copy of the temporary object of A is avoided. For a large number of push_back statements, 
using the move constructor is an efficient choice.
*/

#include <iostream>
#include <string>

using namespace std; // This brings the entire std namespace into scope

class Person {
public:
    // Constructor
    Person(string name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person &other) : name(other.name), age(other.age) {
        cout << "Copy constructor called." << endl;
    }

    // Member function to display person's information
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main() {
    // Create a Person object
    Person person1("Alice", 30);

    // Use the copy constructor to create another Person object as a copy of person1
    Person person2 = person1;

    // Display the information of both persons
    cout << "Person 1:" << endl;
    person1.display();

    cout << "Person 2 (Copy of Person 1):" << endl;
    person2.display();

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class String
{
private:
    char *s;
    int size;
public:
    String(const char *str = NULL);
    String(const String &src);
    ~String();
    String& operator=(const String &rhs);
    void print() const;
};

String::String(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::String(const String &src)
{
    size = src.size;
    s = new char[size+1];
    strcpy(s, src.s);
}

String::~String()
{
    delete [] s;
} 

void String::print() const
{
    cout << s << endl;
}

String& String::operator=(const String &rhs)
{
    if (&rhs != this)
    {
        String tmp(rhs);
        swap(s, tmp.s);
        swap(size, tmp.size);
    }
    return *this;
}

int main()
{
    String str1("learnc++");
    String str2 = str1;

    str1.print();
    str2.print();

    //str2.change("learnjava");
    str2 = "learnjava";

    str1.print();
    str2.print();

    return 0;
}


