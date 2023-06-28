#include <iostream>
using namespace std;
int N, V;
int v_s[550][2];
int map[2][1000500];
int sum;
int previous = 0, current = 1;
void dp() {
	for (int i = 1; i <= sum; i++) {
		map[0][i] = V + 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= sum; j++) {
			if (v_s[i][1] <= j) {
				map[current][j] = min(map[previous][j], map[previous][j - v_s[i][1]] + v_s[i][0]);
			}
			else map[current][j] = map[previous][j];
			
		}
		
		swap(previous, current);
	}
}
int maxx;
int main() {
	cin >> N >> V;
	for (int i = 1; i <= N; i++) {
		cin >> v_s[i][0] >> v_s[i][1];//体积/价值
		sum += v_s[i][1];
	}
	dp();
	for (int i = 1; i <= sum; i++) {
		if (i > maxx && map[previous][i] <= V) {
			maxx = i;
		}
	}
	cout << maxx;

	return 0;
}