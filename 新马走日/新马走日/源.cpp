#include <iostream>
using namespace std;
int map[18][18][2];
#define MAX 998244353
int main() {
	int n, m, num, x, y;
	cin >> n >> m >> x >> y >> num;
	map[x+1][y+1][0] = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 2; j <= n + 1;j++) {
			for (int k = 2; k <= m + 1; k++) {
				int u = i % 2;
				map[j][k][(u + 1) % 2] += map[j - 2][k - 1][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j - 1][k - 2][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j + 2][k - 1][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j + 1][k - 2][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j - 2][k + 1][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j - 1][k + 2][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j + 2][k + 1][u];
				map[j][k][(u + 1) % 2] %= MAX;
				map[j][k][(u + 1) % 2] += map[j + 1][k + 2][u];
				map[j][k][(u + 1) % 2] %= MAX;
			}
		}
		for (int j = 2; j <= n + 1; j++) {
			for (int k = 2; k <= m + 1; k++) {
				map[j][k][(i % 2)] = 0;
			}
		}
	}
	num %= 2;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 2; j <= m + 1; j++) {
			cout << map[i][j][num]<<" ";
		}
		cout << endl;
	}
	return 0;
}