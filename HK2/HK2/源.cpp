#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
const int MAXN = 10005;
const int INF = 1 << 28;
int cx[MAXN];
int cy[MAXN]; 
int nx, ny;
int dx[MAXN];
int dy[MAXN];
int dis;
bool bmask[MAXN];
bool map[10005][10005];


bool searchpath()
{
    queue<int>Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= nx; i++)
    {
        if (cx[i] == -1)
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
        for (int v = 1; v <= ny; v++)
        {
            if (map[u][v] && dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (cy[v] == -1) dis = dy[v];  
                else                 
                {
                    dx[cy[v]] = dy[v] + 1;
                    Q.push(cy[v]);
                }
            }
        }
    }
    return dis != INF;
}
int findpath(int u)
{
    for (int v = 1; v <= ny; v++)
    {
        if (!bmask[v] && map[u][v] && dy[v] == dx[u] + 1)
        {
            bmask[v] = 1;
            if (cy[v] != -1 && dy[v] == dis) 
            {
                continue;
            }
            if (cy[v] == -1 || findpath(cy[v])) 
            {
                cy[v] = u; cx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int res = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    while (searchpath())   
    {
        memset(bmask, 0, sizeof(bmask));
        for (int i = 1; i <= nx; i++)
        {
            if (cx[i] == -1)
            {
                res += findpath(i);
            }
        }
    }
    return res;
}
int main()
{
        cin >> nx >> ny;
        int z;
        cin >> z;
        for (int i = 1; i <= z; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
            map[y][x] = 1;
        }
        cout<<MaxMatch()<<endl;
    return 0;
}