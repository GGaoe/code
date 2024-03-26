#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
struct Edge
{
    int u, v, w;
}edge[200005];
int father[5005], ans, eu, ev, cnt;
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int x)
{
    while (x != father[x]) x = father[x] = father[father[x]];
    return x;
}
void kruskal()
{
    sort(edge, edge + m, cmp);
    for (int i = m-1 ; i >=0; i--)
    {
        eu = find(edge[i].u), ev = find(edge[i].v);
        if (eu == ev)
        {
            continue;
        }
        ans += edge[i].w;
        father[ev] = eu;
        if (++cnt == n - 1)
        {
            break;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal();
    cout << ans << endl;
    return 0;
}