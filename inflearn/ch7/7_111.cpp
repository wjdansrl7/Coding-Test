#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in1.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> arr(n + 2, 0);
    vector<int> dp(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dp[1] = arr[1];

    for (int i = 2; i <= n + 1; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + arr[i];
    }

    cout << dp[n + 1] << '\n';

    return 0;
}
