#include <iostream>
#include <algorithm>
#define ull unsigned long long
using namespace std;
int k;
int n;
ull a[100005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0;
    ull r = a[n - 1];
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int re_num = 0;
        int current = 0;
        for (int i = 1; i < n; i++) {
            current += a[i] - a[i - 1];
            if (current < mid)re_num++;
            else current = 0;
        }
        if (re_num > k)r = mid - 1;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}