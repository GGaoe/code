#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b > c && b + c > a && a + c > b)
	{
		{
			if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(a, 2) == pow(b, 2) + pow(c, 2))
				cout << "Right triangle" << endl;
			if (pow(a, 2) + pow(b, 2) > pow(c, 2) && pow(a, 2) + pow(c, 2) > pow(b, 2) && pow(a, 2) < pow(b, 2) + pow(c, 2))
				cout << "Acute triangle" << endl;
			if (pow(a, 2) + pow(b, 2) < pow(c, 2) || pow(a, 2) + pow(c, 2) < pow(b, 2) || pow(a, 2) > pow(b, 2) + pow(c, 2))
				cout << "Obtuse triangle" << endl;
		}
		{if (a == b || a == c || b == c)
			cout << "Isosceles triangle" << endl;
		if (a == b && a == c)
			cout << "Equilateral triangle" << endl; }
	}

	else
		cout << "Not triangle" << endl;
	return 0;
}