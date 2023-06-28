#include <iostream>
using namespace std;

int op=0;
int k, n;
int map[105][10050];

void dp() {
	for (int i = 1; i <= 10010; i++) {
		map[1][i] = i;
	}
	for (int i = 2; i <= 103; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = map[i - 1][j - 1] + 1 + map[i][j - 1];
		}
	}
}

int main() {
	cin >> k >> n;
	dp();
	for (int i = 1; i <= n; i++) {
		if (map[k][i] >= n) {
			op = i; break;
		}
	}
	cout << op << endl;
	return 0;
}