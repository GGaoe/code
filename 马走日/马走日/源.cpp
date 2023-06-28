#include <iostream>
#include <queue>
int map[501][501];
bool map1[501][501]={0};
using namespace std;
int main() {
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			map[i][j] = -1;
		}
	}
	int m, n;
	cin >> m >> n;
	int x, y;
	cin >> x >> y;
	queue <int>len_1;
	queue <int>col_1;
	int count1 = 0, count2 = 0;
	int step = 0;
	map[x][y] = 0;
	len_1.push(x);
	col_1.push(y);
	step++;
	map1[x][y] = 1;
	count1 = 1;
	bool flag = 1;
	while (!len_1.empty()) {
		if (flag) {
			for (int i = 1; i <= count1; i++) {
				int l = len_1.front();
				
				len_1.pop();
				int c = col_1.front();
				col_1.pop();
				if (0 < l - 1 && l - 1 <= m && 0 < c - 2 && c - 2 <= n&&!map1[l-1][c-2]) {
					len_1.push(l - 1);
					col_1.push(c - 2);
					map1[l - 1][c - 2] = 1;
					map[l - 1][c - 2] = step;
					count2++;
				}
				if (0 < l - 2 && l - 2 <= m && 0 < c - 1 && c - 1 <= n && !map1[l - 2][c - 1]) {
					len_1.push(l - 2);
					col_1.push(c - 1);
					map1[l - 2][c - 1] = 1;
					map[l - 2][c - 1] = step;
					count2++;
				}
				if (0 < l + 1 && l + 1 <= m && 0 < c - 2 && c - 2 <= n && !map1[l + 1][c - 2]) {
					len_1.push(l + 1);
					col_1.push(c - 2);
					map1[l + 1][c - 2] = 1;
					map[l + 1][c - 2] = step;
					count2++;
				}
				if (0 < l - 1 && l - 1 <= m && 0 < c + 2 && c + 2 <= n && !map1[l - 1][c + 2]) {
					len_1.push(l - 1);
					col_1.push(c + 2);
					map1[l - 1][c + 2] = 1;
					map[l - 1][c + 2] = step;
					count2++;
				}
				if (0 < l - 2 && l - 2 <= m && 0 < c + 1 && c + 1 <= n && !map1[l - 2][c + 1]) {
					len_1.push(l - 2);
					col_1.push(c + 1);
					map1[l - 2][c + 1] = 1;
					map[l - 2][c + 1] = step;
					count2++;
				}
				if (0 < l + 2 && l + 2 <= m && 0 < c + 1 && c + 1 <= n && !map1[l + 2][c + 1]) {
					len_1.push(l + 2);
					col_1.push(c + 1);
					map1[l + 2][c + 1] = 1;
					map[l + 2][c + 1] = step;
					count2++;
				}
				if (0 < l + 1 && l + 1 <= m && 0 < c + 2 && c + 2 <= n && !map1[l + 1][c + 2]) {
					len_1.push(l + 1);
					col_1.push(c + 2);
					map1[l + 1][c + 2] = 1;
					map[l + 1][c + 2] = step;
					count2++;
				}
				if (0 < l + 2 && l + 2 <= m && 0 < c - 1 && c - 1 <= n && !map1[l + 2][c - 1]) {
					len_1.push(l + 2);
					col_1.push(c - 1);
					map1[l + 2][c - 1] = 1;
					map[l + 2][c - 1] = step;
					count2++;
				}

			}
			step++;
			flag = 0;
			count1 = 0;
			continue;
		}
		else {
			for (int i = 1; i <= count2; i++) {
				int l = len_1.front();
				len_1.pop();
				int c = col_1.front();
				col_1.pop();
				if (0 < l - 1 && l - 1 <= m && 0 < c - 2 && c - 2 <= n && !map1[l - 1][c - 2]) {
					len_1.push(l - 1);
					col_1.push(c - 2);
					map1[l - 1][c - 2] = 1;
					map[l - 1][c - 2] = step;
					count1++;
				}
				if (0 < l - 2 && l - 2 <= m && 0 < c - 1 && c - 1 <= n && !map1[l - 2][c - 1]) {
					len_1.push(l - 2);
					col_1.push(c - 1);
					map1[l - 2][c - 1] = 1;
					map[l - 2][c - 1] = step;
					count1++;
				}
				if (0 < l + 1 && l + 1 <= m && 0 < c - 2 && c - 2 <= n && !map1[l + 1][c - 2]) {
					len_1.push(l + 1);
					col_1.push(c - 2);
					map1[l + 1][c - 2] = 1;
					map[l + 1][c - 2] = step;
					count1++;
				}
				if (0 < l - 1 && l - 1 <= m && 0 < c + 2 && c + 2 <= n && !map1[l - 1][c + 2]) {
					len_1.push(l - 1);
					col_1.push(c + 2);
					map1[l - 1][c + 2] = 1;
					map[l - 1][c + 2] = step;
					count1++;
				}
				if (0 < l - 2 && l - 2 <= m && 0 < c + 1 && c + 1 <= n && !map1[l - 2][c + 1]) {
					len_1.push(l - 2);
					col_1.push(c + 1);
					map1[l - 2][c + 1] = 1;
					map[l - 2][c + 1] = step;
					count1++;
				}
				if (0 < l + 2 && l + 2 <= m && 0 < c + 1 && c + 1 <= n && !map1[l + 2][c + 1]) {
					len_1.push(l + 2);
					col_1.push(c + 1);
					map1[l + 2][c + 1] = 1;
					map[l + 2][c + 1] = step;
					count1++;
				}
				if (0 < l + 1 && l + 1 <= m && 0 < c + 2 && c + 2 <= n && !map1[l + 1][c + 2]) {
					len_1.push(l + 1);
					col_1.push(c + 2);
					map1[l + 1][c + 2] = 1;
					map[l + 1][c + 2] = step;
					count1++;
				}
				if (0 < l + 2 && l + 2 <= m && 0 < c - 1 && c - 1 <= n && !map1[l + 2][c - 1]) {
					len_1.push(l + 2);
					col_1.push(c - 1);
					map1[l + 2][c - 1] = 1;
					map[l + 2][c - 1] = step;
					count1++;
				}

			}
			step++;
			flag = 1;
			count2 = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}cout << endl;
	}return 0;
}