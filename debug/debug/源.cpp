#include <iostream>
using namespace std;
#define ull long long
#define mod 998244353
int n;
ull map[4005][4005];
int lin[200005];
int col[200005];

typedef long long ll;
//快速幂
ll fastPow(ll a, ll b, ll p)
{
	ll ret = 1;
	while (b) {
		if (b & 1)
			ret = (ret * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ret;
}
//费马小定理求逆元fastPow(a,b-2,b)
ll c(ll n, ll m, ll p)
{
	if (m == 0)    return 1;
	//if(m>n-m) m=n-m;
	ll up = 1, down = 1;
	for (int i = 1; i <= m; i++)
	{
		up = (up * (n - i + 1)) % p;
		down = (down * i) % p;
	}
	return up * fastPow(down, p - 2, p) % p;
}
//求C(n,m)%p
ll lucas(ll n, ll m, ll p)
{
	if (m == 0)    return 1;
	return c(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
void dp() {
	for (int i = 1; i <= 4001; i++) {
		for (int j = 1; j <= 4001; j++) {
			map[i][j] += map[i - 1][j] + map[i][j - 1];
			map[i][j] %= mod;

		}
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		lin[i] = a;
		col[i] = b;
		map[2001 - a][2001 - b] += 1;
	}
	dp();
	ull final_result = 0;
	for (int i = 1; i <= n; i++) {
		final_result += map[lin[i] + 2001][col[i] + 2001];
		final_result %= 2 * mod;
		final_result -= lucas(2 * (lin[i] + col[i]), 2 * lin[i], mod);
		if (final_result < 0)final_result += mod;
	}
	final_result *= 499122177;
	final_result %= mod;
	cout << final_result << endl;
	return 0;
}