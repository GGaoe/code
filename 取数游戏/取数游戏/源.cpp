#include <iostream>
using namespace std;
int n;
int num[2005];
int start, endd;
int sum_f, sum_k;
void search(int s,int e) {
	if (num[s] >= num[e] && num[s] >= num[s + 1]) {
		s++;

	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> num[i];
	}
	start = 0;
	endd = 2 * n - 1;

}