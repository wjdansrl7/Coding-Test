#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int xMap[3][3];
int oMap[3][3];

bool xWin()
{
    bool ret = false;
    for (int i = 0; i < 3; i++)
    {
        if (xMap[i][0] == 1 && xMap[i][0] == xMap[i][1] && xMap[i][1] == xMap[i][2])
        {
            ret = true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (xMap[0][i] == 1 && xMap[0][i] == xMap[1][i] && xMap[1][i] == xMap[2][i])
        {
            ret = true;
        }
    }

    if (xMap[0][0] == xMap[1][1] && xMap[1][1] == xMap[2][2] && xMap[0][0] == 1)
    {
        ret = true;
    }
    if (xMap[0][2] == xMap[1][1] && xMap[1][1] == xMap[2][0] && xMap[0][2] == 1)
    {
        ret = true;
    }

    return ret;
}
bool oWin()
{
    bool ret = false;
    for (int i = 0; i < 3; i++)
    {
        if (oMap[i][0] == 1 && oMap[i][0] == oMap[i][1] && oMap[i][1] == oMap[i][2])
        {
            ret = true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (oMap[0][i] == 1 && oMap[0][i] == oMap[1][i] && oMap[1][i] == oMap[2][i])
        {
            ret = true;
        }
    }

    if (oMap[0][0] == oMap[1][1] && oMap[1][1] == oMap[2][2] && oMap[0][0] == 1)
    {
        ret = true;
    }
    if (oMap[0][2] == oMap[1][1] && oMap[1][1] == oMap[2][0] && oMap[0][2] == 1)
    {
        ret = true;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    while (str != "end")
    {
        bool xxWin = false, ooWin = false;
        int xCnt = 0, oCnt = 0;
        memset(xMap, 0, sizeof(xMap));
        memset(oMap, 0, sizeof(oMap));

        int k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (str[k] == 'X')
                {
                    xMap[i][j] = 1;
                    xCnt++;
                }
                else if (str[k] == 'O')
                {
                    oMap[i][j] = 1;
                    oCnt++;
                }

                k++;
            }
        }

        xxWin = xWin();
        ooWin = oWin();

        if (xxWin && !ooWin && xCnt - oCnt == 1)
        {
            cout << "valid" << '\n';
        }
        else if (!xxWin && ooWin && xCnt == oCnt)
        {
            cout << "valid" << '\n';
        }
        else if (!xxWin && !ooWin && xCnt == 5 && oCnt == 4)
        {
            cout << "valid" << '\n';
        }
        else
        {
            cout << "invalid" << '\n';
        }

        cin >> str;
    }

    return 0;
}
