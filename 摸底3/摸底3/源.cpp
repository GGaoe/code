#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int N = 500 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
ll g[N][N];
int n, m;
int main()
{
    scanf_s("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i <= n; i++)
        g[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        ll z;
        scanf_s("%d%d%lld", &x, &y, &z);
        g[x][y] = min(g[x][y], z);
    }
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            printf("%lld ", g[i][j] >= inf ? -1 : g[i][j]);
        printf("\n");
    }
    return 0;
}
