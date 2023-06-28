#include <iostream>
using namespace std;
int min1 = 1000000000;
int point[1001][2][1001] = {0};
int N, M;
int length = 0;
void dfs(int n) {
	if (n == 1) {
		int count = 0;
		while (point[n][1][count] != 0) {
			length = 0;
			length += point[n][1][count];
			dfs(point[n][0][count]);
			count++;
		}
	}
	else if (n == N) {
		if (length < min1)min1 = length;
	}
	else {
		int count = 0;
		while (point[n][1][count] != 0) {
			length += point[n][1][count];
			dfs(point[n][0][count]);
			length -= point[n][1][count];
			count++;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		int t = min(u, v);
		int j = 0;
		point[t][0][j] = max(u, v);
		point[t][1][j] = w;
		j++;//////ถฅต๔มห
	}
	dfs(1);
	cout << min1;
	return 0;
}