#include <iostream>
#include <string>
using namespace std;

char pan[1001][1001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;

        for (int j = 1; j <= n; j++)
            pan[i][j] = str[j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        bool endflag = false;
        for (int j = 1; j <= n; j++)
        {
            if (pan[i][j] == '*')
            {
                x = i + 1;
                y = j;
                endflag = true;
                break;
            }
        }
        if (endflag)
            break;
    }

    // 심장
    cout << x << " " << y << '\n';
    // 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리의 길이
    int la = 0, ra = 0, w = 0, ll = 0, rl = 0;

    for (int i = 1; i < y; i++)
    {
        if (pan[x][i] == '*')
            la++;
    }
    for (int i = y + 1; i <= n; i++)
    {
        if (pan[x][i] == '*')
            ra++;
    }
    int w_x, w_y;
    for (int i = x + 1; i <= n; i++)
    {
        if (pan[i][y] == '*')
        {
            w++;
            w_x = i;
            w_y = y;
        }
    }
    for (int i = w_x + 1; i <= n; i++)
    {
        if (pan[i][w_y - 1] == '*')
            ll++;
    }
    for (int i = w_x + 1; i <= n; i++)
    {
        if (pan[i][w_y + 1] == '*')
            rl++;
    }

    cout << la << " " << ra << " " << w << " " << ll << " " << rl << '\n';
    return 0;
}
