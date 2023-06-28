#include <iostream>
#include <cmath>
using namespace std;
int a(int x) {
	int sum1 = 0;
	for (int i = 1; i < (x+1) / 2; i++) {//首位
		for (int m = 1; m <= 8; m++) {//公差
			int n = 1;//公差的个数
			while (2*i + n * m <= x) {
				if (i+n * m > 9) { break; }
				if (2*i + n * m == x) {//合条件
					int u = n;
					for (int p = 0; p <= n; p++) {
						int t = i + p * m;
						sum1 += t * pow(10, u) + t * pow(10, n - u); u--;
					}
				}n++;
			}
		}
	}return sum1;
}
int e(int x) {
	 int sum2 = 0;
	for (int i = 1; i < (x+1) / 2; i++) {
		for (int m = 1; m <= 8; m++) {
			int n = 1;
			while (2*i + n * m <= x) {
				if (i+n * m > 9) { break; }
				if (2*i + n * m == x) {
						int u = n;
						for (int p =0; p <= n; p++) {
							int t = i + p * m;
							sum2 += t * pow(10, n-u); u--;
						}
				}n++;
			}
		}
	}return sum2;
}
int main() {
	int p;
	cin>>p;
	if (p == 2|| p == 1||p==0 || p > 17) {
		cout << "-1" <<" "<< "-1";
	}
	else {
		cout << a(p)<<" "<<e(p) << endl;
	}
	return 0;
}