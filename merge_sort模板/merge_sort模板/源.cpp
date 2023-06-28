#include <iostream>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn];
int sort[maxn];
long long ans = 0;
void merge_sort(int l, int r) {
	if (l == r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int ll = l, rr = mid + 1, point = l;
	while (ll <= mid && rr <= r) {
		if (a[ll] < a[rr]) {
			sort[point++] = a[ll++];
		}
		else {
			sort[point++] = a[rr++];
		}
	}
	while (ll <= mid) {
		sort[point++] = a[ll++];
	}
	while (rr <= r) {
		sort[point++] = a[rr++];
	}
	for (int i = l; i <= r; i++) {
		a[i] = sort[i];
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	merge_sort(0, n - 1);
	return 0;
}