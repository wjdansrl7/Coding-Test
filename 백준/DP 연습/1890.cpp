/**
 * @file 1890.cpp
 * @author moongi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
using namespace std;

int n;
int pan[101][101];
long long dp[101][101];
long long res;

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> pan[i][j];
            dp[i][j] = -1;
        }
}

long long DFS(int x, int y)
{
    if (x == n - 1 && y == n - 1)
        return 1;
    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;

    int nx = x + pan[x][y];
    if (nx >= 0 && nx < n && y >= 0 && y < n)
        dp[x][y] += DFS(nx, y);
    int ny = y + pan[x][y];
    if (ny >= 0 && ny < n && x >= 0 && x < n)
        dp[x][y] += DFS(x, ny);
    return dp[x][y];
}

void Solution()
{
    res = DFS(0, 0);
    cout << res;
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
