#include <iostream>
using namespace std;
int flr[53][53];
int m, n;
void csh() {
    cin >> m >> n;
    for (int i = 0; i < 53; i++)
        for (int j = 0; j < 53; j++)
        {
            flr[i][j] = -2;
        }
}
void cinn() {

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> flr[i][j];
        }
}
void coout() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << flr[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }
}
void search() {
    for (int count1 = 1; count1 <= m * n;count1++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (flr[i][j] == 1)
                {
                    for (int q = j; flr[i][q] != 2 && flr[i][q] != -2; q++)
                    {
                        if (flr[i][q] == 0)
                        {
                            flr[i][q] = 1;
                        }
                    }
                    for (int q = j; flr[i][q] != 2 && flr[i][q] != -2; q--) 
                    {
                        if (flr[i][q] == 0)
                        {
                            flr[i][q] = 1;
                        }
                    }
                    for (int q = i; flr[q][j] != 2 && flr[q][j] != -2; q--)
                    {
                        if (flr[q][j] == 0)
                        {
                            flr[q][j] = 1;
                        }
                    }
                    for (int q = i; flr[q][j] != 2 && flr[q][j] != -2; q++) 
                    {
                        if (flr[q][j] == 0)
                        {
                            flr[q][j] = 1;
                        }
                    }
                }
            }
}
int main()
{
    csh();
    cinn();
    search();
    coout();
    return 0;
}
