#include <iostream>
using namespace std;

int dp[31];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[0] = 1;
    dp[2] = 3;

    if (n % 2 == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * dp[2];

        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += 2 * dp[j];
        }
    }

    cout << dp[n];

    return 0;
}
