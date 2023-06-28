#include <iostream>
using namespace std;
int f(int a) {
	if (a >= 10 && a % 10 != 0) {
		bool flag = 1;
		int m = a % 10;
	    if (a / 10 % 10 == a % 10) return -1;
		else if (a >= 100) {
			while (a >= 100) {
				if (a / 10 % 10 != a % 10 && a / 100 % 10 - a / 10 % 10 != a / 10 % 10 - a % 10) {
					flag = 0;
				}a /= 10;
			}
			if (flag) return a / 10 % 10 + m;
			else return -1;
		}
		bool flag1 = 1;
		int n = a / 10 % 10; if (m == n) {
			flag1 = 0;
		}
		else if (a < 100 && flag1) return a / 10 % 10 + a % 10;
		else return -1;
	}
	else return -1;
}
int main() {
	int n, t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;  cout << f(t) << endl;
	}
	return 0;
}