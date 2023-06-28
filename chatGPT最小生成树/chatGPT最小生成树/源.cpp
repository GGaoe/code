#include <iostream>
#include <queue>
#define INF 100001
using namespace std;
int n, m;//点数，边数
int a[1001][1001] = { 0 };
bool flag[1001];//标记点是否用过
int ans = 0;//总和
int minmap[1001][1001];//最小图

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct Vertex {
    int id, dist;
    Vertex(int id, int dist) : id(id), dist(dist) {}
    bool operator< (const Vertex& other) const {
        return dist > other.dist;
    }
};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }//初始化矩阵

    for (int i = 1; i <= n; i++) {
        flag[i] = 0;
        for (int j = 1; j <= n; j++) {
            minmap[i][j] = INF;
        }
    }//初始化图

    priority_queue<Vertex> pq;
    pq.push(Vertex(1, 0));

    while (!pq.empty()) {
        Vertex u = pq.top();
        pq.pop();
        if (flag[u.id]) continue;
        flag[u.id] = true;
        ans += u.dist;
        for (int v = 1; v <= n; v++) {
            if (a[u.id][v] > 0) {
                pq.push(Vertex(v, a[u.id][v]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
