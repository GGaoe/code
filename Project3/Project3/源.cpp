#include <iostream>
#include <cmath>
using namespace std;
#define  maxn  20
int q;
int a[maxn] = { 0 }, b[maxn] = { 0 },c[maxn] = { 0 };//aΪ��������bΪ����cΪ����
int inc(int a[], int n)//������
{
 
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        q = 0;
        for (int m = 0; m< i; m++)
        {
            if (a[m] <= a[i] && q < b[m])
                q = b[m];//����
        }
        b[i] = q + 1;//�����ͼ�һ
    }
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        if (max < b[i])max = b[i];
    }
    return max;//�����������
}
int dec(int a[], int n)//������
{
    for (int i =0;i<n;i++)
    {
        c[0] = 1;
        q = 0;//��ʼ��
        for (int m = 0; m < i; m++)
        {
            if (a[m] >= a[i] && q <c[m])
                q = c[m];//����
        }
        c[i] = q + 1;//�������������ͼ�һ
    }
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        if (max < c[i])max = c[i];
    }
    return max;//����������
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int w = max(inc(a, n), dec(a, n));//��󵥵�
    cout << w<< endl;
    return 0;
}