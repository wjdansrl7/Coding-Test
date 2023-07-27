#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    int cnt = 0;
    string s, t;
    cin >> s >> t;

    unordered_map<char, int> sh, th;

    for (auto x : t)
    {
        th[x]++;
    }

    for (int i = 0; i < t.size() - 1; i++)
    {
        sh[s[i]]++;
    }

    int j = 0;
    for (int i = t.size() - 1; i < s.size(); i++)
    {
        sh[s[i]]++;
        if (th == sh)
        {
            cnt++;
        }
        sh[s[j]]--;

        if (sh[s[j]] == 0)
        {
            sh.erase(s[j]);
        }
        j++;
    }

    cout << cnt << '\n';

    return 0;
}
