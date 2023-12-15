/**
 * @file 1520_1.cpp
 * @author 소스 코드 참고
 * @brief
 * @version 0.1
 * @date 2023-12-15
 *
 * 처음 나는 DFS만을 사용하여 시간초과가 발생함. 4^(500*500)
 * 블로그에서는 DFS + memorization을 사용하여 해당 문제를 풀이하였다.
 * DP[a][b] = c -> (a,b)에서 (m-1, n-1)까지의 경우의 수를 저장
 * DP -> -1은 아직 방문하지 않은 것을 의미
 *
 * @copyright https://yabmoons.tistory.com/340 (c) 2023
 *
 */
#include <iostream>
using namespace std;

int n, m, answer;
int map[501][501];
int dp[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
}

int DFS(int x, int y)
{
    if (x == m - 1 && y == n - 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0; // 방문했다는 것을 의미
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
        {
            if (map[nx][ny] < map[x][y])
            {
                dp[x][y] = dp[x][y] + DFS(nx, ny);
            }
        }
    }
    return dp[x][y];
}

void Solution()
{
    answer = DFS(0, 0);
    cout << answer << '\n';
}

void Solve()
{
    Input();
    Solution();
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solve();

    return 0;
}
