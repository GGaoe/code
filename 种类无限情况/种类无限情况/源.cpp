#include <iostream>
using namespace std;
const int maxx = 100001;
int c1[maxx];
int c2[maxx];
int n;
int main() {
	
	cin >> n;
	for (int i = 0; i <= n; i++) {
		c1[i] = 1;
		c2[i] = 0;
	}
	for (int i = 2; i <= n; i++) {//i指第i个多项式
		for (int j = 0; j <= n; j++) {//j指前i-1个多项式乘积中次数为j的项
			for (int k = 0; k + j <= n; k += i){//k指第i个多项式中次数为k的项
				c2[k + j] += c1[j];
			}
		}
		for (int j = 0; j <= n; j++) {
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
	cout << c1[n] << endl;
	return 0;
}