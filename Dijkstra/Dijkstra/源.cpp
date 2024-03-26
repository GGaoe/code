#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int head[100000], cnt;
long long ans[1000000];
bool vis[1000000];
int m, n, s;
struct edge
{
	int to;
	int nextt;
	int wei;
}edge[1000000];
struct priority
{
	int ans;
	int id;
	bool operator <(const priority& x)const
	{
		return x.ans < ans;
	}
};
void addedge(int x, int y, int z)
{
	edge[++cnt].to = y;
	edge[cnt].wei = z;
	edge[cnt].nextt = head[x];
	head[x] = cnt;
}

priority_queue<priority> q;

int main()
{
	cin >> m >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 2147483647;
	}
	ans[s] = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	int u;
	priority mm = { 0, s };
	q.push(mm);
	while (!q.empty())
	{
		priority temp = q.top();
		q.pop();
		u = temp.id;
		if (!vis[u])
		{
			vis[u] = 1;
			for (int i = head[u]; i; i = edge[i].nextt)
			{
				int v = edge[i].to;
				if (ans[v] > ans[u] + edge[i].wei)
				{
					ans[v] = ans[u] + edge[i].wei;
					if (!vis[v])
					{
						priority vv = { ans[v], v };
						q.push(vv);
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << ' ';
	}
}