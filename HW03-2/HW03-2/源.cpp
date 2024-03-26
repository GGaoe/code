#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, m;
struct {
	int v1, v2;
	int c;
	bool vis;
}edge[1000006];
vector<vector<int>>vec;
stack <int>ans;


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n + 2; i++) {
		vector<int>vv;
		vec.push_back(vv);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		edge[i].v1 = u, edge[i].v2 = v, edge[i].c = cost;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int start = 1;
	for (int i = 1; i <= n; i++) {
		if (vec[i].size() % 2 == 1) {
			start = i;
		}
	}

	return 0;

}