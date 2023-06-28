#include <iostream>
using namespace std;
int a[101]={0}, b[101]={0}, c[101]={0};
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 101-m; i <=100; i++) {
		char t; cin >> t; if (t == 'A')a[i] = 10;
		else if (t == 'B')a[i] = 11;
		else if (t == 'C')a[i] = 12;
		else if (t == 'D')a[i] = 13;
		else if (t == 'E')a[i] = 14;
		else if (t == 'F')a[i] = 15;
		else a[i] = t - '0';
	}
	for (int i = 101 - n; i <= 100; i++)
	{
		char t; cin >> t; if (t == 'A')b[i] = 10;
		else if (t == 'B')b[i] = 11;
		else if (t == 'C')b[i] = 12;
		else if (t == 'D')b[i] = 13;
		else if (t == 'E')b[i] = 14;
		else if (t == 'F')b[i] = 15;
		else b[i] = t - '0';
	}
	int q=101;
	for (int i = 100; i >= 0; i--) {
		c[i] += a[i] + b[i]; if (c[i] > 15) {
			c[i] -= 16; c[i - 1]++;
		}
	}
		for (int i = 0; i <= 100; i++) {
			if (c[i] != 0) {
				q = i; break;
			}
		}if (q == 101) {
			cout << 0;
		}
		else for (int i = q; i <= 100; i++) {
			if (c[i] == 10)cout << "A" << " ";
			else if (c[i] == 11)cout << "B" << " ";
			else  if (c[i] == 12)cout << "C" << " ";
			else  if (c[i] == 13)cout << "D" << " ";
			else if (c[i] == 14)cout << "E" << " ";
			else if (c[i] == 15)cout << "F" << " ";
			else cout << c[i] << " ";
		}
		return 0;
	}