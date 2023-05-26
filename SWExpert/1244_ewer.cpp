#include <iostream>
#include <string>

using namespace std;

int cnt;
string result;

void bfs(string s, int nCount)
{
    if (nCount == cnt)
    {
        if (result < s)
        {
            result = s;
        }

        return;
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] <= s[j])
            {
                swap(s[i], s[j]);
                bfs(s, nCount + 1);
                swap(s[i], s[j]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input (17).txt", "r", stdin);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n;

        cin >> n >> cnt;

        string s = to_string(n);

        result = s;

        int t = 0;
        if (cnt > s.size() - 1)
        {
            t = cnt - (s.size() - 1);
            cnt = s.size() - 1;
        }

        bfs(s, 0);

        if (t % 2 == 1)
        {
            swap(result[result.size() - 1], result[result.size() - 2]);
        }

        int maxNum = stoi(result);

        cout << "#" << tc + 1 << " " << maxNum << '\n';
    }

    return 0;
}
