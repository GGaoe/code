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
	for (int i = 2; i <= n; i++) {//iָ��i������ʽ
		for (int j = 0; j <= n; j++) {//jָǰi-1������ʽ�˻��д���Ϊj����
			for (int k = 0; k + j <= n; k += i){//kָ��i������ʽ�д���Ϊk����
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