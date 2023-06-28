#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b <= c || b + c <= a || a + c <= b)
		cout << "Not triangle" << endl;
	else if (pow(a, 2) + pow(b, 2) == pow(c, 2) ^ pow(a, 2) + pow(c, 2) == pow(b, 2) ^ pow(a, 2) == pow(b, 2) + pow(c, 2))
		cout << "Right traigle" << endl;
	else if (pow(a, 2) + pow(b, 2) > pow(c, 2) ^ pow(a, 2) + pow(c, 2) > pow(b, 2) ^ pow(a, 2) < pow(b, 2) + pow(c, 2))
		cout << "Acute traigle" << endl;
	else if (pow(a, 2) + pow(b, 2) < pow(c, 2) ^ pow(a, 2) + pow(c, 2) < pow(b, 2) ^ pow(a, 2) > pow(b, 2) + pow(c, 2))
		cout << "Obtuse traigle" << endl;
	if ((a == b || a == c || b == c) && (a + b > c && b + c > a && a + c > b))
		cout << "Isosceles traight" << endl;
	if (a == b && a == c)
		cout << "Equilateral traight" << endl;
	return 0;
}