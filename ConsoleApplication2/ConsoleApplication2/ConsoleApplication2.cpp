#include <iostream>
#include<iomanip>
using namespace std;
int main() {
	double  a, b, c;
	cin >> a >> b >> c;
	double p, s;
	p = 0.5 * (a + b + c);
	s = pow(p * (p - a) * (p - b) * (p - c), 0.5);
	cout << fixed << setprecision(1) <<s<< endl;
	return 0;
}