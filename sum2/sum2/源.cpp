#include <iostream>
using namespace  std;
#define ll long long
ll sum[1000050];
ll add;
int main() {
	int n, q;
	cin >> n >> q;
	sum[0] = 0; 
	int mid=0;
	mid = n / 2;
	for (int i = 1; i <= mid; i++) {
		int vul;
		cin >> vul;
		add += vul;
		sum[i] = add;
	}
	add = 0;
	for (int i = mid + 1; i <= n; i++) {
		int vul;
		cin >> vul;
		add += vul;
		sum[i] = add;
	}
	
	for (int i = 1; i <= q; i++) {
		int ask;
		cin >> ask;
		int s, e;
		cin >> s >> e;
		if (ask == 2) {
			if (s > mid+1) {
				cout << sum[e] - sum[s - 1] << endl;
			}
			else if (e <= mid) {
				cout << sum[e] - sum[s - 1] << endl;
			}
			else if (s == mid + 1) {
				cout << sum[e]<<endl;
			}
			else {
				cout << sum[mid]+sum[e]-sum[s - 1] << endl;
			}
		}
		else {
			int ax,diff;
			if(s!=mid+1)
			ax = sum[s] - sum[s - 1];
			else { ax = sum[s]; }
			diff = ax - e;
			if (s <= mid) {
				for (int j = s; j <= mid; j++) {
					sum[j] -= diff;
				}
			}
			else {
				for (int j = s; j <= n; j++) {
					sum[j] -= diff;
				}
			}
			
		}
	}

	return 0;
}