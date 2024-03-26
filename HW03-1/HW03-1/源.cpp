#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
int n, m;
struct{
	int v1, v2;
}edge[1000006];
vector<set<int>>vec;
stack <int>ans;

void Hierhozer(int u) {
    set<int>::iterator it;
	it = vec[u].begin();
	while(!vec[u].empty()) {
		it = vec[u].begin();
		int e = *it;
		int v;
		if (u == edge[e].v1) {
			v = edge[e].v2;
		}
		else v= edge[e].v1;
			vec[u].erase(e);
			vec[v].erase(e);
			Hierhozer(v);
	}
	ans.push(u);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n + 2; i++) {
		set<int>vv;
		vec.push_back(vv);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[i].v1 = u;
		edge[i].v2 = v;
		vec[u].insert(i);
		vec[v].insert(i);
	}
	int start=1;
	int count1=0;
	for (int i = 1; i <= n; i++) {
		if (vec[i].size() % 2 == 1) {
			count1++;
			start = i;
		}
	}
	if (count1 <= 2) {
		Hierhozer(start);
		cout << "YES" << endl;
		while (!ans.empty()) {
			int to = ans.top();
			ans.pop();
			cout <<to<<" ";
		}
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}