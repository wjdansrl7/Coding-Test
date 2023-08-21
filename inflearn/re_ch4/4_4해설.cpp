#include <iostream>
#include <string>
using namespace std;
int n, cnt = 0;
void DFS(int s, int e, string res)
{
    if (s > n || e > n || e > s)
        return;
    if (s == n && e == n)
    {
        cout << res << '\n';
        cnt++;
    }
    else
    {
        DFS(s + 1, e, res + '(');
        DFS(s, e + 1, res + ')');
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    DFS(0, 0, "");
    cout << cnt;

    return 0;
}
