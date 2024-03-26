#include <iostream>
using namespace std;
#define ll unsigned long long
#define mod 998244353
int n, m;
ll re;
inline int gcd(int a, int b) {
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}
ll mul(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ans;
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        re = (mul(m, gcd(i, n), mod) + re) % mod;
    }
    for (int i = 1; i <= n; i = i + 2) {
        re += mul(m, n / 2, mod);
        re %= mod;
        re += mul(m, n / 2 + 1, mod);
        re %= mod;
    }
    ll inva = mul(2 * n, mod - 2, mod);
    re *= inva;
    re %= mod;
    cout << re;

    return 0;
}