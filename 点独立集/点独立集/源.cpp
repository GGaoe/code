#include <iostream>
#include <vector>
#define inf 100000000
using namespace std;

int n;

struct node {
	int nub;
	int father;
	int r;
	int num;
	vector<int>son;
}nodes[100005];

int a[100005];

void initial() {
	for (int i = 1; i <= n; i++) {
		nodes[i].father = 0;
		nodes[i].r = 0;
		nodes[i].num = 0;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = inf;
	}
	return;
}

int find_root() {
	for (int i = 1; i <= n; i++) {
		if (nodes[i].num == 0) {
			if (nodes[i].r > 0)
				a[i] = nodes[i].r;
			else a[i] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {

		if (nodes[i].father == 0)return i;
	}
}

int dp(int num) {

	if (a[num] != inf)return a[num];
	else {

		int num1 = 0;
		int num2 = 0;

		//该节点构成的子树，且该节点不在选中的节点中
		for (vector<int>::iterator iter = nodes[num].son.begin(); iter != nodes[num].son.end(); iter++)
		{
			num1 += dp(*iter);
			//cout << dp(*iter) << "  1  " << *iter << endl;
		}

		//该节点构成的子树，且该节点在选中的节点中
		for (vector<int>::iterator iter = nodes[num].son.begin(); iter != nodes[num].son.end(); iter++)
			for (vector<int>::iterator iter1 = nodes[*iter].son.begin(); iter1 != nodes[*iter].son.end(); iter1++)
			{
				num2 += dp(*iter1);// cout << dp(*iter) << "  2  " << *iter << endl;
			}
		num2 += nodes[num].r;
		a[num] = max(num1, num2);
		//cout<< max(a[num], 0)<<endl;
		a[num] = max(a[num], 0);
		return a[num];
	}

}

int main() {
	cin >> n;
	initial();
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i].r;
		nodes[i].nub = i;
	}
	for (int i = 1; i < n; i++) {
		int l, k;
		cin >> l >> k;
		nodes[k].father = l;
		nodes[l].num++;
		nodes[l].son.push_back(k);
	}

	int father = find_root();
	cout << dp(father) << endl;

	return 0;
}