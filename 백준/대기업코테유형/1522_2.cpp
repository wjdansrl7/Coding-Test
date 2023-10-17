#include <iostream>
#include <string>
using namespace std;

int solve(string &s, int x, int len);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cnt = 0;
    ans = (int)1e9;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'b')
            cnt++;

    for (int i = 0; i < s.size(); i++)
        ans = min(ans, solve(s, i, cnt));
    cout << ans;

    return 0;
}

int solve(string &s, int x, int len)
{
    int ret = 0;
    for (int i = x; i < x + len; i++)
        if (s[(i + 1) % s.size()] == 'a')
            ret++;
    return ret;
}
