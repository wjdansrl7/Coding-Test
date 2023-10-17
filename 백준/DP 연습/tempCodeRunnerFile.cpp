#include <iostream>
using namespace std;

long long dp[31] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[2] = 3;
    dp[4] = 11;

    for (int i = 6; i < 31; i += 2)
    {
        dp[i] = 2 * dp[i - 2] * dp[2];
    }

    cout << dp[n];

    return 0;
}
