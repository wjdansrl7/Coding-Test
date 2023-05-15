/*
문제 자체는 어렵지 않은 것 같았으나 생각하는게 힘들었다. 처음에 직사각형들이 합쳐져서 겉의 테두리만 나타내야 하는데 배열을 통해 표현해야겠다고는 생각했지만, 아이디어가 마땅히 떠오르지 않았다.
따라서 다른 코드를 참고하였다.
참고 코드에서는 각각의 직사각형들에 대해서 모두 값을 채운 다음에 표현해주고, 이후에 직사각형 속을 비우기 위해서 각 직사각형의 꼭짓점이후부터 마지막 꼭짓점 이전까지 값들은 모두 0으로 채우므로서 속이 빈 직사각형의 겉 테두리를
설정하게 되었다.

그러나 만약 이렇게 표현하고 값을 출력한다면 각각의 좌표값이 작다보니 모양이 조금 다르게 나온다. 이 부분을 해결하기 위해 모든 좌표를 2배씩 늘려줌으로써 모양을 크게 표현하고 마지막 결과값에서 2배 해준 것에 대해서 값 / 2 해줌으로써
해결한다.
문제풀이는 bfs를 통하여 끝까지 간 후에 count의 최소를 찾아주었다.
*/

#include <string>
#include <vector>

using namespace std;

int visited[101][101] = {
    0,
};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {
    1,
    -1,
    0,
    0,
};
int answer = 987654321;

void bfs(int x, int y, int destX, int destY, int count)
{
    if (x == destX && y == destY)
    {
        if (answer > count)
        {
            answer = count;
            return;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (visited[x + dx[i]][y + dy[i]] == 1)
        {
            visited[x + dx[i]][y + dy[i]] = 0;
            bfs(x + dx[i], y + dy[i], destX, destY, count + 1);
            visited[x + dx[i]][y + dy[i]] = 1;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;

    // 직사각형 채우기
    for (auto rec : rectangle)
    {
        for (int i = rec[1] * 2; i <= rec[3] * 2; i++)
        {
            for (int j = rec[0] * 2; j <= rec[2] * 2; j++)
            {
                visited[j][i] = 1;
            }
        }
    }

    // 속 비우기
    for (auto rec : rectangle)
    {
        for (int i = rec[1] * 2 + 1; i <= rec[3] * 2 - 1; i++)
        {
            for (int j = rec[0] * 2 + 1; j <= rec[2] * 2 - 1; j++)
            {
                visited[j][i] = 0;
            }
        }
    }

    bfs(characterX, characterY, itemX, itemY, 0);

    return answer / 2;
}