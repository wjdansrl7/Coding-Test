
// 참고한 풀이: dp를 활용
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int dp[501][501] = {
        0,
    };
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][0] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    for (int i = 0; i < triangle.size(); i++)
    {
        if (answer < dp[triangle.size() - 1][i])
            answer = dp[triangle.size() - 1][i];
    }

    return answer;
}

// 내가 푼 풀이 : bfs를 사용하여 재귀 호출을 통해 가장 최댓값을 구하려고 하였으나, 시간초과가 나서 해결하지 못하였다.
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tri;
int answer = -1;

void bfs(int start_x, int start_y, int sum)
{
    if (start_x == tri.size() - 2)
    {
        if (tri[start_x + 1][start_y] < tri[start_x + 1][start_y + 1])
        {
            sum += tri[start_x + 1][start_y + 1];
            if (sum > answer)
            {
                answer = sum;
            }
        }
        else
        {
            sum += tri[start_x + 1][start_y];
            if (sum > answer)
            {
                answer = sum;
            }
        }
        return;
    }

    bfs(start_x + 1, start_y, sum + tri[start_x + 1][start_y]);
    bfs(start_x + 1, start_y + 1, sum + tri[start_x + 1][start_y + 1]);
}

int solution(vector<vector<int>> triangle)
{
    tri = triangle;

    bfs(0, 0, tri[0][0]);

    return answer;
}