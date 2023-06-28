#include <iostream>
#include <algorithm>
using namespace std;
double  yhd(int a, int b) {
	double  ans = 0;
	{if (a <= b) {
		
		for (int i = a; i <= b; i++) {
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
}
	{if (ans != 0) {
		double  q = 1.0 / a / b;
	    return q;
		}
		else {
		double y = ans / a / b;
		 return  y;
		}
	}
}

	int main() {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		double ma = max(yhd(a, b), yhd(a, c));
		double  mb = max(yhd(a, d), yhd(b, c));
		double  mc = max(yhd(b, d), yhd(c, d));
		double  w = max(ma, mb);
		double f = max(mc, w);
		cout << f;
		return 0;
	}
