#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int a[105][2];
const int maxn = 1e2 + 5;
const int base = 1e5 + 5;
int f[maxn][2 * base+5];
const int INF = -1e7;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 0; i <= 2 * base; i++) {
		f[0][i] = INF;
	}
	f[0][base] = 0;
	for (int i = 1; i <= n; i++) {
		int v = a[i][0] - k * a[i][1];
		int w = a[i][0] + a[i][1];
		for (int j = 0; j <= 2 * base; j++) {
			f[i][j] = f[i - 1][j];
			if (j - v >= 0 && j - v <= 2 * base && f[i - 1][j - v] != INF) {
				f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
			}
		}
	}
	cout << f[n][base] << endl;

	return 0;
}