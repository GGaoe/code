#include <iostream>
using namespace std;
struct UFSnode {
	int data;
	int rank;
	int parent;
	int relation;
	int total;
};
class UFSet {
protected:
	int n;
	UFSnode* tree;
public:
	UFSet(int n);
	~UFSet();
	int Find(int x);
	void Union(int x, int y);
	int Getanswer();
};

UFSet::UFSet(int n) {
	this->n = n;
	tree = new UFSnode[n];
	for (int i = 0; i < n; i++) {
		tree[i].rank = 1;
		tree[i].parent = i;
		tree[i].total = 1;
		tree[i].relation = 0;
	}
}
UFSet::~UFSet() {
	delete[]tree;
}
int UFSet::Find(int x) {
	int temp = tree[x].parent;
	if (x != tree[x].parent) {
		tree[x].parent = Find(tree[x].parent);
		return tree[x].parent;
	}
	else return x;
}
int UFSet::Getanswer() {
	int r = Find(0);
	return tree[r].total;
}
void UFSet::Union(int x, int y) {
	int findx = Find(x);
	int findy = Find(y);
	if (tree[x].parent == tree[y].parent) {
		return;
	}
	else {
		if (tree[findx].rank > tree[findy].rank) {
			tree[findy].parent = findx;
			tree[findx].total += tree[findy].total;
		}
		else {
			if (tree[findx].rank == tree[findy].rank) {
				tree[findy].rank += 1;

			}
			tree[findx].parent = findy;
			tree[findy].total += tree[findx].total;
			
		}
	}
}
int main() {
	int n = 0;
	int m = 0;
	int person1 = 0, person2 = 0;
	while (cin >> n >> m && n > 0 && m >= 0) {
		UFSet ufs(n);
		for (int i = 0; i < m; i++) {
			int count = 0;
			cin >> count;
			cin >> person1;
			for (int j = 1; j < count; j++) {
				cin >> person2;
				ufs.Union(person1, person2);
				person1 = person2;
			}

		}

		cout << ufs.Getanswer() << endl;
	}
	return 0;
}