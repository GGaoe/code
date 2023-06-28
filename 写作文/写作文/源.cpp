#include <iostream>
using namespace std;

int n, k, x;
long long a[100005];
long long sumn[100005]; 
long long sumn1[100005];
long long sumn2[100005];
long long final_result1;
long long final_result2;
void sum() {
	for (int i = 1; i <= n; i++) {
		sumn[i] = sumn[i - 1] + a[i];
		sumn1[i] = sumn[i] - i * x;
		sumn2[i] = sumn[i] + i * x;
	}
	return;
}
void min_num1() {
	long long minnum = 1000000050;
	long long result=-1000000050;
	for (int i = k + 1; i <= n; i++) {
		minnum = min(minnum, sumn1[i - k]);
		long long ans = sumn1[i] - minnum;
		result = max(result, ans);
	}
	final_result1 = result + 2 * k * x;

	return;
}

long long deque[100005];

void min_num2() {
	long long result = -1000000050;
	deque[1] = sumn2[1];
	int l = 1;
	int r = 1;
	for (int i = 2; i <= n; i++) {
		if (i > k) {
			if (deque[l] == sumn2[i - k])l++;
		}
		result = max(result,sumn2[i] - deque[l]);
		while (r - l > -1 && deque[r] > sumn2[i]) {
			r--;
		}
		deque[r + 1] = sumn2[i];
		r++;
		
	}
	final_result2 = result;
	return;
}

int main() {
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sum();
	min_num1();
	min_num2();
	long long result = max(final_result1, final_result2);
	result = max(result,(long long) 0);
	cout << result << endl;

	return 0;
}