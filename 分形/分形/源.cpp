#include <iostream>
#include <cmath>
using namespace std;
int k[129][129];
int a[2][2];
int b, c, d, g;
int f(int m,int up,int left) {
	if (m > 0) {
		if (k[up][left] == 1) {
			k[up][left] = b; f(m - 1,up,left);
			k[up + (int)pow(2, m - 1)][left] =d; f(m - 1, up + (int)pow(2, m - 1), left);
			k[up][left + (int)pow(2, m - 1)] =c; f(m - 1, up, left + (int)pow(2, m - 1));
			k[up + (int)pow(2, m - 1)][left + (int)pow(2, m - 1)] =g; f(m - 1, up + (int)pow(2, m - 1), left + (int)pow(2, m - 1));
		}
		else return 0;
	}
	else return 0;
}
int main() {
	int m;
	cin >> m;
	char q, w, e, r;
	cin >> q >> w >> e >> r;
	a[0][0] = q - '0'; a[0][1] = w - '0'; a[1][0] =e - '0'; a[1][1] = r - '0';
	 b = a[0][0], c = a[0][1], d = a[1][0], g = a[1][1];
	int n = pow(2, m);
	k[1][1] = b; k[n+1][1] = d; k[1][n+1] = c; k[n+1][n+1] = g;
	f(m, 1, 1);
	f(m, 1 +n, 1);
	f(m, 1, 1 +n);
	f(m, 1 +n, 1 + n);

	for (int i = 1; i <= pow(2, m + 1); i++) {
		for (int j = 1; j <= pow(2, m + 1); j++) {
			cout << k[i][j];
		}cout << endl;
	}
	return 0;
}