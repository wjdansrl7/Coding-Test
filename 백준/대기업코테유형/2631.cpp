#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int arr[201];
    int dp[201] = {
        0,
    };
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 0)
        {
            dp[i] = 1;
        }
        for (int j = 1; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    cout << n - *max_element(dp + 1, dp + n + 1) << '\n';

    return 0;
}