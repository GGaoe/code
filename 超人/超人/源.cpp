#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M, K;//一天有N个小时，有M件事，有K件必须完成的事

struct task {
	int id;//任务编号
	int must;//是否是必须完成的任务
	int num;//可以选择的时间区间数量
	vector<pair<int, int>>times;//时间区间
};//定义结构体

task t[12];//任务

int count1;//计数器
int max_num;//最大完成的任务
stack<int>intervals;//最大完成任务的选的时间区间
stack<int>intervals_try;//遍历过程中的时间区间
stack<int>tsk;//最大完成任务的选的任务
stack<int>tsk_try;//遍历过程中的选定的任务
bool tim[53];//表示一天中已经被占用的时间
bool over = 0;
void dfs(int i) {
	if (i == M + 1) {
		over = 1;
		if (count1 > max_num) {
			max_num = count1;
			intervals = intervals_try;
			tsk = tsk_try;
		}
	}
	else {
		bool used = 0;
		for (int p =0 ; p < t[i].num; p++) {
			bool flag1 = 1; 
			for (int u = t[i].times[p].first; u < t[i].times[p].second; u++) {
				if (tim[u] == 1) {
					flag1 = 0;
				}
			}
				if (!flag1)continue;
				else {
					for (int o = t[i].times[p].first; o < t[i].times[p].second; o++) {
						tim[o] = 1;
					}
					used = 1;
					count1++;
					tsk_try.push(i);
					intervals_try.push(p+1);
					dfs(i + 1);
					count1--;
					tsk_try.pop();
					intervals_try.pop();
					for (int o = t[i].times[p].first; o < t[i].times[p].second; o++) {
						tim[o] = 0;
					}
				}
			}
		if (!t[i].must)dfs(i + 1);
		else return;
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		t[i].id = i;
		cin >> t[i].num;
		t[i].must = 0;
		for (int j = 1; j <= t[i].num; j++) {
			int s, e;
			cin >> s >> e;
			t[i].times.push_back(make_pair(s, e));
		}
	}
	for (int i = 1; i <= K; i++) {
		int j; cin >> j;
		t[j].must = 1;
	}//初始化数据
	dfs(1);
	if (!over) {
		cout << -1;
	}
	else {
		cout << max_num << endl;
		stack<int> result_tak;
		stack<int> result_time;
		for (int i = 1; i <= max_num; i++) {
			int o = tsk.top();
			tsk.pop();
			result_tak.push(o);
			int u = intervals.top();
			intervals.pop();
			result_time.push(u);
		}
		for (int i = 1; i <= max_num; i++) {
			int o = result_tak.top();
			result_tak.pop();
			cout << o << " ";
			int u = result_time.top();
			result_time.pop();
			cout << u;
			cout << endl;
		}
	}
	return 0;
}