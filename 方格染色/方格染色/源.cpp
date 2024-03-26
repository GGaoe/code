#include <iostream>

using namespace std;
typedef long long LL;

const int N = 2550, mod = 998244353;
int fact[N], infact[N];
int n, m, k;

LL aa[1300];

LL qmi(LL a, int k, int p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

LL qpow(LL a, LL n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1) * a % mod;
    else
    {
        LL temp = qpow(a, n / 2) % mod;
        return temp * temp % mod;
    }
}

int main()
{
    //预处理阶乘和阶乘的逆元
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod; //这里是关键，把组合数的公式转化为乘法形式
    }

    cin >> n >> m >> k;
    int j, o;
    if (n * m % 2 == 1) {
        j = n * m / 2 + 1;
        o = n * m / 2;
    }
    else { 
        j = n * m / 2; 
        o = n * m / 2;
    }
    LL result = 0;
    for (int i = k - 1; i > 0; i--) {
        LL tmp = 0;
        tmp = ((((LL)fact[k] * infact[k - i] % mod * infact[i] % mod) * qpow(i, j) % mod) * qpow(k - i, o) % mod);
        if ((((k % 2 == 1)&& (i > (k) / 2))|| ((k % 2 == 0) && (i >= (k) / 2)))&&i != 1 && i != k - 1)tmp+= ((((((LL)fact[k] * infact[k - i] % mod * infact[i] % mod) * (k - i))%mod *i) % mod * qpow(i-1, j) % mod) * qpow(k - i - 1, o) % mod);
        LL tmp1 = 0;
        tmp %= mod;
        //cout << tmp << endl;
        if(i!=1)tmp1+= (((((LL)fact[k] * infact[k - i] % mod * infact[i] % mod) * i ) % mod * qpow(i-1, j) % mod) * qpow(k - i, o) % mod);
        if(i!=k-1)tmp1+= (((((LL)fact[k] * infact[k - i] % mod * infact[i] % mod) * (k-i)) % mod * qpow(i, j) % mod) * qpow(k - i - 1, o) % mod);
        //cout <<i<<" "<< (LL)fact[k] * infact[k - i] % mod * infact[i] % mod << "  " << qpow(i, j) << "  " << qpow(k - i, o) << endl;
        result += tmp;
        if(k%2==1)if(i>(k)/2)result -= tmp1;
        else { if (i >= (k) / 2)result -= tmp1; }
        //cout << tmp1 << endl;
        if (result < 0)result += mod;
        result %= mod;
    }
    cout << result;

    return 0;
}