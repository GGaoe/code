#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define inf 10005
#define INF 200005

int x,y,z;
struct Edge {
	int u;
	int v;
}edge[INF];

int main() {
	cin >> x >> y >> z;
	for (int i = 1; i <= z; i++) {
		cin >> edge[i].u >> edge[i].v;
	}


	return 0;
}