#include <iostream>
using namespace std;

int dp[31] = {
    0,
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 1;
    dp[2] = 3;

    int n;
    cin >> n;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * dp[2];

        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += 2 * dp[j];
        }
    }

    if (n % 2 == 1)
        cout << 0;
    else
        cout << dp[n];

    return 0;
}
