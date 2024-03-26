#include <iostream>
using namespace std;
int n, m;
int Mask[40000];
int dp_map[40000][20];
int map[20][20];

void dp(int x,int Mark) {
	for (int i = 0; i < n; i++) {//遍历一遍所有节点，找出与x相连的节点
		if (map[x][i] != 0) {//节点相连
			if ((Mark >> i) % 2 != 1) {//节点没走过
				int d = 1<<i;
				if (dp_map[Mark | d][i] == 0) {
					dp_map[Mark | d][i] = dp_map[Mark][x]+map[x][i];
				}
				else {
					dp_map[Mark | d][i] = min(map[x][i] + dp_map[Mark][x], dp_map[Mark|d][i]);
				}
				dp(i, Mark | d);
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v,c;
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
	for (int i = 0; i < n; i++) {
		int y = 1<<i;
		dp(i, y);
	}
	int min1 = 10000;
	int d = (1<<n) - 1;
	for (int i = 0; i < n; i++) {
		min1 = min(min1, dp_map[d][i]);
	}
	if (min1 == 0) {
		cout << -1 << endl;
	}
	else cout << min1 << endl;
	
	return 0;
}