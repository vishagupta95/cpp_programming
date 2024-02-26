#include <iostream>

using namespace std;

 
int main_x()
{
    int num;
    cin >> num;
    // num % 2 computes the remainder when num is divided by 2
    if ( num % 2 == 0 )
    {
        cout << num << " is even ";
    }
 
    return 0;
}

int main()
{
	int x, y, z;
	char name[20], address[20];
	
	
	cout << "Address: ";
	cin.getline(address, 20);
	
	
	cout << endl << "You entered " << endl;
	cout << "Address = " << address << endl;
	
    /* For single input */
	cout << "Enter a number: ";
	cin >> x;
	
	/* For multiple inputs*/
	cout << "Enter 2 numbers: ";
	cin >> y >> z;
	
	cout << "Sum = " << (x+y+z) << endl;

	return 0;
}
