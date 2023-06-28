#include <iostream>
#include <cmath>
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
		int p;
		cin >> p;
		int ans = 0; int ans1 = 0; 
		if (p<=2||p>17) { cout << "-1" << " -1" << endl; }
		else {
			int q;
			q = 19 - p;
			if (p <= q) {
				for (int i = 12; i <= pow(10, p); i++) {
					if (f(i) == p) {
						ans += i;
						int m, n; m = i % 10; n = i;
						while (n >= 10) {
							n /= 10;
						}
						if (m < n) {
							ans1 += i;
						}
					}
				}
			}
			else{
					for (int i = 12; i <= pow(10, q); i++) {
						if (f(i) == p) {
							ans += i;
							int m, n; m = i % 10; n = i;
							while (n >= 10) {
								n /= 10;
							}
							if (m < n) {
								ans1 += i;
							}
						}
					}
			}cout << ans << " " << ans1 << endl;
		}
		return 0;
	}