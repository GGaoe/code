#include <iostream>
using namespace std;
int n, m;
int Mask[40000];
int dp_map[40000][20];
int map[20][20];

void dp() {
	for (int j = 1; j < (1 << n); j++) {//遍历路径
		for (int m = 0; m < n; m++) {//找到一个在路上的点
			int tmp1 = j >> m;
			if (tmp1 % 2 == 1)
				for (int b = 0; b < n; b++) {//找到不在路上的点
					int tmp2 = j >> b;
					if (tmp2 % 2 != 1) {
						if (map[b][m] != 0) { //两节点之间有边
							int tmp = 1 << b;
							dp_map[j|tmp][b] = min(map[b][m] + dp_map[j][m], dp_map[j|tmp][b]);
						}
					}
				}
		}

	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		if (map[u][v] == 0) {
			map[u][v] = c;
			map[v][u] = c;
		}
		else {
			map[u][v] = min(map[u][v], c);
			map[v][u] = min(map[v][u], c);
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < 16; j++) {
			if (i == (1 << j))continue;
			else dp_map[i][j] = 10000;
		}
	}
	dp();
	int min1 = 10000;
	int d = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		min1 = min(min1, dp_map[d][i]);
	}
	if (min1 == 0) {
		cout << -1 << endl;
	}
	else cout << min1 << endl;
	

	return 0;
}