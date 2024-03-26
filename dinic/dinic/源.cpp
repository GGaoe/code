#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, s, t;
#define s 0
#define t n+1

int top = 0;
const int inf = 1 << 27;
int head[10050];
int level[10050];
int que[10050];
int in[300];
int out[300];
int max_flow = 0;

struct {
	int v;
	int val;
	int next;
}node[10005];

void addedge(int u,int v,int val) {
	node[top].v = v;
	node[top].val = val;
	node[top].next = head[u];
	head[u] = top++;
	node[top].v = u;
	node[top].val = 0;
	node[top].next = head[v];
	head[v] = top++;
}

bool bfs() {
	memset(level, 0x3f, sizeof(level));
	memset(que, 0, sizeof(que));
	level[s] = 0;
	queue<int>q;
	q.push(s);
	while (!empty(q)) {
		int r = q.front();
		q.pop();
		que[r] = 0;
		for (int i = head[r]; i; i = node[i].next) {
			int d = node[i].v;
			if (level[d] > level[r] + 1 && node[i].val) {
				level[d] = level[r] + 1;
				if (que[d] == 0) {
					q.push(d);
					que[d] = 1;
				}
			}
		}
	}
	if (level[t] != 0x3f3f3f3f)return 1;
	else return 0;
}

int dfs(int u, int flow) {
	int rlow = 0;
	if (u == t)return flow;
	for (int i = head[u]; i; i = node[i].next) {
		int d = node[i].v;
		if (node[i].val && level[d] == level[u] + 1) {
			if (rlow = dfs(d, min(flow, node[i].val))) {//找到增广路径
				node[i].val -= rlow;
				node[i^1].val += rlow;//更新剩余网络
				return rlow;
			}
		}
	}
	return 0;
}

void dinic() {
	int flow = 0;
	while (bfs()) {
		while (flow = dfs(s, inf))max_flow += flow;
	}
	return;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		top = 0;
		memset(head, 0, sizeof(head));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		max_flow = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int u, v, op;
			cin >> u >> v >> op;
			if (!op) addedge(u, v, 1);
			else addedge(u, v, 0);
			in[v]++; out[u]++;
		}
		int count1 = 1, sum = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = in[i] - out[i];
			if (tmp & 1) count1 = 0;
			if (tmp > 0) addedge(i, n+1, tmp / 2);
			if (tmp <= 0) addedge(0, i, -tmp / 2), sum -= tmp / 2;
		}
		if (!count1) {
			cout << "impossible" << endl; 
			continue;
		}
		dinic();
		if (max_flow == sum) cout << "possible" << endl;
		else cout << "impossible" << endl;
	}
	return 0;
}