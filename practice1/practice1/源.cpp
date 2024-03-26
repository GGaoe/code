#include <iostream>
#include <stack>
using namespace std;
int n, m;

struct node {
	stack<int>num;

}nodes[100005];

int main() {
	int a, b;
	cin >> a >> b;

	swap(a, b);
	cout << a << b;
	return 0;
}