#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, e, q;
    int ss, ee, qq;
    unordered_map<string, int> st;
    unordered_map<string, int> et;
    cin >> s >> e >> q;

    ss = stoi(s.substr(0, s.find(':'))) * 100 + stoi(s.substr(s.find(':') + 1));
    ee = stoi(e.substr(0, e.find(':'))) * 100 + stoi(e.substr(e.find(':') + 1));
    qq = stoi(q.substr(0, q.find(':'))) * 100 + stoi(q.substr(q.find(':') + 1));

    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int uu = stoi(str1.substr(0, str1.find(':'))) * 100 + stoi(str1.substr(str1.find(':') + 1));

        if (uu <= ss)
        {
            st[str2]++;
        }
        else if (uu >= ee && uu <= qq)
        {
            et[str2]++;
        }
    }

    int cnt = 0;

    for (auto v : st)
        if (et[v.first])
            cnt++;

    cout << cnt;

    return 0;
}
