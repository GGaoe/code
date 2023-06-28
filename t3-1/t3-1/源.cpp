#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int  n; cin >> n; int  a = n, r = n; int  b = 1, c = 0; if (a < 0) { a *= -1; r *= -1; }
	for (int i = 1; i <= 9; i++)
	{
		if (a / 10 >= 1) { b *= 10; c++; a /= 10; }
	}int y = r - a * b; for (int i = 1; i <= c; i++) {
		if (y % 10 == 0)y /= 10;
		else break;
	}
	double k; k = r - (a - 1) * b; for (int i = 1; i <= c; i++) {
		if (int(k) % 10 == 0)k /= 10;
		else break;
	}int d = k,e=0; for (int i = 1; i <= 9; i++) {
		if (d / 10 != 0) { e++; d /= 10; }
		else break;
	}
	if (n == 0)cout << "0";
	else if (y == 0) {
		if (n > 0)cout << r / b << "e" << c;
		else cout << "-" << r / b << "e" << c;
	}
	else if (y != 0) {
	if (n > 0)cout << int (r / b) << "." <<setw(e) << setfill('0') <<y << "e" << c;
	else cout << "-" << int (r / b) << "." << setw(e) << setfill('0') << y << "e" << c;
	}
	return 0;
}