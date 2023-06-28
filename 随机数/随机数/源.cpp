#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
    // 生成随机数种子
    srand((unsigned)time(NULL));
    int n;
    cin >> n;
    int a = 1, b = 999;
    // 生成[a,b]的随机数
    
    for(int i=1;i<=2*n;i++)cout << (rand() % (b - a + 1)) + a << endl;
    return 0;
}
