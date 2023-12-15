#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

char seat[5][5];
int vis[5][5], board[5][5];
int ans = 0;
int pos[25] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

bool bfs(vector<pair<int, int>> v) // v에 담긴 좌표들이 서로 이어져 있는지 학인하는 함수
{
    memset(vis, false, sizeof(vis)); // 방문 표시 배열과 board를 0으로 초기화
    memset(board, false, sizeof(board));

    for (auto c : v)
        board[c.first][c.second] = 1; // 각 좌표들의 위치를 board에 1로 표시

    queue<pair<int, int>> q;           // 인접한 좌표들을 담을 queue
    q.push({v[0].first, v[0].second}); // bfs의 시작점은 첫 번째 좌표
    vis[v[0].first][v[0].second] = 1;  // 시작점에 방문 표시

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            {
                continue;
            }
            if (board[nx][ny] != 1 || vis[nx][ny] == 1)
            {
                continue;
            }
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }

    for (auto c : v)
        if (vis[c.first][c.second] == 0)
        {
            return false;
        }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            seat[i][j] = s[j];
        }
    }

    do
    {
        vector<pair<int, int>> v; // 선택한 좌표를 저장할 vector

        for (int i = 0; i < 25; i++)
        {
            if (pos[i] == 1)
            {
                v.push_back({(i / 5), (i % 5)}); // 선택한 좌표 저장
            }
        }

        bool conn = bfs(v); // bfs로 선택한 좌표들이 이어지는지 확인

        if (conn) // 선택한 좌표들이 이어진다면
        {
            int cnt = 0;
            for (auto c : v)
                if (seat[c.first][c.second] == 'S') // 좌표들 중 'S'의 개수 count
                    cnt++;

            if (cnt >= 4)
                ans++; // 'S'의 개수가 4이상이라면 경우의 수 증가
        }

    } while (next_permutation(pos, pos + 25)); // 25개중 7개 선택(조합 - 순서 고려 X)

    cout << ans;

    return 0;
}
