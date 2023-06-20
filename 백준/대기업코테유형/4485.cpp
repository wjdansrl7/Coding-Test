#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

int n = 1;
int arr[126][126];
int dist[126][126];
bool visited[126][126];
stack<pair<int, pair<int, int>>> stk;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int ans;

// void dfs(int x, int y, int sum)
// {
//     // visited[x][y] = true;
//     // ans += arr[x][y];
//     stk.push({sum, {x, y}});

//     while (!stk.empty())
//     {
//         int curr_x = stk.top().second.first;
//         int curr_y = stk.top().second.second;
//         int curr_sum = stk.top().first;

//         stk.pop();

//         if (curr_x == n - 1 && curr_y == n - 1)
//         {
//             if (curr_sum < ans)
//             {
//                 ans = curr_sum;
//             }
//             continue;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int nx = curr_x + dx[i];
//             int ny = curr_y + dy[i];

//             if (nx < 0 || nx >= n || ny < 0 || ny >= n)
//             {
//                 continue;
//             }
//             else
//             {
//                 stk.push({curr_sum + arr[nx][ny], {nx, ny}});
//             }
//         }
//     }
// }
int main(int argc, char const *argv[])
{
    while (1)
    {
        ans = 987654321;
        // memseet(visited, 0, sizeof(visited));
        cin >> n;
        if (n == 0)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        dfs(0, 0, arr[0][0]);

        cout << ans << '\n';
    }

    // return 0;
}
