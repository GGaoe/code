#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
    // �������������
    srand((unsigned)time(NULL));
    int n;
    cin >> n;
    int a = 1, b = 999;
    // ����[a,b]�������
    
    for(int i=1;i<=2*n;i++)cout << (rand() % (b - a + 1)) + a << endl;
    return 0;
}
