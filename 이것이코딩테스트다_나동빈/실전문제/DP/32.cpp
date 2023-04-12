/*
정수 삼각형: 1932
나의 풀이:
dp 테이블에 array 값을 초기화하고, 임의의 i행 j열에 있는 dp[i][j]의 최댓값을
구하기 위해서는 이전 (i-1, j-1), (i-1, j)행에 있는 dp 값 중 최댓값을 선택하고
기존 array[i][j]의 값을 더해줘서 최댓값을 구해준다.
마지막 행에서는 가장 큰 값을 찾기 위해 비교하였다.

내가 작성한 점화식:
dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);

*/

#include <iostream>
#include <cstring>

using namespace std;

int arr[501][501];
int dp[501][501];

int main(int argc, char const *argv[])
{
    int n;
    memset(arr, -1, sizeof(arr));

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    int maxValue;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i - 1 < j)
            {
                maxValue = 0;
            }
            else
            {
                maxValue = dp[i - 1][j];
            }

            dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], maxValue);
        }
    }

    int result = dp[n][1];

    for (int i = 2; i <= n; i++)
    {
        if (dp[n][i] > result)
        {
            result = dp[n][i];
        }
    }

    cout << result << '\n';

    // 점화식
    // dp[i][j] = arr[i][j] + max(dp[i-1][j-1], dp[i-1][j]);

    return 0;
}
