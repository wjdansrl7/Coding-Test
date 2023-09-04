#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in5.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> cost(n + 1, 0);
    int dp[45];

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    cout << dp[n];

    return 0;
}
