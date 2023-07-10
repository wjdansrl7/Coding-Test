#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[50001] = {
    0,
},
    n = 0;
int won, cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 3;

    while (t--)
    {
        int sum = 0;
        vector<pair<int, int>> vec;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> won >> cnt;
            vec.push_back(make_pair(won, cnt));
            sum += won * cnt;
        }
        if (sum % 2 == 1)
        {
            cout << 0 << endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 50000; j >= vec[i].first; j--)
            {
                if (dp[j - vec[i].first] == 1)
                {
                    for (int k = 0; k < vec[i].second && (j + k * vec[i].first) <= 50000; k++)
                    {
                        dp[j + k * vec[i].first] = 1;
                    }
                }
            }

        if (dp[sum / 2] == 1)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}