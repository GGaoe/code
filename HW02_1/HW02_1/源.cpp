#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[505][505];
struct node {
	bool flag;
	int min;
}v[505];
queue <int> s;
int count1;

int search() {
	while(!s.empty()){
		int x = s.front();
		s.pop();
		for(int i=1;i<=n;i++)
		if (map[x][i] == 1 &&v[i].flag==0) {
			v[i].min = v[x].min + 1;
			v[i].flag = 1;
			s.push(i);
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			else {
				if (map[i][j] == 1)map[i][j] = 0;
				else map[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		v[i].min = 0;
		v[i].flag = 0;
	}
	v[1].flag = 1;
	s.push(1);
	count1 = 1;
	search();
	for (int i = 2; i <= n; i++) {
		cout << v[i].min;
		if(i!=n)cout<<" ";
	}
	return 0;
}