#include <iostream>
#include <cmath>
using namespace std;
int n;
int nn = 0;
int prime(int n) {
	if (n == 1)return 0;
	else if (n == 2) {
		nn++; return 0;
	}
	else {
		bool flag = 1;
		for (int i = 2; i <= pow(n, 0.5); i++)
		{
			if (n % i == 0) {
				flag = 0; break;
			}
		}if (flag) {
			nn++; return 0;
		}
		else return 0;
	}
}
bool xuanchu[21] = { 0 };
int  used[21]={0};//ǰһ����ʶһ�����Ƿ��ù�����һ�����ѡ������
int a[21];
int sum;//�����
int k;
int num;
int t = k;//ѡ�����ܺ�
int xs(int k) {
	if (k == 0) {
		sum = 0;
		for (int i = 1; i <= t; i++) {
			sum += used[i]; cout << used[i] << " ";
		}cout << endl;
		prime(sum);
		return 0;
	}
	else {
		if (k == t)num = 1;
		for (int i = 1; i <= n; i++) {
			if (!xuanchu[i]) {
				xuanchu[i] = 1;
				used[num] = a[i];
				num++;
				xs(k - 1);
				xuanchu[i] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> k;
	t = k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	xs(k);
	for (int i = 1; i <= k; i++)
	{
		nn /= i;
	}
	cout << nn;
	return 0;
}