#include <iostream>
using namespace std;
int n,m;
int map[50][50];
int sum1, sum2;
int cnt1, cnt2;
int maxn = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxn)maxn = map[i][j];
			if ((i + j) %2) {
				cnt2++;
				sum2 += map[i][j];
			}
			else {
				cnt1++;
				sum1 += map[i][j];
			}
		}
	}
	if (cnt1==cnt2) {
		if (sum1 != sum2) {
			cout << -1 << endl;
			return 0;
		}
		else {
			cout << maxn;
			return 0;
		}
	}
	else {
		int ans = (sum1 - sum2)/(cnt1-cnt2);
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp += (ans - map[i][j]);
			}
		}
		if (tmp < 0)cout << -1;
		else cout << tmp;
	}
	return 0;
}