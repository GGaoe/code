#include <iostream>
#include <cmath>
using namespace std;
#define  maxn  20
int q;
int a[maxn] = { 0 }, b[maxn] = { 0 },c[maxn] = { 0 };//a为输入数，b为增序，c为减序
int inc(int a[], int n)//增序数
{
 
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        q = 0;
        for (int m = 0; m< i; m++)
        {
            if (a[m] <= a[i] && q < b[m])
                q = b[m];//遍历
        }
        b[i] = q + 1;//序数和加一
    }
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        if (max < b[i])max = b[i];
    }
    return max;//返回最大增序
}
int dec(int a[], int n)//减序数
{
    for (int i =0;i<n;i++)
    {
        c[0] = 1;
        q = 0;//初始化
        for (int m = 0; m < i; m++)
        {
            if (a[m] >= a[i] && q <c[m])
                q = c[m];//遍历
        }
        c[i] = q + 1;//合条件，序数和加一
    }
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        if (max < c[i])max = c[i];
    }
    return max;//返回最大减序
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int w = max(inc(a, n), dec(a, n));//最大单调
    cout << w<< endl;
    return 0;
}