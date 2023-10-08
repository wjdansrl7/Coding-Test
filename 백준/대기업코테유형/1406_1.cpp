#include <iostream>
#include <string>
#include <queue>
using namespace std;

deque<char> q1, q2;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        q1.push_back(str[i]);
    }

    int m;
    cin >> m;

    char cmd, s;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!q1.empty())
            {
                int curr = q1.back();
                q1.pop_back();
                q2.push_back(curr);
            }
        }
        else if (cmd == 'D')
        {
            if (!q2.empty())
            {
                int curr = q2.back();
                q2.pop_back();
                q1.push_back(curr);
            }
        }
        else if (cmd == 'B')
        {
            if (!q1.empty())
            {
                q1.pop_back();
            }
        }
        else
        {
            cin >> s;
            q1.push_back(s);
        }
    }

    string res = "";
    while (!q1.empty())
    {
        res += q1.front();
        q1.pop_front();
    }

    while (!q2.empty())
    {
        res += q2.back();
        q2.pop_back();
    }

    cout << res;

    return 0;
}
