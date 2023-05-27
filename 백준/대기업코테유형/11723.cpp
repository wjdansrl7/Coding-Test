#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    int s[21] = {
        0,
    };
    cin >> m;

    string command;
    int cmd, x;

    for (int i = 0; i < m; i++)
    {
        cin >> command;

        if (command == "add")
            cmd = 1;
        else if (command == "remove")
            cmd = 2;
        else if (command == "check")
            cmd = 3;
        else if (command == "toggle")
            cmd = 4;
        else if (command == "all")
            cmd = 5;
        else if (command == "empty")
            cmd = 6;
        else
            cmd = 0;

        switch (cmd)
        {
        case 1:
        {
            cin >> x;
            if (s[x] == 0)
            {
                s[x]++;
            }

            break;
        }
        case 2:
        {
            cin >> x;
            if (s[x] > 0)
            {
                s[x]--;
            }
            break;
        }
        case 3:
        {
            cin >> x;
            if (s[x] != 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            break;
        }
        case 4:
        {
            cin >> x;
            if (s[x] != 0)
            {
                s[x]--;
            }
            else
                s[x]++;
            break;
        }
        case 5:
        {
            for (int i = 1; i <= 20; i++)
                if (s[i] == 0)
                {
                    s[i]++;
                }
            break;
        }
        case 6:
        {
            for (int i = 1; i <= 20; i++)
            {
                if (s[i] != 0)
                {
                    s[i]--;
                }
            }

            break;
        }
        default:
            break;
        }
    }

    return 0;
}
