// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int r, c, n;
char pan[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> piece;

bool check(int x, int y)
{
    // cout << "111" << '\n';
    bool visited[101][101];

    visited[x][y] = true;
    q.push({x, y});
    piece.push_back({x, y});

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        if (xx == r - 1)
        {
            piece.clear();
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c || pan[nx][ny] == '.')
            {
                continue;
            }
            else
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    piece.push_back({nx, ny});
                }
            }
        }
    }

    return false;
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

void composing(vector<pair<int, int>> &piece)
{
    sort(piece.begin(), piece.end(), cmp);

    for (int i = 0; i < piece.size(); i++)
    {
        cout << piece[i].first << " " << piece[i].second << '\n';
    }

    while (1)
    {
        bool endflag = false;
        for (int i = 0; i < piece.size(); i++)
        {
            // piece의 아래가 바닥이 아니면서 비어있는 경우
            if (piece[i].first + 1 < r && pan[piece[i].first + 1][piece[i].second] == '.')
            {
                // pan[piece[i].first + 1][piece[i].second] = 'x';
                pan[piece[i].first][piece[i].second] = '.';

                // piece의 위치변화
                piece[i].first += 1;
            }
            // 바닥에 뭐가 있는 경우
            else
            {
                // 처음 piece부터 위치 다시 되돌리기
                if (i != 0)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        // pan[piece[j].first - 1][piece[j].second] = 'x';
                        pan[piece[j].first][piece[j].second] = '.';
                        piece[j].first -= 1;
                        // pan[piece[j].first-1][]
                    }
                }
                endflag = true;
                break;
            }
        }
        for (int i = 0; i < piece.size(); i++)
        {
            pan[piece[i].first][piece[i].second] = 'x';
        }

        if (endflag)
        {
            piece.clear();
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> pan[i][j];
        }
    }

    cin >> n;

    int h;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> h;

        if (i % 2 == 1) // 홀수
        {
            int curr_x, curr_y;
            for (int j = 0; j < c; j++)
            {
                // 미네랄과 부딫침
                if (pan[r - h][j] == 'x')
                {
                    pan[r - h][j] = '.';
                    curr_x = r - h;
                    curr_y = j;
                    break;
                }
            }
            // 미네랄과 맞닿아있는 미네랄의 개수
            int cnt = 0;

            for (int i = 0; i < 4; i++)
            {
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];

                if (pan[nx][ny] == 'x')
                {
                    cnt++;
                    v.push_back({nx, ny});
                }
            }
            if (cnt >= 2)
            {
                for (auto t : v)
                {
                    // 각각의 연결된 클러스터들이 공중에 떠있는지 확인
                    if (!check(t.first, t.second))
                    {
                        cout << i << '\n';
                        composing(piece);
                    }
                }
            }
            v.clear();
        }
        else // 짝수
        {
            int curr_x, curr_y;
            for (int j = c - 1; j >= 0; j--)
            {
                // 미네랄과 부딫침
                if (pan[r - h][j] == 'x')
                {
                    pan[r - h][j] = '.';
                    curr_x = r - h;
                    curr_y = j;
                    break;
                }
            }
            // 미네랄과 맞닿아있는 미네랄의 개수
            int cnt = 0;

            for (int i = 0; i < 4; i++)
            {
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];

                if (pan[nx][ny] == 'x')
                {
                    cnt++;
                    v.push_back({nx, ny});
                }
            }
            if (cnt >= 2)
            {
                for (auto t : v)
                {
                    // 각각의 연결된 클러스터들이 공중에 떠있는지 확인
                    if (!check(t.first, t.second))
                    {
                        composing(piece);
                    }
                }
            }
            v.clear();
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << pan[i][j];
        }
        cout << '\n';
    }

    return 0;
}
