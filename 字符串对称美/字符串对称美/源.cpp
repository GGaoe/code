#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
//ToDo
char str[10000];
int n;
char* GetStrings()
{
    char* s;
    s = str;
    char m;
    for (int i = 0;i<n; i++) {
        cin >> m; *(s + i) = m;
    }
    return s;
}
//ToDo
//Attention!! str_list[i] is forbidden!!
bool flag=1;
void Func(char* str_list)
{
    for (int i = 0; i <n; i++) {
        flag = 1;
        for (int k = 0; k <=n / 2; k++) {
            if (*(str_list + k) != *(str_list +n - 1 - k)) {
                flag = 0; break;
            }
        }
        if (flag)break;
        else {
            char b = *(str_list +n - 1);
            for (int j = n - 1; j >= 1; j--) {
                *(str_list + j) = *(str_list + j - 1);
            }*(str_list) = b;
        }
    }
}

int main()
{
    cin >> n;
    char* str_list = GetStrings();
    Func(str_list);
    if (flag) {
        for (int i = 0; i < n; i++) {
            cout << *(str_list + i) << " ";
        }
    }
    else cout << "False";
    return 0;
}