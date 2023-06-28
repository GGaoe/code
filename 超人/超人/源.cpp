#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N, M, K;//һ����N��Сʱ����M���£���K��������ɵ���

struct task {
	int id;//������
	int must;//�Ƿ��Ǳ�����ɵ�����
	int num;//����ѡ���ʱ����������
	vector<pair<int, int>>times;//ʱ������
};//����ṹ��

task t[12];//����

int count1;//������
int max_num;//�����ɵ�����
stack<int>intervals;//�����������ѡ��ʱ������
stack<int>intervals_try;//���������е�ʱ������
stack<int>tsk;//�����������ѡ������
stack<int>tsk_try;//���������е�ѡ��������
bool tim[53];//��ʾһ�����Ѿ���ռ�õ�ʱ��
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
	}//��ʼ������
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