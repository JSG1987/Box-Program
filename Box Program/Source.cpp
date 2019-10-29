#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>

using namespace std;

double readit();
void right(double, double, double);
//void tri(double, double, double);

ofstream outfile;
ifstream infile;

double readit()
{
	double t;
	infile >> t;
	return t;
}

/*void tri(double x, double y, double z)
{
	if (x + y < z)
	{
		outfile << "This is a valid triangle. " << endl;
		cout << "This is a valid triangle. " << endl;
	}
	else
	{
		outfile << "This is not a triangle. " << endl;
		cout << "This is not a triangle. " << endl;
	}
	return;
}*/
void right(double x, double y, double z)
{
	double sides = (pow(x, 2) + pow(y, 2));
	if (sides == pow(z, 2))
	{
		outfile << "This is a right triangle. " << endl;
		cout << "This is a right triangle. " << endl;
		cout << z << ">" << x << "+" << y << endl;
	}
	else 
	{
		//obtuse(x, y, z);
		//tri(x, y, z);
	}
	return;
}
void obtuse(double x, double y, double z)
{
	double sides = (pow(x, 2) + pow(y, 2));
	if (sides < pow(z, 2))
	{
		outfile << "This is an Obtuse triangle. " << endl;
		cout << "This is an Obtuse triangle. " << endl;
		cout << z << ">" << x << "+" << y << endl;
	}
	else
	{
		//acute(x, y, z);
		//tri(x, y, z);
	}
	return;
}
void acute(double x, double y, double z)
{
	double sides = (pow(x, 2) + pow(y, 2));
	if (sides > pow(z, 2))
	{
		outfile << "This is an acute triangle. " << endl;
		cout << "This is an acute triangle. " << endl;
		cout << z << ">" << x << "+" << y << endl;
	}
	else
	{
		//tri(x, y, z);
	}
	return;
}

int main()
{
	outfile.open("Triangle.txt");
	infile.open("T.txt");
	double x, y, z, a, b;
	if (!infile.good())
	{
		cout << "file bad\n";
	}

	while (infile.good())
	{
		x = readit();
		y = readit();
		z = readit();
		if (x > z)
		{
			a = z;
			z = x;    
			x = a;
		}
		if (y > z)
		{
			b = z;
			z = y;
			y = b;
		}
		if (x + y > z)
		{
			cout << "This is a Triangle" << endl;
			right(x, y, z);
			obtuse(x, y, z);
			acute(x, y, z);
		}
		else
			cout << "Not a Triangle" << endl;
	}
	infile.close();
	outfile.close();
	system("PAUSE");
	return 0;
}