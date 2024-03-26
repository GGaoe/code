#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 10005;
const int INF = 0x3f3f3f3f;

bool flag;
int p, n;
int Mx[MAXN], My[MAXN], Nx, Ny;
int dx[MAXN], dy[MAXN], dis;
bool vst[MAXN];
vector<vector<int>>que;

bool find(int u,int v) {
    for (vector<int>::iterator iter = que[u].begin(); iter != que[u].end(); iter++)
        if (*iter == v)return 1;
    return 0;
}

bool searchP()
{
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof dx);
    memset(dy, -1, sizeof dy);
    for (int i = 1; i <= Nx; ++i)
    {
        if (Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis) break;
        for (int v = 1; v <= Ny; ++v)
        {
            if (find(u,v) && dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1) dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool DFS(int u)
{
    for (int v = 1; v <= Ny; ++v)
    {
        if (!vst[v] && find(u, v) && dy[v] == dx[u] + 1)
        {
            vst[v] = 1;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof Mx);
    memset(My, -1, sizeof My);
    while (searchP())
    {
        memset(vst, 0, sizeof vst);
        for (int i = 1; i <= Nx; ++i)
        {
            if (Mx[i] == -1 && DFS(i))
                ++res;
        }
    }
    return res;
}

int main() {

    cin >> Nx >> Ny;
    for (int i = 1; i <= Nx + Ny+2; i++) {
        vector<int>s;
        que.push_back(s);
    }
    int z;
    cin >> z;
    for (int i = 1; i <= z; i++) {
        int x, y;
        cin >> x >> y;
        que[x].push_back(y);
        que[y].push_back(x);
    }
    cout<<MaxMatch()<<endl;
    return 0;
}