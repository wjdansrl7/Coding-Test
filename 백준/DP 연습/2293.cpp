#include <iostream>
using namespace std;

int dp[10001] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    dp[0] = 1;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = x; j <= k; j++)
            dp[j] += dp[j - x];
    }

    cout << dp[k] << '\n';

    return 0;
}
