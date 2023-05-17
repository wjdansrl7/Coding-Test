#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans, change;
string s;

void dfs(int index, int current)
{
    if (current == change)
    {
        ans = max(ans, stoi(s));
        return;
    }

    for (int i = index; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            dfs(i, current + 1);
            swap(s[i], s[j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("input (17).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        cin >> s >> change;
        ans = 0;

        // if (change > s.size())
        // {
        //     change = s.size() - 1;
        // }
        dfs(0, 0);
        cout << "#" << tc + 1 << " " << ans << '\n';
    }

    return 0;
}
