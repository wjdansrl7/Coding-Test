// 스티커 - 9465번
/*
n = 1일 때, max(arr[1][1], arr[2][1])

*/

#include <iostream>
#include <cstring>
#define MAXN 100000

using namespace std;

int arr[3][MAXN + 1];
int dp[MAXN + 1];

void solution(int arr[3][MAXN + 1], int n)
{
    dp[1] = max(arr[1][1], arr[2][1]);
    dp[2] = max(arr[1][1] + arr[2][2], arr[1][2] + arr[2][1]);

    cout << "1 " << dp[1] << "\n";
    cout << "2 " << dp[2] << "\n";

    for (int i = 3; i <= n; i++)
    {
        // dp[i] = max(dp[i - 1] + dp[i - 2], arr[1][i - 2] + dp[i - 2]);
        // dp[i] = max(dp[i], dp[i - 2] + arr[2][i]);
        dp[i] = max(dp[i-1]+arr[1][i], dp[i-1] + )

        cout << i << " " << dp[i] << endl;
    }

    cout << dp[n] << "\n";
}

int main(int argc, char const *argv[])
{
    int tc;

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int n;
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        cin >> n;

        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        solution(arr, n);
    }

    return 0;
}
