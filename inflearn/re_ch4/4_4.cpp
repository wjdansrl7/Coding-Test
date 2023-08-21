#include <iostream>
#include <string>
using namespace std;
int n;

void rever(int L, string res, int l, int r)
{
    if (l + r == n * 2)
    {
        cout << res << '\n';
        return;
    }
    else
    {
        if (l < n)
        {
            rever(L + 1, res + '(', l + 1, r);
        }

        if (r < n)
        {
            rever(L + 1, res + ')', l, r + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;

    rever(0, '', 0, 0);

    return 0;
}
