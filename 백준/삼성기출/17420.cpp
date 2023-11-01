#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a, b;
    vector<pair<ll, ll>> c;

    ll x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        b.push_back(y);
    }

    for (int i = 0; i < n; i++)
    {
        c.push_back({a[i], b[i]});
    }

    sort(c.begin(), c.end(), cmp);

    long long maxDay = INT_MIN;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        while (c[i].first < c[i].second || c[i].first < maxDay)
        {
            res++;
            c[i].first += 30;

            maxDay = max(maxDay, c[i].first);
        }
    }

    cout << res;

    return 0;
}
