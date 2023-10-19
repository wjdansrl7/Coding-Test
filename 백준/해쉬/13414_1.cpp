#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second < b.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, l;
    map<string, int> m;
    cin >> k >> l;

    string str;
    for (int i = 0; i < l; i++)
    {
        cin >> str;
        m[str] = i + 1;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    for (auto h : v)
    {
        cout << h.first << '\n';
        cnt++;
        if (cnt == k)
            break;
    }

    return 0;
}
