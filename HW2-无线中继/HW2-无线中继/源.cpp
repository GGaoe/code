#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

long long n, C;
struct node {
	int id;
	long long x, y;
	bool operator < (const node& tmp) const {
		if (y != tmp.y) return y < tmp.y;
		return id < tmp.id;
	}
}nodes[100005];
int pre[100005];

bool cmp_x(node one, node two) {
	if(one.x != two.x)
		return one.x < two.x;
	else {
		return one.y < two.y;
	}
}
int find(int x)
{
	if (pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}
void connect(int x, int y)
{
	pre[find(x)] = find(y);
}

int main() {
	cin >> n >> C;
	for (int i = 0; i < n; i++) {
		long long tmp_x, tmp_y;
		cin >> tmp_x >> tmp_y;
		nodes[i].x = tmp_x + tmp_y;
		nodes[i].y = tmp_x - tmp_y;
	}
	sort(nodes, nodes + n, cmp_x);

	for (int i = 0; i < n; i++) {
		nodes[i].id = i;
		pre[i] = i;
	}
	int index_left = 0;
	set<node> se;
	se.insert(nodes[0]);
	for (int index_right=1; index_right < n; index_right++) {//每次进入一个新节点
		while (nodes[index_right].x - nodes[index_left].x > C && index_left<index_right)
		{
			se.erase(nodes[index_left]);
			index_left++;//维护一个C的窗口
		}
		auto it = se.lower_bound({nodes[index_right].id, nodes[index_right].x,nodes[index_right].y - C});
		auto it1 = se.lower_bound({ nodes[index_right].id, nodes[index_right].x,nodes[index_right].y });
		if (it != se.end()&&abs(it->y - nodes[index_right].y)<= C) {
			connect(index_right,it->id);
		}
		if (it1 != se.end() && it!=se.end() && (it1->y - nodes[index_right].y)<=C) {
			connect(index_right,it1->id);
		}
		se.insert(nodes[index_right]);
	}
	long long cnt[100005] = {};
	for (int i = 0; i < n; i++) cnt[find(i)]++;
	long long cnt_ans = 0, max_ans = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] > 0) {
			cnt_ans ++;
			if (cnt[i] > max_ans) max_ans = cnt[i];
		}
	}
	cout << cnt_ans << endl;
	cout << max_ans << endl;
	return 0;
}