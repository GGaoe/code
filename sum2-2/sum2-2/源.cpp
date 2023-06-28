#include <iostream>
using namespace std;
#define ll long long
const int maxn = 1000500;
int n;
int input[maxn];
struct node {
		int l, r;
		ll sum;
	}tree[4*maxn];//节点

void build(int left,int right,int index) {
	tree[index].sum = 0;
	tree[index].l = left;
	tree[index].r = right;
	if (left == right)
		return;
	int mid = (right + left) / 2;
	build(left, mid, index * 2);
	build(mid + 1, right, index * 2 + 1);
}//构建线段树

int add(int index) {
	if (tree[index].r == tree[index].l) {
		tree[index].sum = input[tree[index].r];
	}
	else {
		tree[index].sum = add(2 * index)+ add(2 * index + 1);
	}
	return tree[index].sum;
}//算每层的和

void change(int index, int point,int diff) {
	if (tree[index].l <= point && tree[index].r >=point) {//点在该区间内
		tree[index].sum += diff;
		if (tree[index].l == point && tree[index].r == point)return;
		if (tree[2 * index].l <= point && tree[2 * index].r >= point)
		{
			change(2 * index, point, diff);
		}
		else {
			change(2 * index+1, point, diff);
		}	
	}
}

inline int search(int i, int l, int r) {
	if (tree[i].l >= l && tree[i].r <= r) {
		return tree[i].sum;//该层元素全在区间内
	}
	if (tree[i].r<l || tree[i].l>r)return 0;
	int s = 0;
	if (tree[i * 2].r >= l) {
		s += search(i * 2, l, r);
	}
	if (tree[i * 2 + 1].l <= r) {
		s += search(i * 2 + 1, l, r);
	}
	return s;
}

int main() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	build(1, n, 1);
	add(1);
	for (int i = 1; i <= q; i++) {
		int a;
		cin >> a;
		int one, two;
		cin >> one >> two;
		if (a == 1) {
			int diff = 0;
			diff = two-input[one];
			input[one] = two;
			change(1, one, diff);
		}
		else {
			for (int j = 1; j <= 9; j++) {
				//cout << tree[j].sum << " ";
			}//cout << endl;
			cout << search(1, one, two) << endl;
		}
	}
	return 0;
}