#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    string a, b;
    int res = 0;

    cin >> a;

    for (int i = 0; i < a.size(); i++)
    {
        if (isdigit(a[i]))
            b += a[i];
        else
        {
            if (b.size() > 0)
            {
                res += stoi(b);
                b.clear();
            }
        }
    }

    if (b.size() > 0)
    {
        res += stoi(b);
        b.clear();
    }

    cout << res << '\n';

    return 0;
}
