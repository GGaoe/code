#include <iostream>
using namespace std;
char a[1001][1001];
bool b[1001][1001];
int min = 1000000;
int go_right(int x, int y);
int go_down(int x, int y);
int go_up(int x,int y);
int go_left(int x, int y);
int go_left(int x, int y) {
	if ((a[x - 1][y] == 'P' || a[x - 1][y] == 'G') && !b[x - 1][y]) {
		b[x][y] = 1; go_up(x - 1, y); b[x][y] = 0;
	}
	if ((a[x][y - 1] == 'P' || a[x][y - 1] == 'G') && !b[x][y - 1]) {
		b[x][y] = 1; go_left(x, y - 1); b[x][y] = 0;
	}
	if ((a[x + 1][y] == 'P' || a[x + 1][y] == 'G') && !b[x + 1][y]) {
		b[x][y] = 1; go_down(x + 1, y); b[x][y] = 0;
	}
	else return 0;
}
int go_up(int x,int y){
	if ((a[x ][y+1] == 'P' || a[x ][y+1] == 'G') && !b[x ][y+1]) {
		b[x][y] = 1; go_right(x , y+1); b[x][y] = 0;
	}
	if ((a[x][y - 1] == 'P' || a[x][y - 1] == 'G') && !b[x][y - 1]) {
		b[x][y] = 1; go_left(x, y - 1); b[x][y] = 0;
	}
	if ((a[x + 1][y] == 'P' || a[x + 1][y] == 'G') && !b[x + 1][y]) {
		b[x][y] = 1; go_down(x + 1, y); b[x][y] = 0;
	}
	else return 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}
