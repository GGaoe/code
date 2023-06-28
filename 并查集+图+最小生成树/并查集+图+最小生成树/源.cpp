#include <iostream>
#define INF 100001
using namespace std;
int n, m;//����������
int a[1001][1001]={0};
bool flag[1001];//��ǵ��Ƿ��ù�
int ans = 0;//�ܺ�
int minmap[1001];//��Сͼ
int main() {
	cin >> n >> m;
	for (int i = 1; i <= 1000; i++) {
		minmap[i] = INF;
		flag[i] = 0;
		for (int j = 1; j <= 1000; j++) {
			a[i][j] = INF;
	}
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}//��ʼ������
	minmap[1] = 0;
	while (true) {
		int v = 0;
		for (int i = 1; i <= n; i++) {
			if (!flag[i]&&(minmap[i] < minmap[v] || (v == 0))) {
				v = i;
			}
		}
		if (v == 0)break;
		else {
			flag[v] = 1;
			ans += minmap[v];
			for (int i = 1; i <= n; i++) {
				if (!flag[i]&& a[v][i] < minmap[i]) {
					minmap[i] = a[v][i];
				}
			}
		}
		
	}
	cout << ans;
	return 0;
}