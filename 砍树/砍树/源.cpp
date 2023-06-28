#include <iostream>
#include <vector>
using namespace std;
int n, m;
int m_count[100005];
bool flag = 0;
int anc[100005][21];

struct node {
	int num;
	int depth;
	int parent;
	int parent_path;
	int child_num;
	int mark;
	vector<int>child;
	vector<int>path;

}nod[100005];
/*
int find_com_par(int a, int b) {//找到ab的共同祖先、
	flag = 1;
	//前两种情况下a和b在同一支下，砍断的树只能在ab通路之间 dec
	//其余情况ab在不同枝，砍断的树在a与祖节点之间和b与祖节点之间
	if (nod[a].parent == b) {
		flag = 0;
		return b;
	}
	if (nod[b].parent == a) {
		flag = 0;
		return a;
	}
	if (nod[a].depth > nod[b].depth) {
		return find_com_par(nod[a].parent, b);
	}
	if (nod[a].depth < nod[b].depth) {
		return find_com_par(nod[b].parent, a);
	}
	if (nod[a].depth == nod[b].depth) {
		if (nod[a].parent != nod[b].parent) {
			return find_com_par(nod[b].parent, nod[a].parent);
		}
		else return nod[a].parent;
	}

	return 0;

}
*/

void initial(struct node i) {
	i.num = 0;
	i.mark = 0;
	i.depth = 0;
	i.parent = 0;
	i.parent_path = 0;
	i.child_num = 0;
}

void depth(int a) {
	nod[a].depth = nod[nod[a].parent].depth + 1;
	for (int i = 1; i <= nod[a].child_num; i++) {
		depth(nod[a].child[i - 1]);
	}
	return;
}
inline int read() {
	register char c = getchar();
	register int tmp = 0;
	while (c < '0' || c>'9') c = getchar();
	while (c > '0' - 1 && c < '9' + 1) {
		tmp = (tmp << 1) + (tmp << 3) + c - '0';
		c = getchar();
	}
	return tmp;
}

void dfs(int x, int father) {
	anc[x][0] = father;
	for (int i = 1; i <= 20; i++) {
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	}
	for (int y = nod[x].child_num; y > 0; y--) {
		dfs(nod[x].child[y - 1], x);
	}
	return;
}

int query_lca(int x, int y) {
	if (nod[x].depth < nod[y].depth) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (nod[anc[x][i]].depth >= nod[y].depth)
			x = anc[x][i];
	// 此时有 depth[x] = depth[y]
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (anc[x][i] != anc[y][i])
		{
			x = anc[x][i];
			y = anc[y][i];
		}
	// 注意不等号条件，此时 x, y 一定都是 LCA 的孩子, LCA = anc[x][0] = anc[y][0]
	return anc[x][0];

}
int merge(int x) {
	for (int i = 1; i <= nod[x].child_num; i++) {
		nod[x].mark += merge(nod[x].child[i - 1]);
	}
	return nod[x].mark;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		initial(nod[i]);
	}

	for (int i = 1; i <= n - 1;  i++) {
		int x, y;
		x = read();
		y = read();
		int ma = min(x, y), mi = max(x, y);//ma父节点，mi子节点
		//定义父节点的左右边
		nod[ma].child_num += 1;
		nod[ma].child.push_back(mi);
		nod[ma].path.push_back(i);
		//定义两个节点的num
		nod[ma].num = ma, nod[mi].num = mi;
		//定义父节点
		nod[mi].parent = ma;
		nod[mi].parent_path = i;
	}

	depth(1);
	dfs(1, 0);

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		int con_par = query_lca(x, y);
		nod[x].mark += 1;
		nod[y].mark += 1;
		nod[con_par].mark -= 2;
		/*int con_par = find_com_par(x, y);
		if (flag == 1) {
			while (x != con_par) {
				m_count[nod[x].parent_path]++;
				x = nod[x].parent;
			}
			while (y != con_par) {
				m_count[nod[y].parent_path]++;
				y = nod[y].parent;
			}
		}
		else {
			if(con_par==y)
			while (x != con_par) {
				m_count[nod[x].parent_path]++;
				x = nod[x].parent;
			}
			else {
				while (y != con_par) {
					m_count[nod[y].parent_path]++;
					y = nod[y].parent;
				}
			}
		}*/
	}
	/*bool flag1 = 0;


	for (int i = n; i > 0; i--) {
		if (m_count[i] == m) {
			cout << i << endl;
			flag1 = 1;
			break;
		}
		
	}
	if (!flag1) {
		cout << -1 << endl;
	}*/
	merge(1);
	int max_path = 0;
	for (int i = 1; i <= n; i++) {
		if (nod[i].mark == m) {
			if (nod[i].parent_path > max_path) {
				max_path = nod[i].parent_path;
			}
		}
	}
	if (max_path != 0) {
		cout << max_path << endl;
	}
	else {
		cout << -1<<endl;
	}

	return 0;
}