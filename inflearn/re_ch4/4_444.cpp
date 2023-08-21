#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;

void reverse(int l, int r, string res)
{
    if (l > n || r > n || r > l)
    {
        return;
    }

    if (l == n && r == n)
    {
        cout << res << '\n';
        cnt++;
    }
    else
    {
        reverse(l + 1, r, res + '(');
        reverse(l, r + 1, res + ')');
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;

    reverse(0, 0, "");

    return 0;
}
