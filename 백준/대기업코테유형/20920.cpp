#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second == b.second)
    {
        if (a.first.size() == b.first.size())
        {
            return a.first < b.first;
        }
        return a.first.size() > b.first.size();
    }

    return a.second > b.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string str;
    map<string, int> en;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str.size() >= m)
            en[str]++;
    }

    vector<pair<string, int>> dict(en.begin(), en.end());
    sort(dict.begin(), dict.end(), cmp);

    for (auto v : dict)
    {
        cout << v.first << '\n';
    }

    return 0;
}
