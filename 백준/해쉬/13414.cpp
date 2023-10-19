#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
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
    cin >> k >> l;

    unordered_map<string, int> m;
    vector<pair<string, int>> vv;

    string str;
    for (int i = 0; i < l; i++)
    {
        cin >> str;
        m[str] = i + 1;
    }

    for (auto v : m)
    {
        vv.push_back({v.first, v.second});
    }

    sort(vv.begin(), vv.end(), cmp);

    for (int i = 0; i < k; i++)
    {
        cout << vv[i].first << '\n';
    }

    return 0;
}
