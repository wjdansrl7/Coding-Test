#include <iostream>
#include <queue>
#include <algorithm> // fill

using namespace std;

#define X first  // column
#define Y second // row

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

string maze[1002]; // 공백이 없어서 string으로 받는다.

// 불의 BFS 결과가 지훈에게 영향을 주기 때문에 2개 이용
int visJ[1002][1002];  // 지훈
int visㄹ[1002][1002]; // 불

int m, n;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(falsez);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int, int>> QJ;
    queue<pair<int, int>> QF;

    // 행, 열 차례대로 입력
    cin >> m >> n;

    // 미로를 string으로 받음
    for (int i = 0; i < m; i++)
    {
        cin >> maze[i];
    }

    // 거리초기화(단계 초기화)
    for (int i = 0; i < m; i++)
    {
        fill(visJ[i], visJ[i] + n, -1);
        fill(visF[i], visF[i] + n, -1);
    }

    // 시작점 찾기 - 불, 지훈
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maze[i][j] == 'F')
            {
                QF.push({i, j});
            }
            else if (maze[i][j] == 'J')
            {
                QJ.push(i, j);
                visJ[i][j] = 0;
            }
        }
    }

    return 0;
}
