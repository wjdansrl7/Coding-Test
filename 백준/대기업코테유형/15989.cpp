/*
해당 문제를 DP로 풀어야 한다고는 생각했지만, 점화식을 제대로 구현하지 못하였다.
정수의 합을 오름차순으로 정렬했을 경우
정수 i를 1을 통해서만 구현하는 경우
dp[i][1]
정수 i를 2를 통해서 구현하는 경우
dp[i][2] = dp[i-2][1] + dp[i-2][2]
정수 i를 3을 통해서 구현하는 경우
dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3]
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int num;
    int dp[10001][4] = {
        0,
    };

    for (int i = 0; i < n; i++)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> num;

        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][2] = 1;
        dp[3][1] = 1;
        dp[3][2] = 1;
        dp[3][3] = 1;

        for (int i = 4; i <= num; i++)
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
            dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
        }

        cout << dp[num][1] + dp[num][2] + dp[num][3] << '\n';
    }

    return 0;
}
