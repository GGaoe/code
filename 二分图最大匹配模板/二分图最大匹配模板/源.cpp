//给定一个二分图，其左部点的个数为n，右部点的个数为m，边数为e，求其最大匹配的边数。左部点从1 至n 编号，右部点从1 至m 编号。
//输入的第一行是三个整数，分别代表n，m 和e。接下来e 行，每行两个整数u, v，表示存在一条连接左部点u 和右部点v 的边。

#include <iostream>
#include <cmath>	
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#define ri register int
using namespace std;
#define gc getchar
template<class T>void read(T& x) {
    ri f = 1, c; while (c = gc(), c < 48 || 57 < c)if (c == '-')f = -1; x = c ^ 48;
    while (c = gc(), 47 < c && c < 58)x = (x << 3) + (x << 1) + (c ^ 48); x *= f;
}
const int N = 3005, INF = 0x3f3f3f3f;
vector<int> G[N];
int Nx, Ny, k;

int Mx[N], My[N];
int dx[N], dy[N];
int dis, u, v;
bool used[N];
bool searchP() {
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < Nx; ++i)
        if (Mx[i] == -1)    Q.push(i), dx[i] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (dx[u] > dis) break;
        int sz = G[u].size();
        for (int i = 0; i < sz; ++i) {
            int v = G[u][i];
            if (dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (My[v] == -1) dis = dy[v];
                else dx[My[v]] = dy[v] + 1, Q.push(My[v]);
            }
        }
    }
    return dis != INF;
}
bool DFS(int u) {
    int sz = G[u].size();
    for (int i = 0; i < sz; ++i) {
        int v = G[u][i];
        if (!used[v] && dy[v] == dx[u] + 1) {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || DFS(My[v])) {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch() {
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (searchP()) {
        memset(used, false, sizeof(used));
        for (int i = 0; i < Nx; ++i)
            if (Mx[i] == -1 && DFS(i)) ++res;
    }
    return res;
}
int main() {
    read(Nx); read(Ny); read(k);
    while (k--) { read(u); read(v); if (v <= Ny) G[u - 1].push_back(v - 1); }
    printf("%d\n", MaxMatch());
}