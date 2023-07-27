#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;

void dfs(int L, string str, int r, int l)
{
    if (L == n * 2 && r == n && l == n)
    {
        cout << str << '\n';
        cnt++;
        return;
    }
    else
    {
        if (r < n && r >= l)
        {
            dfs(L + 1, str + '(', r + 1, l);
        }

        if (l < n && r >= l)
        {
            dfs(L + 1, str + ')', r, l + 1);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    // freopen("in5.txt", "r", stdin);
    cin >> n;

    string target = "";
    dfs(0, target, 0, 0);
    cout << cnt << '\n';

    return 0;
}
