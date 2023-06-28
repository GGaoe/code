#include <iostream>
#include <queue>
using namespace std;
char a[1001][1001];
bool b[1001][1001];
queue<int>list_x;
queue<int>list_y;
int start_x, start_y;
int step = 1;
bool flag = 0;
bool over = 0;
int count1 = 0;
int count2 = 0;
void popout(int u, int v) {
	
	if (a[u + 1][v] == 'P' && b[u + 1][v] == 0) {
		b[u+1][v] = 1;
		if (!flag) {
			count1++;
		}
		else count2++;
		list_x.push(u+1);
		list_y.push(v);
	}
	if (a[u - 1][v] == 'P' && b[u - 1][v] == 0) {
		b[u-1][v] = 1;
		if (!flag) {
			count1++;
		}
		else count2++; 
		list_x.push(u - 1);
		list_y.push(v);
	}
	if (a[u ][v+1] == 'P' && b[u ][v+1] == 0) {
		b[u][v+1] = 1;
		if (!flag) {
			count1++;
		}
		else count2++; 
		list_x.push(u );
		list_y.push(v+1);
	}
	if (a[u ][v-1] == 'P' && b[u ][v-1] == 0) {
		b[u][v-1] = 1;
		if (!flag) {
			count1++;
		}
		else count2++; 
		list_x.push(u );
		list_y.push(v-1);
	}
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'D'){start_x = i; start_y = j;
			}
		}
	}
	
	b[start_x][start_y] = 1;
	list_x.push(start_x);
	list_y.push(start_y);
	count1 = 1;
	flag = 1;
	while (!list_x.empty()&&!over)
		{
			if (flag) {
				step++;
				for (int i = 1; i <= count1; i++) {
					if (
						a[list_x.front() + 1][list_y.front()] != 'G'
						&& a[list_x.front() - 1][list_y.front()] != 'G'
						&& a[list_x.front()][list_y.front() + 1] != 'G'
						&& a[list_x.front()][list_y.front() - 1] != 'G'
						) {
						popout(list_x.front(), list_y.front());
						list_x.pop(); list_y.pop();
					}
					else over = 1;
				}count1 = 0; flag = 0;
			}
			else {
				step++;
				for (int i = 1; i <= count2; i++) {
					if (
						a[list_x.front() + 1][list_y.front()] != 'G'
						&& a[list_x.front() - 1][list_y.front()] != 'G'
						&& a[list_x.front()][list_y.front() + 1] != 'G'
						&& a[list_x.front()][list_y.front() - 1] != 'G'
						) {
						popout(list_x.front(), list_y.front());
						list_x.pop(); list_y.pop();
					}
					else over=1;
				}count2 = 0; flag = 1;
			}
		}
	if (list_x.empty())cout << "No"; 
	else cout << step-1;
	return 0;
}