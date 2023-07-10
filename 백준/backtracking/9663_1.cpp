#include <iostream>
#include <vector>
#include <cmath>
// #include <string>
using namespace std;

int n;
vector<int> col;
int res;
// string a;

bool promising(int x)
{
    bool flag = true;
    int idx = 1;
    // string a = "";

    while (idx < x && flag)
    {
        for (int i = 1; i <= idx; i++)
        {
            if (col[i] == col[x] || abs(col[x] - col[i]) == abs(x - i))
            {
                flag = false;
                break;
            }
        }
        idx++;
    }

    return flag;
}

void nQueen(int x)
{
    if (promising(x))
    {
        if (x == n)
        {
            res++;

            // for (int i = 1; i <= n; i++)
            // {
            //     a += to_string(col[i]);
            // }
            // cout << a << '\n';
            // a = "";

            return;
        }

        for (int i = 1; i <= n; i++)
        {
            col[x + 1] = i;
            nQueen(x + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    res = 0;

    cin >> n;

    col.resize(n + 1);

    nQueen(0);
    cout << res << '\n';

    return 0;
}
