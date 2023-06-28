#include  <iostream>
using namespace std;
const int N = 1e5 + 10;
int m, n;
int p[N];
int find(int x) {
	if (p[x] == x)return p[x];
	else p[x] = find(p[x]);
	return p[x];
}
int main() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		char a; int w, e; cin >> a>>w>>e;
		if (a == 'M')//p[e] = w;
			p[find(w)] = find(e);
		else {
			if (find(w) == find(e))cout << "Yes";
			else cout << "False";
		}
		
	}
	return 0;
}