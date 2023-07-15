#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    string a, tmp = "";
    int res = 0;

    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
        {
            tmp += a[i];
        }
        else
        {
            if (tmp != "")
            {
                res += stoi(tmp);
                tmp = "";
            }
        }
    }

    if (tmp != "")
    {
        res += stoi(tmp);
    }

    cout << res << '\n';

    return 0;
}
