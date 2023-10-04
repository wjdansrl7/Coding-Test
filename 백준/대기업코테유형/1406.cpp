#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string str;

    cin >> str;

    n = str.size();

    cin >> m;

    char cmd, s;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd;

        if (cmd == 'L')
        {
            if (n != 0)
            {
                n--;
            }
        }
        else if (cmd == 'D')
        {
            if (n != str.size())
            {
                n++;
            }
        }
        else if (cmd == 'B')
        {
            if (n != 0)
            {
                str = str.substr(n);
                n = 0;
            }
        }
        else
        {
            cin >> s;
            str.insert(n, 1, s);
            n++;
        }
    }

    cout << str;

    return 0;
}
