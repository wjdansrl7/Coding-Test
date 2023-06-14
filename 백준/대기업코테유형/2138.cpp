#include <iostream>
#include <string>
using namespace std;

int n;
int ans = -1;
string str, target;

char change(char c)
{
    if (c == '0')
    {
        return '1';
    }
    else
    {
        return '0';
    }
}

void solve(string str, string target, int start)
{
    int cnt = 0;
    string tmp = str;
    for (int i = start; i < n; i++)
    {
        if (i == 0)
        {
            tmp[0] = change(tmp[0]);
            tmp[1] = change(tmp[1]);
            cnt++;
            continue;
        }

        if (tmp[i - 1] != target[i - 1])
        {
            tmp[i - 1] = change(tmp[i - 1]);
            tmp[i] = change(tmp[i]);
            if (i + 1 != n)
            {
                tmp[i + 1] = change(tmp[i + 1]);
            }
            cnt++;
        }
    }

    if (tmp == target)
    {
        ans = cnt;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    cin >> str >> target;

    solve(str, target, 1);

    if (ans == -1)
    {
        solve(str, target, 0);
    }

    cout << ans << '\n';

    return 0;
}
