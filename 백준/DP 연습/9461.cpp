#include <iostream>
using namespace std;

long dp[101] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    for (int i = 5; i <= 100; i++)
    {
        dp[i] = dp[i - 5] + dp[i - 1];
    }

    while (T--)
    {
        int x;
        cin >> x;

        cout << dp[x] << '\n';
    }

    return 0;
}
