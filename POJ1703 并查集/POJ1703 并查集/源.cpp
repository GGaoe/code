#include <iostream>
using namespace std;
struct UFSetnode {
	int num;
	int parent;
};
class UFSet {
protected:
	int n;
	UFSetnode* tree;
public:
	UFSet(int n);
	int Find(int x);
	void Union(int x, int y);
	int count1();
};

UFSet::UFSet(int n) {
	this->n = n;
	tree = new UFSetnode[n+1];
	for (int i = 1; i <= n; i++) {
		tree[i].parent = i;
	}
}
int UFSet::Find(int x) {
	if (tree[x].parent == x) {
		return x;
	}
	else {
		tree[x].parent = Find(tree[x].parent);
		return tree[x].parent;
	}
}
void UFSet::Union(int x, int y) {
	int findx = Find(x);
	int findy = Find(y);
	if (findx == findy)return;
	else {
		tree[findy].parent = findx;
	}

}
bool flag[3000000];

int UFSet::count1() {
	int numm = 0;
	for (int i = 1; i <= n; i++) {
		int k = UFSet::Find(i);
		if (flag[k] == 0) {
			flag[k] = 1;
			numm++;
		}
	}
	return numm;
}
int main() {
	int n; cin >> n;
	UFSet ufs(n);
	for (int i = 1; i <= n; i++) {
		int person1 = 0, person2 = 0;
		cin >> person1 >> person2;
		ufs.Union(person1, person2);
	}
	cout << n-ufs.count1() << endl;
	return 0;
}