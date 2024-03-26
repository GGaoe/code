#include <iostream>
#include <queue>
using namespace std;
int map[650][650];
int checked[650][650];
int break1[650][650];
int break2[650][650];
int n, m, k;
int tmp;
long long result;

queue<int>q_x;
queue<int>q_y;

void bfs() {
	int x, y;
	long long tmp_ans=0;

	while (!q_x.empty()) {
		x = q_x.front();
		q_x.pop();
		y = q_y.front();
		q_y.pop();
		tmp_ans += map[x][y];
		if ((x - 1 > 0) && !break2[x - 1][y]&&!checked[x-1][y]) {
			q_x.push(x - 1);
			q_y.push(y);
			//tmp_ans += map[x - 1][y];
			checked[x - 1][y] = 1;
		}
		if ((x + 1 <=n) && !break2[x][y] && !checked[x + 1][y]) {
			q_x.push(x + 1);
			q_y.push(y);
			//tmp_ans += map[x + 1][y];
			checked[x + 1][y] = 1;
		}
		if ((y - 1 > 0) && !break1[x][y-1] && !checked[x][y-1]) {
			q_x.push(x);
			q_y.push(y-1);
			//tmp_ans += map[x][y-1];
			checked[x][y-1] = 1;
		}
		if ((y + 1 <= m) && !break1[x][y] && !checked[x][y+1]) {
			q_x.push(x);
			q_y.push(y+1);
			//tmp_ans += map[x][y+1];
			checked[x][y+1] = 1;
		}
	}
	//cout << tmp_ans << endl;
	result += tmp_ans * tmp_ans;
	return;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++)
		{
			cin >> tmp;
			if (!tmp)break1[i][j] = 1;//位置(i, j) 和位置(i,j+1) 之间有障碍物
		}
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= m; j++)
		{
			cin >> tmp;
			if (!tmp)break2[i][j] = 1; //位置(i, j) 和位置(i + 1, j)之间有障碍物。
		}
	}
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] += 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!checked[i][j]) {
				checked[i][j] = 1;
				q_x.push(i);
				q_y.push(j);
				bfs();
			}
		}
	}
	cout << result << endl;
	
	return 0;
}