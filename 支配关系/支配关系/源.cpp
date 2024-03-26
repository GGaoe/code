#include <iostream>
#include <vector>
using namespace std;
#define N 5005
int n;
struct node {
    vector<int>son;
}nodes[N];

bool visited[N];

int  dfs(int u,int n) {
    if (n == u)return 0;
    else if (visited[n] == 1)return 0;
    else visited[n] = 1;
    for (vector<int>::iterator iter = nodes[n].son.begin(); iter != nodes[n].son.end(); iter++)
    {
        dfs(u, *iter);
    }
    return 0; 
}

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    return;
}

int check() {
    int count1 = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i])count1++;
    }
    return count1;
}


int main() {
    int  m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        nodes[u].son.push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        init();
        dfs(i,1);
        cout << n - check()<<" ";
    }
	return 0;
}