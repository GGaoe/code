#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, m;
struct node {
	int d;
	int low;
	int visited;
	int parent;
	int children;
	int tim;
	int blk;
}nodes[300010];

stack<int>s;
stack<int>s1;
int time1;
int x1, x2;
vector<vector<int>>vec;

int find_edge(int v1, int v2) {
	for (int i = 0; i < vec[v1].size(); i++) {
		if (vec[v1][i] == v2)return 1;
	}
	return 0;

}

int tim2;


void dfs(int u) {
	time1 = time1 + 1;
	nodes[u].d = time1;
	nodes[u].low = nodes[u].d;
	nodes[u].visited = 1;
	for (int i = 1; i <= n; i++) {
		if (find_edge(u,i)) {
			if (nodes[i].visited == 0) {
				x1 = min(u, i);
				x2 = max(u, i);
				int x3, x4;
				s.push(x1);
				s1.push(x2);
				nodes[i].parent = u;
				nodes[u].children++;
				dfs(i);
				nodes[u].low = min(nodes[u].low, nodes[i].low);
				if ((nodes[u].parent == 0 && nodes[u].children >= 2) || (nodes[u].parent != 0 && nodes[i].low >= nodes[u].d)) {
					tim2++;
					do {
						x3 = s.top();
						s.pop();
						x4 = s1.top();
						s1.pop();
						if (nodes[x3].tim != tim2) {
							nodes[x3].blk++;
							nodes[x3].tim = tim2;
						}
						if (nodes[x4].tim != tim2) {
							nodes[x4].blk++;
							nodes[x4].tim = tim2;
						}
					} while (x3 != x1 || x4 != x2);
				}
			}

			

			else if (i != nodes[u].parent) {
				if (nodes[u].d >= nodes[i].d) {
					x1 = min(u, i);
					x2 = max(u, i);
					s.push(x1);
					s1.push(x2);
					nodes[u].low = min(nodes[u].low, nodes[i].d);
				}
			}
		}

			
	}

	return;
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n+2; i++) {
		vector<int>v1;
		vec.push_back(v1);
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		vec[v1].push_back(v2);
		vec[v2].push_back(v1);
	}
	for (int i = 1; i <= n; i++) {
		if (!nodes[i].visited) {
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		//cout << nodes[i].visited << endl;
		if (nodes[i].blk > 1) {
			cout << i << " ";
		}
	}

	return 0;
}