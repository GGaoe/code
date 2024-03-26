#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n,s,t;

const int inf = 0x9f9f9f;
int level[10050];
int que[10050];
int max_flow = 0;
int used[10000];

struct edge{
	int v;
	int val;
	unsigned long long next;
};

vector<edge>edges[10000];

void addedge(int u, int v, int val) {
	edges[u].push_back(edge{ v, val, edges[v].size()});
	edges[v].push_back(edge{ u, 0, edges[u].size()-1 });
	return;
}

bool bfs() {
	cout << s << endl;
	//s = 0;
	memset(level, -1, sizeof(level));
	memset(que, 0, sizeof(que));
	level[s] = 0;
	queue<int>q;
	q.push(s);
	while (!empty(q)) {
		int r = q.front();
		q.pop();
		que[r] = 1;
		for (int b = 0; b < edges[r].size(); b++) {
			edge f = edges[r][b];
			if (f.val>0 && !que[f.v] && level[f.v]==-1) {
				q.push(f.v);
				que[f.v] = 1;
				level[f.v] = level[r] + 1;
			}
		}
	}
	if (level[t] != -1)return 1;
	else return 0;
}

int dfs(int u, int flow) {
	cout << s << endl;
	//s = 0;
	//int rlow = 0;
	if (u == t)return flow;
	for (int& i = used[u]; i < edges[u].size(); i++) {
		edge& r = edges[u][i];
		if (r.val > 0 && level[u] < level[r.v]) {
			int d = dfs(r.v, min(flow, r.val));
			if (d>0) {
				r.val -= d;
				edges[r.v][r.next].val += d;
				return d;
			}
		}
	}
	return 0;
}

void dinic() {
	int flow = 0;
	while (bfs()) {
		//s = 0;
		int flow = 0;
		memset(used, 0, sizeof(used));
		while (flow = dfs(s, inf)>0) {
			max_flow += flow;
		}
	}
	return;
}


int main() {
	s = 0;
	cin >> n;
	t = n * n + 1;
	int val=0;
	int sum1 = 0;
	int nexts[4][2] = { 1,0, 0,1, -1,0, 0,-1 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> val;
			sum1 += val;
			if ((i + j) % 2) {
				addedge(0, (i - 1) * n + j, val);
				for (int k = 0; k < 4; k++) {
					int xx = i + nexts[k][0];
					int yy = j + nexts[k][1];
					if (xx>0 && yy>0 && xx <= n && yy <= n && !((xx+yy)%2))
						addedge((i - 1) * n + j, (xx - 1) * n + yy, inf);
				}
			}
			else    addedge((i - 1) * n + j, n * n +1, val);
		}
	}
	dinic();
	std::cout << sum1-max_flow << endl;

	return 0;
}