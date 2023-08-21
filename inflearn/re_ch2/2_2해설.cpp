#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string s, t;
    int cnt = 0;
    unordered_map<char, int> sH, tH;
    cin >> s >> t;
    for (auto x : t)
        tH[x]++;
    int l = t.size() - 1;
    for (int i = 0; i < l; i++)
        sH[s[i]]++;
    int lt = 0;
    for (int rt = l; rt < s.size(); rt++)
    {
        sH[s[rt]]++;
        if (sH == tH)
            cnt++;
        sH[s[lt]]--;
        if (sH[s[lt]] == 0)
            sH.erase(s[lt]);
        lt++;
    }

    cout << cnt << '\n';

    return 0;
}
