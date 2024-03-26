#include<iostream>
using namespace std;
#define MOD 10000079
int pow_mod(int a, int n, int m)
{
    if (n == 0) return 1;
    int x = pow_mod(a, n / 2, m);
    long long ans = (long long)x * x % m;
    if (n % 2 == 1) ans = ans * a % m;
    return (int)ans;
}
int main()
{
    int n;
    cin >> n;
    long long tmp = 1;
    if (n > MOD)cout << 0 << endl;
    else {
        for (int i = 1; i <= n - 1; i++) {
            tmp *= i;
            tmp %= MOD;
        }
        cout << tmp << endl;
    }
    cout << pow_mod(2, n-1, MOD)<<endl;
}