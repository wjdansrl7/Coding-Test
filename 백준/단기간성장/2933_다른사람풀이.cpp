#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int r, c, n;
char map[101][101];
bool visited[101][101];
bool cluster[101][101];
vector<int> order;
vector<pair<int, int>> air_cluster;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void input()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        order.push_back(a);
    }
}

bool throw_stick(int h, int ch)
{
    if (ch == 'L')
    {
        for (int i = 0; i < c; i++)
        {
            if (map[h][i] == 'x')
            {
                map[h][i] = '.';
                return true;
            }
        }
    }
    else
    {
        for (int i = c - 1; i >= 0; i--)
        {
            if (map[h][i] == 'x')
            {
                map[h][i] = '.';
                return true;
            }
        }
    }

    return false;
}

void BFS(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < r && ny < c)
            {
                if (map[nx][ny] == 'x' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

bool clusterInAir()
{
    for (int i = 0; i < c; i++)
    {
        if (map[r - 1][i] == 'x' && !visited[r - 1][i])
        {
            BFS(r - 1, i);
        }
    }

    bool CIA = false;

    memset(cluster, false, sizeof(cluster));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'x' && !visited[i][j])
            {
                CIA = true;
                air_cluster.push_back({i, j});
                cluster[i][j] = true;
            }
        }
    }
    return CIA;
}

int gravity(int x, int y)
{
    int cnt = 0;
    for (int i = x + 1; i < r; i++)
    {
        if (map[i][y] == 'x')
        {
            if (cluster[i][y])
            {
                return INT_MAX;
            }
            else if (map[i][y] == '.')
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void remake_map()
{
    int H = INF - 1;
    for (int i = 0; i < Air_Cluster.size(); i++)
    {
        int x = Air_Cluster[i].first;
        int y = Air_Cluster[i].second;

        int Temp_H = Gravity(x, y);
        if (Temp_H == INF)
            continue;
        else
            H = Min(H, Temp_H);
    }

    sort(Air_Cluster.begin(), Air_Cluster.end());
    for (int i = Air_Cluster.size() - 1; i >= 0; i--)
    {
        int x = Air_Cluster[i].first;
        int y = Air_Cluster[i].second;

        MAP[x][y] = '.';
        MAP[x + H][y] = 'x';
    }
}

void Solution()
{
    for (int i = 0; i < Order.size(); i++)
    {
        Air_Cluster.clear();
        memset(Visit, false, sizeof(Visit));
        memset(Cluster, false, sizeof(Cluster));

        char Order_C;
        int Height = Order[i];
        Height = R - Height;

        if (i % 2 == 0)
            Order_C = 'L';
        else
            Order_C = 'R';

        if (Throw_Stick(Height, Order_C) == false)
            continue;

        if (Cluster_In_Air() == false)
            continue;
        else
            Remake_MAP();
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << MAP[i][j];
        }
        cout << endl;
    }
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
