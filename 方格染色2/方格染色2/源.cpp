#include <iostream>
using namespace std;

const int N = 2600, mod = 998244353;

long long c[N][N];
long long dp[N][N];
int n, m, k;

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
}//求组合数

void dn_p() {
    for (int i = 1; i <= n * m; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * j) % mod;
        }
    }
}//dp，在正常填色情况下，用j种颜色填i个格子的填法数

int main() {
    cin >> n >> m >> k;
    init();
    dn_p();

    long long ans = 0;
    if (n * m == 1) {
        ans = k;
    }
    else {
        int odd = (m * n + 1) / 2;
        int even = m * n - odd;
        for (int i = 1; i < k; i++) {
            for (int j = 1; j <= k - i; j++) {
                ans += ((c[k][i] * dp[odd][i] % mod) * (c[k - i][j] * dp[even][j] % mod) % mod);
                ans %= mod;

            }
        }
    }
    cout << ans << endl;

    return 0;
}