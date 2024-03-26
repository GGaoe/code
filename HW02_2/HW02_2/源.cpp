#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int N;
string B;
string E;
unordered_map<string, int> point;
vector<vector<int>>edge;
vector<int> w;
int num_point = 1;//point¶à1
bool flag[200005];
int min_num[200005];
queue <int> q;
void add_word(string& s) {
	if (point.find(s) == point.end()) {
		point[s] = num_point;
		num_point++;
		vector<int>edge_m;
		edge.push_back(edge_m);
	}
}

void search_edge(string& s) {
	add_word(s);
	int num_1 = point[s];
	for (char& letter : s) {
		char tmp = letter;
		letter = '*';
		add_word(s);
		int num_2 = point[s];
		edge[num_2].push_back(num_1);
		edge[num_1].push_back(num_2);
		letter = tmp;
	}
}

void min_road() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= edge[x].size(); i++) {
			if (flag[edge[x][i - 1]] == 0) {
				min_num[edge[x][i - 1]] = min_num[x] + 1;
				flag[edge[x][i - 1]] = 1;
				q.push(edge[x][i - 1]);
			}
		}if (x == point[E])break;
	}

}

int main() {
	cin >> N >> B >> E;
	edge.push_back(w);
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		search_edge(s);
	}
	search_edge(B);
	num_point--;
	int num_b = point[B];
	int num_e = point[E];
	//cout << num_b << " " << num_e << endl;
	q.push(num_b);
	flag[num_b] = 1;
	min_road();
	cout << min_num[num_e] / 2 + 1 << endl;


	return 0;
}