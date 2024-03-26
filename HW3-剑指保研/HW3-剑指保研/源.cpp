#include <iostream>
#include <vector>
using namespace std;
int n;
int q;
struct node {
	int id;
	int num;
	int order;
	int order_num;
	int son_num;
	vector<int>vec;
}nodes[500005];

void dfs(int id,int ord,int ord_num) {
	for (int i = 0; i < nodes[id].son_num; i++) {
		int tmp = nodes[id].vec[i];
		if (nodes[tmp].order > ord) {
			nodes[tmp].num = nodes[tmp].order_num;
			dfs(tmp, nodes[tmp].order, nodes[tmp].order_num);
		}
		else {
			if(ord_num)nodes[tmp].num = ord_num;
			dfs(tmp, ord,ord_num);
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		nodes[i].id = i;
		nodes[i].num = 0;
		nodes[i].order = 0;
		nodes[i].order_num = 0;
		nodes[i].son_num = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin>>nodes[i].num;
	}
	for (int i = 1; i < n; i++) {
		int tmp;
		cin >> tmp;
		nodes[tmp].son_num++;
		nodes[tmp].vec.push_back(i + 1);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x].order = i;
		nodes[x].order_num = y;
	}
	if(nodes[1].order)nodes[1].num = nodes[1].order_num;
	dfs(1,nodes[1].order,nodes[1].order_num);
	for (int i = 1; i <= n; i++) {
		cout << nodes[i].num << " ";
	}

	return 0;
}