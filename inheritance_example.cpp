#include <iostream>
using namespace std;


class Cpolygon
{
	protected:
		int width, height;
	public:
		void input_values (int one, int two)
		{
			width=one;
			height=two;
		}
};

class Cprint
{
	public:
		void printing (int output);
};

void Cprint::printing (int output)
{
	cout << output << endl;
}

class Crectangle: public Cpolygon, public Cprint
{
	public:
		int area ()
		{
			return (width * height);
		}
};

class Ctriangle: public Cpolygon, public Cprint
{
	public:
		int area ()
		{
			return (width * height / 2);
		}
};

int main ()
{
	Crectangle rectangle;
	Ctriangle triangle;
	rectangle.input_values (2,2);
	triangle.input_values (2,2);
	rectangle.printing (rectangle.area());
	triangle.printing (triangle.area());
	return 0;
}
