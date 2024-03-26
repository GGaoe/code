#include <iostream>
#include <algorithm>

using namespace std;
int map[2010][2010];
int n, m;
int a[4005][2];
int sort1[4005][2];
struct node {
	int num;
	int val;
}nodes[2005];

int cmp(node x, node y) {
	return(x.val > y.val);
}

void merge_sort(int l, int r) {
	if (l == r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int ll = l, rr = mid + 1, point = l;
	while (ll <= mid && rr <= r) {
		if (a[ll] < a[rr]) {
			sort1[point][1] = ll;
			sort1[point++][0] = a[ll++][0];
		}
		else {
			sort1[point][1] = rr;
			sort1[point++][0] = a[rr++][0];
		}
	}
	while (ll <= mid) {
		sort1[point][1] = ll;
		sort1[point++][0] = a[ll++][0];
	}
	while (rr <= r) {
		sort1[point][1] = rr;
		sort1[point++][0] = a[rr++][0];
	}
	for (int i = l; i <= r; i++) {
		a[i][1] = sort1[i][1];
		a[i][0] = sort1[i][0];
	}
	return;
}

int result = 0;
int b[2005];
int count1;

void greedy() {
	for (int i = 1; i <= n; i++) {
		//int c = a[i][1];
		int c = nodes[i].num;
		int count2 = 0;
		for (int j = 1; j <= n; j++) {
			if (map[c][j]) {
				map[c][j] = 0;
				map[j][c] = 0;
				count2++;
			}
		}
		if (count2) {
			b[++count1] = c;
			result++;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
		a[u][0]++;
		a[v][0]++;
	}
	for (int i = 1; i <= n; i++) {
		nodes[i].num = i;
		nodes[i].val = a[i][0];
	}
	sort(nodes, nodes + n + 1, cmp);
	//merge_sort(1, n);
	//for (int i = 1; i <= n; i++) {
	//	cout << a[i][0] << " " << a[i][1] << endl;
	//}
	greedy();
	std::cout << result << endl;
	for (int i = 1; i <= count1; i++) {
		std::cout << b[i] << " ";

	}


	return 0;
}