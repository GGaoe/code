#include <iostream>
#include <cmath>
#include <algorithm>
int er;
using namespace std;
int m[20001][20001] = {};
int main() {
	int x1, y, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int a = x1 + 10000; int b = y + 10000; int c = x2 + 10000; int d = y2 + 10000;
	int e = x3 + 10000; int f = y3 + 10000; int g = x4 + 10000; int h = y4 + 10000;
	int sum = 0;
	int we, me;
	int wr, wt;
	int x = 0; int p = 0;
	wr = min(b, f);
	wt = max(d, h);
	we = min(a, e);
	me = max(c, g);

	for (int i = a; i <= c; i++) {
		for (int w = b; w <= d; w++) {
			m[i][w]++;
		}
	}//��һ�����һ
	for (int i = e; i <= g; i++) {
		for (int w = f; w <= h; w++) {
			m[i][w]++;
		}
	}//�ڶ������һ
	bool flag = 0;
	for (int i = we; i <= me; i++) {
		for (int w = wr; w <= wt; w++) {
			if (m[i][w] == 1)m[i][w] = 0;
		}
	}//���ཻ�ķ�Χ��0

		for (int i = e; i <= g; i++) {
			for (int w = f; w <= h; w++) {
				if (m[i][w] != 0&&m[i+1][w]!=0&&m[i][w+1]!=0)flag = 1;
			}
		}//֤�����ڽ���
        if (flag) {
		for (int i = we; i <= me; i++) {
			for (int w = wr; w <= wt; w++) {
				if (m[i][w] != 0)
				{
					er = i; break;
				}
			}
		}//�ҵ���һ������x
		for (int w = wr; w <= wt; w++) {
			if (m[er][w] != 0) {
				x++;
			}

		}//���ų���
		for (int i = we; i <= me; i++) {
			for (int w = wr; w <= wt; w++) {
				if (m[i][w] != 0) {
					p++;
				}

			}

		}//�����
		p = p / x;//�г�
		x--; p--;//����
		cout << x * p << endl;//���
	}
		else { cout << 0; }
	return 0;
}