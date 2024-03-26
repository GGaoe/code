#include <iostream>
using namespace std;
#define inf 1e9
int n, m, u, v, w, tmp = inf;
int dis[300][300];
int map[300][300];
int main() {
	cin >> n >> m;
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			map[i][j] = inf;
			dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		map[u][v] = w;
		map[v][u] = w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++)
			for (int j = i + 1; j < k; j++)
				tmp = min(tmp, dis[i][j] + map[i][k] + map[k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}

	}
	if (tmp >1e8 )cout << -1<<endl;
	else cout << tmp <<endl;
	return 0;
}