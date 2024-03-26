#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define ll long long
int INF = 1e9;
const int MAXN = 6050;
int n, m;
ll ans;
struct node {
    int to, val;
    bool operator<(const node x)const {
        return val > x.val;
    }
};

vector<node> edge[MAXN];
bool visit[MAXN];
int dis[MAXN], h[MAXN], cnt[MAXN];


bool bellman_ford()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        h[i] = INF;
    }
    h[0] = 0;
    visit[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visit[u] = false;
        for (auto it : edge[u]) {
            int v = it.to, w = it.val;
            if (h[v] > h[u] + w) {
                h[v] = h[u] + w;
                if (visit[v]==0) {
                    visit[v] = 1;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] > n) {
                        return 0;
                    }
                }
            }
        }
    }
    return true;
}

void dijkstra(int s){
    memset(visit,0, sizeof(visit));
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    priority_queue<node> q;
    q.push(node{ s,dis[s] = 0 });
    while (!q.empty()) {
        int u = q.top().to;
        q.pop();
        if (visit[u]) {
            continue;
        }
        visit[u] = true;
        for (auto it : edge[u]) {
            int v = it.to, w = it.val;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(node{ v,dis[v] });
            }
        }
    }
}

void johnson(){
    for (int u = 1; u <= n; u++)
        for (int i = 0; i < edge[u].size(); i++) {
            edge[u][i].val += h[u] - h[edge[u][i].to];
        }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        ans = 0;
        for (int j = 1; j <= n; j++)
            if (dis[j] != INF) {
                dis[j] += h[j] - h[i];
            }
        for (int j = 1; j <= n; j++) {
            ans +=1ll*j * dis[j];
        }
        cout << ans << endl;
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(node{ v,w });
    }
    for (int i = 1; i <= n; i++)
        edge[0].push_back(node{ i,0 });

    if (!bellman_ford()) {
        cout << -1 << endl;
    }
    else johnson();
    return 0;
}