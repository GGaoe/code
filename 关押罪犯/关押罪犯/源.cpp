#include <iostream>
using namespace std;
int n, m;
bool flag = 0;
int maxn = 0;
struct edge{
	int left_node;
	int right_node;
	int num;
}edge_set[100008],sort[100008];
struct node {
	int parent;
}node_set[40010];
void initial() {
	for (int i = 1; i <= 2 * n; i++) {
		node_set[i].parent = i;
	}
	return;
}
void merge_sort(int l, int r) {
	if (l == r)return;
	int mid = l + r >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int ll = l, rr = mid + 1, point = l;
	while (ll <= mid && rr <= r) {
		if (edge_set[ll].num < edge_set[rr].num) {
			sort[point++] = edge_set[ll++];
		}
		else {
			sort[point++] = edge_set[rr++];
		}
	}
	while (ll <= mid) {
		sort[point++] = edge_set[ll++];
	}
	while (rr <= r) {
		sort[point++] = edge_set[rr++];
	}
	for (int i = l; i <= r; i++) {
		edge_set[i] = sort[i];
	}
	return;
}
int find(int a) {
	if(node_set[a].parent!=a )
	node_set[a].parent = find(node_set[a].parent);
	return node_set[a].parent;
}
int find_par(int a, int b) {
	if (node_set[a].parent == 0 || node_set[b].parent == 0) {
		return 0;
	}
	else {
		if (find(a) != find(b))return 0;
		else return 1;
		}
}
void merge(int num,int a, int b) {
	if (find(a) == find(b)) {
		flag = 1;
		maxn = num;
	}
	node_set[find(a)].parent = find(b+n);
	node_set[find(b)].parent = find(a + n);
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> edge_set[i].left_node >> edge_set[i].right_node >> edge_set[i].num;
	}
	initial();
	merge_sort(1,m);
	/*for (int i = m; i >= 1; i--) {
		cout << edge_set[i].num << endl;
	}*/
	for (int i = m; i>=1; i--) {
		merge(edge_set[i].num, edge_set[i].left_node, edge_set[i].right_node);
		if (flag)break;
	}
	cout << maxn << endl;
	return 0;
}