#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    int n;
    vector<pair<int, int>> v;
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    // sort(v.begin(), v.end());
    sort(v.begin(), v.end(), comp);

    for (auto p : v)
    {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}
