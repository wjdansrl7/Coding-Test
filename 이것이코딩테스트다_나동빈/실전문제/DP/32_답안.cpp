/*
Q31 금광 문제와 유사,
특정한 위치로 도달하기 위해서는
1. 왼쪽 위,
2. 바로 위
2가지 위치에서만 내려올 수 있다. 따라서 모든 위치를 기준으로 이전 위치로 가능한 2가지
위치까지의 최적의 합 중에서 더 큰 값을 가지는 경우를 선택하면 된다.

dp[i][j] = array[i][j] + max(dp[i-1][j-1], dp[i-1][j])
*/

#include <iostream>

int n;
int dp[500][500]; // 다이나믹 프로그래밍을 위한 DP 테이블 초기화

int main(int argc, char const *argv[])
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dp[i][j];
        }
    }

    // 다이나믹 프로그래밍으로 2번째 줄부터 내려가면서 확인
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int upLeft, up;
            // 왼쪽 위에서 내려오는 경우
            if (j == 0)
                upLeft = 0;
            else
                upLeft = dp[i - 1][j - 1];
            // 바로 위에서 내려오는 경우
            if (j == i)
                up = 0;
            else
                up = dp[i - 1][j];
            // 최대 합을 저장
            dp[i][j] = dp[i][j] + max(upLeft, up);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[n - 1][i]);
    }

    cout << result << '\n';

    return 0;
}
