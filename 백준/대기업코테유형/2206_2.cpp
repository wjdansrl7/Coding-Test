#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
deque<pair<int, pair<int, int>>> q;

bool visited[1001][1001];

void bfs(int x, int y)
{
    bool visited[1001][1001] = {
        0,
    };

    visited[x][y] = 1;
    q.push_back({x, {y, 1}});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second.first;
        int curr_cnt = q.front().second.second;
        q.pop_front();
        
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    string str;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;

        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = str[j - 1];
        }
    }

    bfs(1, 1);

    return 0;
}
