#include <iostream>
using namespace std;
int n, m;
int t;
int s[200005];
int k[200005];

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
	}//¹ýÇ°40%


	return 0;
}