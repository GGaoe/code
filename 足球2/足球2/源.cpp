#include <iostream>
using namespace std;
int n, m;
int t;
int s[100005];
int k[100005];
int dp2[100005][103][2][2];//球员，第k脚传球，长传短传，总距离及传到的位置
int dp[1000000][2][2];

struct player {
	int longt;
	int l_p;
	int shortt;
	int s_p;
}mem[200009];

void init() {
	for (int t = 1; t <= m; t++) {
		int i, j, c;
		cin >> i >> j >> c;
		if (mem[i].l_p < c) {
			mem[i].l_p = c;
			mem[i].longt = j;
		}
		if (mem[i].s_p == 0 || mem[i].s_p > c) {
			mem[i].s_p = c;
			mem[i].shortt = j;
		}
		if (mem[j].l_p < c) {
			mem[j].l_p = c;
			mem[j].longt = i;
		}
		if (mem[j].s_p == 0 || mem[j].s_p > c) {
			mem[j].s_p = c;
			mem[j].shortt = i;
		}

	}
	return;
}

void dp_m() {
	int one=1;
	int two = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0][0] = dp[i - 1][1][0] + mem[one].l_p;
		dp[i][0][1] = mem[one].longt;
		one = mem[one].longt;
		dp[i][1][0] = dp[i - 1][0][0] + mem[one].s_p;
		dp[i][1][1] = mem[two].shortt;
	    two = mem[two].shortt;
	}


	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	init();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s[i] >> k[i];
	}
	for (int i = 1; i <= t; i++) {
		bool flag = 1;
		long long dis = 0;
		player one = mem[s[i]];
		for (int j = 1; j <= k[i]; j++) {
			if (flag) {
				dis += one.l_p;
				one = mem[one.longt];
				flag = 0;
			}
			else {
				dis += one.s_p;
				one = mem[one.shortt];
				flag = 1;
			}

		}cout << dis << '\n';
	}//过前40%


	return 0;
}