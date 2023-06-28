#include <iostream>
using namespace std;
double q(int a,int b) {
	double  ans = 0;
	if (a <= b) {

		for (int i = a; i <= b; i++) {
			bool flag = 1;
			
			for (int m = 2; m <= i - 1; m++) {
				if (i % m == 0) {
					flag = 0;
				}
			}
			if (flag) {
				ans += i;
			}
		}
	}
	else {

		for (int i = b; i <= a; i++) {
			bool flag = 1;
			if (i == 2) { ans += 2; }
			for (int m = 2; m <= i - 1; m++) {
				if (i % m == 0) {
					flag = 0;
				}
			}
			if (flag) {
				ans += i;
			}
		}
	}
	return ans / a / b;
}
double max(double a, double  b, double c, double d,double g,double f) {
	double e = 0;
	if (a > e)e = a;
	if (b > e)e = b;
	if (c > e)e = c;
	if (d > e)e = d;
	if (g > e)e = g;
	if (f > e)e = f;
	return e;
}
int main() {
	int a, b,c,d;
	cin >> a >> b>>c>>d;
	cout << max(q(a, b), q(a, c), q(a, d), q(b, c), q(b, d), q(c, d));
	return 0;
}
