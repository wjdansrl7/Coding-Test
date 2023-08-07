#include <iostream>
#include <algorithm>
using namespace std;

int dp[46], arr[46];

int main(int argc, char const *argv[])
{
    freopen("in2.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dp[1] = arr[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + arr[i];
    }

    cout << min(dp[n], dp[n - 1]) << '\n';

    return 0;
}
