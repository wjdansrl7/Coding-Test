#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int l, n;
vector<pair<int, int>> v;
int res = INT_MIN;

void dfs(int L, int minAvail, int idx)
{
    int tmp_minAvail = minAvail;
    if (L == l)
    {
        res = max(res, minAvail);
        return;
    }
    else if (L > l)
    {
        return;
    }
    else
    {
        for (int i = idx; i < v.size(); i++)
        {
            L += v[i].first;
            tmp_minAvail = min(tmp_minAvail, v[i].second);
            dfs(L, tmp_minAvail, i + 1);
            L -= v[i].first;
            tmp_minAvail = minAvail;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    cin >> l >> n;

    int pipe, avail;
    for (int i = 0; i < n; i++)
    {
        cin >> pipe >> avail;
        v.push_back({pipe, avail});
    }

    dfs(0, INT_MAX, 0);

    cout << res << '\n';

    return 0;
}
