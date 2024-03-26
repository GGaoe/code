#include <iostream>
using namespace std;
int map[210][210];
int n;
int sum1;

int main() {
	cin >> n;
	for (int i = 1; i <= n * (n - 1) / 2; i++) {
		int c, v;
		cin >> c >> v;
		int color;
		cin >> color;
		if (color == 1) {
			map[c][v] = 1;
			map[v][c] = 1;
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (map[i][j] == map[j][k] && map[i][j] == map[i][k])
					sum1++;
			}
		}
	}
	cout << sum1;

	return 0;
}