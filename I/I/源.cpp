//给定一个包含n 个结点和m 条带权边的有向图，求所有点对间的最短路径长度，一条路径的长度定义为这条路径上所有边的权值和。
//nmlogn
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int n, X, Y;
struct node {
	int id;
	int child;
	int a[8030];
}nodes[8030];
int vis[8030];

stack<int>s;
bool flag = 0;
int y_neigh = 0;
int x_neigh = 0;
int count2 = 0;
int count3 = 0;

void dfs1() {
	if (!s.empty() && !flag) {
		int t = s.top();
		for (int i = 1; i <= nodes[t].child&&!flag; i++) {
			if (vis[nodes[t].a[i]])continue;
			if (nodes[t].a[i] == Y) {
				flag = 1; return;
			}
			s.push(nodes[t].a[i]);
			vis[nodes[t].a[i]] = 1;
			dfs1();
		}
	}
	if(!flag)s.pop();
}

void dfs2() {
	if (!s.empty()) {
		int t = s.top(); 
		for (int i = 1; i <= nodes[t].child; i++) {
			if (vis[nodes[t].a[i]])continue;
			else if (nodes[t].a[i]==y_neigh)continue;
			if (nodes[t].a[i] != y_neigh) {
				s.push(nodes[t].a[i]);
				vis[nodes[t].a[i]] = 1;
				count2++;
				dfs2();
			}
		}
	}
	s.pop();
	return;
}
void dfs3() {
	if (!s.empty()) {
		int t = s.top();
		for (int i = 1; i <= nodes[t].child; i++) {
			if (vis[nodes[t].a[i]])continue;
			else if (nodes[t].a[i] == x_neigh)continue;
			if (nodes[t].a[i] != x_neigh) {
				s.push(nodes[t].a[i]);
				vis[nodes[t].a[i]] = 1;
				//cout << nodes[t].a[i] << endl;
				count3++;
				dfs3();
			}
		}
	}
	s.pop();
	return;
}


int main() {
	cin >> n >> X >> Y;
	for (int i = 1; i <= n; i++) {
		nodes[i].id = i;
	}
	for (int i = 1; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		nodes[num1].child++;
		nodes[num1].a[nodes[num1].child] = num2;
		nodes[num2].child++;
		nodes[num2].a[nodes[num2].child] = num1;
	}

	s.push(X);
	vis[X] = 1;
	dfs1();
	if (!s.empty()) {
		y_neigh = s.top();
	}
	int tmp = 0;
	while (!s.empty()) {
		tmp = s.top();
		s.pop();
		if(!s.empty()&&s.top()==X)x_neigh = tmp;
	}
	//cout << x_neigh << endl;

	for (int i = 1; i <= 5050; i++) {
		vis[i] = 0;
	}
	s.push(Y);
	vis[Y] = 1;
	dfs2();

	while (!s.empty()) {
		s.pop();
	}

	for (int i = 1; i <= 5050; i++) {
		vis[i] = 0;
	}
	s.push(X);
	vis[X] = 1;
	dfs3();
	count2++;
	count3++;
	//cout << count3<< count2 << endl;
	cout << n * (n - 1) - count3 * count2;

	return 0;
}