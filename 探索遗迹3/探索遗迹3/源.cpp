#include<bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
int s, T, cnt = 1, n, S;
int nxt[1000005], h[1000005], t[1000005], w[1000005];
int deth[1000005], det[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
queue <int> q;

void add(int x, int y, int z)
{
    cnt++;
    t[cnt] = y;
    nxt[cnt] = h[x];
    w[cnt] = z;
    h[x] = cnt;
    cnt++;
    swap(x, y), z = 0;
    t[cnt] = y;
    nxt[cnt] = h[x];
    w[cnt] = z;
    h[x] = cnt;
}
int bfs()
{
    memset(deth, 0, sizeof(deth));
    while (!q.empty()) q.pop();
    deth[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i != -1; i = nxt[i])
        {
            if (w[i] > 0 && deth[t[i]] == 0)
            {
                deth[t[i]] = deth[u] + 1;
                q.push(t[i]);
            }
        }
    }
    if (deth[T] != 0) return 1;
    return 0;
}
int dfs(int u, int dist)
{
    if (u == T) return dist;
    for (int i = h[u]; i != -1; i = nxt[i])
    {
        if ((deth[t[i]] == deth[u] + 1) && (w[i] != 0))
        {
            int di = dfs(t[i], min(dist, w[i]));
            if (di > 0)
            {
                w[i] -= di;
                w[i ^ 1] += di;
                return di;
            }
        }
    }
    return 0;
}
int dinic()//dinic求最大流=最小割 
{
    int ans = 0;
    while (bfs())
    {
        while (int res = dfs(s, INF)) ans += res;
    }
    return ans;
}
int main()
{
    std::cin>>n;
    s = 0, T = n * n + 1;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;
            S += p;
            if ((i + j) % 2 == 1)
            {
                add(s, i * n - n + j, p);
                for (int k = 0; k < 4; k++) 
                {
                    int x = i + det[k][0], y = j + det[k][1];
                    if (x<1 || x>n || y<1 || y>n) continue;
                    add(i * n - n + j, x * n - n + y, INF);
                }
            }
            else add(i * n - n + j, T, p);
        }
    }
    cout << S - dinic();
    return 0;
}