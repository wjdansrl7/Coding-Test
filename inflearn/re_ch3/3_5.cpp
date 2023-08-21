#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, st_x, st_y, et_x, et_y;
int arr[101][101];
int dist[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> st_x >> st_y;
    cin >> et_x >> et_y;

    q.push({st_x, st_y});
    dist[st_x][st_y] = 2;

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();
    }

    return 0;
}
