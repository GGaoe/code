#include <iostream>
using namespace  std;
#define ll long long
ll sum[1000050];
ll add;
int main() {
	int n, q;
	cin >> n >> q;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		int vul;
		cin >> vul;
		add += vul;
		sum[i] = add;
	}
	for (int i = 1; i <= q; i++) {
		int s, e;
		cin >> s >> e;
		cout << sum[e] - sum[s-1]<<endl;
	}
	return 0;
}