// CPP program to illustrate 
// use of new keyword 
// For a dynamically allocated object, constructor is invoked by new operator 

#include<iostream> 
using namespace std; 

class student {
    int rno;
    char name[10];
    double fee;

public:
    student()
    {
        cout<<"Enter the RollNo:";
        cin>>rno;
        cout<<"Enter the Name:";
        cin>>name;
        cout<<"Enter the Fee:";
        cin>>fee;
    }

    void display()
    {
        cout<<endl<<rno<<"\t"<<name<<"\t"<<fee;
    }
};

class Point {
private:
    int x, y;
 
public:
    // Parameterized Constructor
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
 
    int getX() { return x; }
    int getY() { return y; }
};



/* defining constructor outside class
student::student()
{
    cout<<"Enter the RollNo:";
    cin>>rno;
 
      cout<<"Enter the Name:";
    cin>>name;
     
      cout<<"Enter the Fee:";   
    cin>>fee;
} 
*/
// Cpp program to illustrate the
// concept of Constructors
#include <iostream>
using namespace std;

class construct {
public:
    int a, b;

    // Default Constructor
    construct()
    {
        a = 10;
        b = 20;
    }
};


class car 
{ 
	string name; 
	int num; 

	public: 
		car(string a, int n) 
		{ 
			cout << "Constructor called" << endl; 
			this ->name = a; 
			this ->num = n; 
		} 
/*
                car(string a, int n)  
                {
                  cout << "Constructor called" << endl; 
                  name = a;  
                  num = n;  
                }                                                                                                                        }
*/
		void enter() 
		{ 
			cin>>name; 
			cin>>num; 
		} 

		void display() 
		{ 
			cout << "Name: " << name << endl; 
			cout << "Num: " << num << endl; 
		} 
}; 

int main() 
{ 
    // Default constructor called automatically
    // when the object is created
    construct c;
    cout << "a: " << c.a << endl << "b: " << c.b;
 

    // Constructor called
    Point p1(10, 15); 

     student s; // constructor gets called automatically when
     // we create the object of the class
     s.display();
     // Using new keyword 
     car *p = new car("Honda", 2017); // For a dynamically allocated object, constructor is invoked by new operator 
     p->display(); 
} 
