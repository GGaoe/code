#include <iostream>
#include <iostream>
#include<string.h>
using namespace std;
#define MAXD 10001
int max3;
int max2;
int i, j;
int k1, k2, len1, len2;
int chuli() {
    if (k1 > k2) {
        max3 = k1;
    }
    else max3 = k2;
    if (len2 > len2)
        max2 = len1;
    else max2 = len2;
    return 0;
}
int  flag = 1;
char str1[MAXD] = { '0' };
char str2[MAXD] = { '0' };
int a[MAXD] = { 0 };
int b[MAXD] = { 0 };
int cut[MAXD] = { 0 };
int add[MAXD] = { 0 };
int read() {
    if (len1 == k1)
        for (i = len1 - 1; i >= 0; i--)
        {
            a[j++] = str1[i] - '0';
        }
    else
    {
        for (i = len1 - 1; i >= 1; i--)
        {
            a[j++] = str1[i] - '0';
        }
    }
    j = 0;
    if (len2 == k2)
        for (i = len2 - 1; i >= 0; i--)
        {
            b[j++] = str2[i] - '0';
        }
    else
        for (i = len2 - 1; i >= 1; i--)
        {
            b[j++] = str2[i] - '0';
        }
    if (len1 > k1 && len2 == k2)
        flag = -1;
    if (k1 > k2)
        flag = 1;
    else if (k1 == k2)
    {
        int k = k1;
        while (a[k] == b[k] && k >= 0)
            k--;
        if (a[k] > b[k])
            flag = 1;
        else if (a[k] == b[k])
            flag = 0;
        else flag = -1;

    }
    else flag = -1;
    return 0;
}
int addd() {
    for (i = 0; i <= max3; i++)
    {
        add[i] = add[i] + a[i] + b[i];
        if (add[i] >= 10)
        {
            add[i] -= 10;
            add[i + 1] += 1;
        }
    }return 0;
}
int cutt() {
    for (i = 0; i <= max3; i++)
    {
        if (flag == 1)
        {
            a[i] -= b[i];
            if (a[i] < 0)
            {
                a[i] += 10;
                a[i + 1] -= 1;
            }
            cut[i] = a[i];
        } 
        else {
            b[i] -= a[i];
            if (b[i] < 0)
            {
                b[i] += 10;
                b[i + 1] -= 1;
            }
            cut[i] = b[i];
        }
            
    }return 0;
}
int main()
{

    bool flag1 = false;
    cin >> k1 >> str1;
    cin >> k2 >> str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    j = 0;
    chuli();
    read();
    addd();
    cutt();
    if (k1 == len1 && k2 == len2)
    {
        if (add[max3] != 0)
        {
            cout << add[max3];
        }
        for (i = max3 - 1; i >= 0; i--)
        {
            cout << add[i];
        }
        cout << endl;
        if (flag == -1)
            cout << '-';
        if (cut[max3] != 0)
        {
            cout << cut[max3];
        }
        for (int i = 0; i <= max3; i++)
            if (cut[i] != 0)
            {
                flag1 = true;
            }
        if (flag1)
        {
            for (i = i = max3 - 1; i >= 0; i--)
                if (cut[i] != 0)
                    break;

            for (; i >= 0; i--)
            {
                cout << cut[i];
            }
        }
        else
            cout << '0';
    }
    else if (k1 != len1 && k2 != len2)
    {
        cout << '-';
        if (add[max3] != 0)
        {
            cout << add[max3];
        }
        for (i = max3 - 1; i >= 0; i--)
        {
            cout << add[i];
        }
        cout << endl;
        if (flag == 1)
            cout << '-';
        for (int i = 0; i <= max3; i++)
            if (cut[i] != 0)
            {
                flag1 = true;
            }
        if (flag1)
        {
            for (i = i = max3 - 1; i >= 0; i--)
                if (cut[i] != 0)
                    break;

            for (; i >= 0; i--)
            {
                cout << cut[i];
            }
        }
        else
            cout << '0';
    }
    else if (k1 != len1 && k2 == len2)
    {
        for (int i = 0; i <= max3; i++)
            if (cut[i] != 0)
            {
                flag1 = true;
            }
        if (flag1)
        {
            for (i = i = max3 - 1; i >= 0; i--)
                if (cut[i] != 0)
                    break;

            for (; i >= 0; i--)
            {
                cout << cut[i];
            }cout << endl;
        }
        else
            cout << '0' << endl;
        cout << '-';
        if (flag == 1)
            cout << '-';
        if (add[max3] != 0)
        {
            cout << add[max3];
        }
        for (i = max3 - 1; i >= 0; i--)
        {
            cout << add[i];
        }
    }
    else
    {
        if (flag == -1)
            cout << '-';
        for (int w = 0; w <= max3; w++)
            if (cut[w] != 0)
            {
                flag1 = true;
            }
        if (flag1)
        {
            for (i = i = max3 - 1; i >= 0; i--)
                if (cut[i] != 0)
                    break;

            for (; i >= 0; i--)
            {
                cout << cut[i];
            }
        }
        else
            cout << '0';
        cout << endl;
        if (add[max3] != 0)
        {
            cout << add[max3];
        }
        for (i = max3 - 1; i >= 0; i--)
        {
            cout << add[i];
        }
    }
    return 0;
}