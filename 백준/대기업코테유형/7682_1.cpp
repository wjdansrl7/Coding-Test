#include <iostream>
#include <string>
using namespace std;

int oMap[3][3];
int oMap[3][3];

bool xWin()
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

    if (map[0][0] == map[1][1] == map[2][2] && map[0][0] == 1)
    {
        ret = true;
    }
    if (map[0][2] == map[1][1] == map[2][0] && map[0][2] == 1)
    {
        ret = true;
    }
}

void oWin()
{
}

int main(int argc, char const *argv[])
{
    string soMapoMapoMapoMapoMap

    while (1)
    {

        cin >> str;

        if (oMap== "end")oMapoMapoMapoMap
        {
            break;
        }

        int k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (str[k] == 'X')
                {
                    xMap[i][j] = 1;
                }
                else if (str[k] == 'O')
                {
                    oMap[i][j] = 1;
                }
            }
        }
    }

    return 0;
}
oMap