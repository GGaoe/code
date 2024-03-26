#include <iostream>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn][2];
int sort[maxn][2];
long long ans = 0;
void merge_sort(int l, int r) {
	if (l == r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int ll = l, rr = mid + 1, point = l;
	while (ll <= mid && rr <= r) {
		if (a[ll] < a[rr]) {
			sort[point][1] = ll;
			sort[point++][0] = a[ll++][0];
		}
		else {
			sort[point][1] = rr;
			sort[point++][0] = a[rr++][0];
		}
	}
	while (ll <= mid) {
		sort[point++][0] = a[ll++][0];
	}
	while (rr <= r) {
		sort[point][1] = rr;
		sort[point++][0] = a[rr++][0];
	}
	for (int i = l; i <= r; i++) {
		a[i][1] = sort[i][1];
		a[i][0] = sort[i][0];
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