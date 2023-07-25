#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
{
    return a.second.second < b.second.second;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);

    int n, m, r;

    cin >> n >> m >> r;

    vector<pair<int, pair<int, int>>> study;
    vector<int> dp(m + 1);

    int st, et, ev;
    int res = INT_MIN;
    study.push_back({0, {0, 0}});
    for (int i = 1; i <= m; i++)
    {
        cin >> st >> et >> ev;
        study.push_back({ev, {st, et}});
    }

    sort(study.begin(), study.end(), cmp);

    for (int i = 1; i <= m; i++)
    {
        dp[i] = study[i].first;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (study[i].second.first >= study[j].second.second + r)
            {
                if (dp[j] + study[i].first > dp[i])
                {
                    dp[i] = dp[j] + study[i].first;
                }
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << '\n';

    return 0;
}
