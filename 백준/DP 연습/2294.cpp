#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int dp[10001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    set<int> v;
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.insert(x);
    }

    dp[0] = 0;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it <= k)
        {
            dp[*it] = 1;
        }

        for (int i = *it; i <= k; i++)
        {
            if (dp[i - *it] == -1)
            {
                continue;
            }
            else
            {
                if (dp[i] == -1 || dp[i] > dp[i - *it] + 1)
                {
                    dp[i] = dp[i - *it] + 1;
                }
            }
        }
    }

    cout << dp[k];

    return 0;
}
