//����һ��n ����m ���ߵ�����ͼ����������е�ǿ��ͨ����
//ע�⣬������ܴ����رߺ��Ի���
//��һ������������n ��m ����ʾͼ�ĵ����ͱ�����������m �У�ÿ������������u ��v ��ʾһ���ߡ�
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;
struct node {
	int to, next;
}e[MAXM << 1];
int head[MAXN], num;
bool instack[MAXN];
int s[MAXN], len;
int low[MAXN];
int cnt;
int belong[MAXN];
int n, m;
int f[MAXN];
vector<int>ans[MAXN];
void add(int u, int v) {
	e[++num].to = v;
	e[num].next = head[u];
	head[u] = num;
}
int dfn[MAXN], tot;
void dfs(int x) {
	dfn[x] = low[x] = ++tot;
	s[++len] = x;
	instack[x] = 1;
	for (int i = head[x]; i; i = e[i].next) {
		int y = e[i].to;
		if (!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else {
			if (instack[y])low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x]) {
		cnt++;
		ans[cnt].push_back(x);
		while (s[len] != x) {
			belong[s[len]] = cnt;
			instack[s[len]] = 0;
			ans[cnt].push_back(s[len]);
			len--;
		}
		len--;
		instack[x] = 0;
		belong[x] = cnt;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i])dfs(i);
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; ++i) {
		sort(ans[i].begin(), ans[i].end());
	}
	for (int i = 1; i <= n; ++i) {
		if (f[belong[i]])continue;
		f[belong[i]] = 1;
		for (int j = 0; j < ans[belong[i]].size(); ++j) {
			cout << ans[belong[i]][j] << " ";
		}cout << endl;
	}
	return 0;
}