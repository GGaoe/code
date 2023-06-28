#include <iostream>
using namespace std;
int a[10], b[10],c[10],d[10];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}int num = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			c[num] = a[i];d[num]=b[i]; num++;
		}
		else continue;
	}if (c[0] == 0) {
		cout << 0 << " " << 1;
	}
	else {
		num--;//数据清洗 c分子d分母
		long long fm = 1; int fz = 0;
		for (int i = 0; i <= num; i++) {
			fm *= d[i]; fz *= d[i];
			fz += fm / d[i] * c[i];
			int g = 1; 
			if (fm == 2 && fz % 2 == 0) {
				fz /= 2; fm /= 2;
			}
			else if (fm > 2) {
				for (int i = 2; i <= fm; i++) {
					if (fz % i == 0 && fm % i == 0) {
						g = i;
					}
				}
				fz /= g; fm /= g;
			}
		}
		cout << fz << " " << fm;
	}return 0;
}