#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int r, c, n;
char pan[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> piece;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

void BFS(int x, int y)
{
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
            return;
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
    // composing
    sort(piece.begin(), piece.end(), cmp);

    cout << piece.size() << '\n';
    cout << "-------------------'\n";
    for (int i = 0; i < piece.size(); i++)
    {

        cout << piece[i].first << " " << piece[i].second << '\n';
    }

    bool endflag = false;
    while (1)
    {
        for (int i = 0; i < piece.size(); i++)
        {
            if (piece[i].first + 1 < r && pan[piece[i].first + 1][piece[i].second] == '.')
            {
                pan[piece[i].first][piece[i].second] = '.';
                pan[piece[i].first + 1][piece[i].second] = 'x';
                // piece[i].first += 1;
            }
            else
            {
                if (i != 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        piece[j].first -= 1;

                        pan[piece[j].first + 1][piece[j].second] = '.';
                        pan[piece[j].first][piece[j].second] = 'x';
                    }
                    endflag = true;
                    break;
                }
            }
            piece[i].first += 1;
        }

        if (endflag)
        {
            break;
        }
    }
}

// BFS를 돌렸을 떄 2개이상이 나온다는건 미네랄이 두덩이로 분리되었으므로
// 분리된 덩어리중에 바닥과 붙어있지 않는다면 바닥 또는 다른 미네랄과 붙을때까지 아래로 내려간다.
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

    // 막대기를 던진 횟수
    cin >> n;
    vector<pair<int, int>> slice;

    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        int cnt = 0;

        if (i % 2 == 1) // 홀수 -> L -> R
        {
            for (int j = 0; j < c; j++)
            {
                if (pan[r - x][j] == 'x')
                {
                    pan[r - x][j] = '.';
                    int curr_x = r - x;
                    int curr_y = j;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = curr_x + dx[k];
                        int ny = curr_y + dy[k];

                        if (pan[nx][ny] == 'x')
                        {
                            cnt++;
                            slice.push_back({nx, ny});
                        }
                    }
                    if (cnt > 1)
                    {
                        for (auto s : slice)
                        {
                            BFS(s.first, s.second);
                        }
                    }
                    slice.clear();

                    break;
                }
            }
        }
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (pan[r - x][j] == 'x')
                {
                    pan[r - x][j] = '.';
                    int curr_x = r - x;
                    int curr_y = j;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = curr_x + dx[k];
                        int ny = curr_y + dy[k];

                        if (pan[nx][ny] == 'x')
                        {
                            cnt++;
                            slice.push_back({nx, ny});
                        }
                    }
                    if (cnt > 1)
                    {
                        for (auto s : slice)
                        {
                            BFS(s.first, s.second);
                        }
                    }
                    slice.clear();

                    break;
                }
            }
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
