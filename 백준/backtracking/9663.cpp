#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;

int n;
int cnt = 0;
bool visited[16][16];
deque<pair<int, int>> q;

void nQueen(int x, int y)
{
    visited[x][y] = true;
    q.push_back({x, y});

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int curr_y = q.front().second;

        q.pop_front();

        if (curr_x == n)
        {
            cnt++;
            continue;
        }

        for (int i = curr_x + 1; i <= n; i++)
        {
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[16][16];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        nQueen(1, i);
    }

    return 0;
}
