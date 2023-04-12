/*
정답 풀이:
2차원 테이블을 이용한 다이나믹 프로그램이으로 해결해야 한다.
1. 왼쪽 위에서 오는 경우, 2. 왼쪽 아래에서 오는 경우, 왼쪽에서 오는 경우 3가지만 존재
array 변수: 초기 '금광'정보, dp 변수는 다이나믹 프로그램을 위한 2차원 테이블
dp[i][j] = array[i][j] + max(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1])

제약 조건:
dp 테이블에 접근해야 할 때마다 리스트의 범위를 벗어나지 않은지 체크할 필요가 있다. 또한 구현의 편의상
초기 데이터를 담는 array 변수를 사용하지 않고, 바로 dp 테이블에 초디 데이터를 담아서 점화식에 따라서
dp 테이블을 갱신할 수 있다.
*/

#include <iostream>

using namespace std;

int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(int argc, char const *argv[])
{
    // 테스트 케이스(Test Case) 입력
    cin >> testCase;

    for (int tc = 0; tc < testCase; tc++)
    {
        // 금광 정보 입력
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        // 다이나믹 프로그래밍을 위한 2차원 케이블 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = arr[i][j];
            }
        }

        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int leftUp, leftDown, left;
                // 왼쪽 위에서 오는 경우
                if (i == 0)
                {
                    leftUp = 0;
                }
                else
                    leftUp = dp[i - 1][j - 1];
                // 왼쪽 아래에서 오는 경우
                if (i == n - 1)
                {
                    leftDown = 0;
                }
                else
                    leftDown = dp[i + 1][j - 1];
                // 왼쪽에서 오는 경우
                left = dp[i][j - 1];
                dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, dp[i][m - 1]);
        }

        cout << result << '\n';
    }

    return 0;
}
