#include <iostream>
#include <stack>

using namespace std;
stack<int>a[50005];
int level = 1;
stack<int>behind;
stack<int>map1;
int n;
int num1[50005], num2[50005];


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> num2[i];
	}
	for (int i = n; i >= 1; i--) {
		behind.push(num2[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (num1[i] != behind.top()) {
			a[level++].push(num1[i]);
			map1.push(num1[i]);
		}
		else {
			a[level].push(num1[i]);
			behind.pop();
			//if()
			while(!map1.empty() && !behind.empty()&&map1.top()==behind.top()){
				map1.pop();
				behind.pop();
				level--;
			}
		}
	}
	for (int i = 1; i <= 50004; i++) {
		if (!empty(a[i]))cout << a[i].top() << " ";
		else break;
	}
	return 0;
}