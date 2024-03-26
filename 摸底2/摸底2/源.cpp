#include <iostream>
using namespace std;
int map[2010][2010];
int n, m;

int main() {
	int T;
	cin >> T;
	while (T--) {
		bool succ = 1;
		for (int i = 1; i <= 2005; i++) {
			for (int j = 1; j <= 2005; j++) {
				map[i][j] = 2;
			}
		}
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			map[i][i] = 1;
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			if (a == b)succ = 0;
			if (map[b][a] == 0)succ = 0;
			map[b][a] = 1;
			map[a][b] = 0;
			for (int j = 1; j <= n; j++) {
				if (map[j][b] == 1) {
					for (int k = 1; k <= n; k++) {
						if (map[a][k] == 1) {
							if (map[j][k] == 0)succ = 0;
							map[j][k] = 1;
							map[k][j] = 0;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (map[i][j] == 2)succ = 0;
				if (!(map[i][j] ^ map[j][i]))succ = 0;
			}
		}
		if (succ)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}