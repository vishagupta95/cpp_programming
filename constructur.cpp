// CPP program to illustrate 
// use of new keyword 
#include<iostream> 
using namespace std; 

class string
{
    public:

	string(char* aStr)
	{
		str = new char[ strlen(aStr) + 1 ];
		strcpy (str,aStr);
	}

	string(string &strObj)
	{
                str = new char[ strObj.str ];
                strcpy( str, strObj.str );
	}

	string &string::operator=(const string &s)
	{
                string temp( s );
                std::swap( temp.str, str );
                return *this;
	}

	// destructor
	~string() 
	{
		delete[] str;
	}

    private:
	char* str;
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

#if 0
int main() 
{ 
	// Using new keyword 
	car *p = new car("Honda", 2017); 
	p->display(); 
} 
#endif

class Line {

   public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   cout << "Normal constructor allocating ptr" << endl;
   
   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
}

Line::Line(const Line &obj) {
   cout << "Copy constructor allocating ptr." << endl;
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
}

Line::~Line(void) {
   cout << "Freeing memory!" << endl;
   delete ptr;
}

int Line::getLength( void ) {
   return *ptr;
}

void display(Line obj) {
   cout << "Length of line : " << obj.getLength() <<endl;
}

// Main function for the program
int main() {
   Line line(10);

   display(line);

   return 0;
}

