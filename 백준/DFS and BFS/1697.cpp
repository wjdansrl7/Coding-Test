#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    queue<pair<int, int>> q;
    int visited[100001];

    memset(visited, -1, sizeof(visited));

    cin >> N >> K;

    q.push({N, 0});
    visited[N] = 0;

    while (!q.empty())
    {
        int curr_x = q.front().first;
        int count = q.front().second;
        visited[curr_x] = count;

        if (curr_x == K)
        {
            cout << count << "\n";
            return 0;
        }

        count++;
        q.pop();

        if (curr_x - 1 >= 0 && curr_x - 1 <= 100000)
        {
            if (visited[curr_x - 1] == -1)
            {
                visited[curr_x - 1] = count;
                q.push({curr_x - 1, count});
            }
            else
            {
                if (visited[curr_x - 1] > count)
                {
                    visited[curr_x - 1] = count;
                    q.push({curr_x - 1, count});
                }
            }
        }

        if (curr_x + 1 >= 0 && curr_x + 1 <= 100000)
        {
            if (visited[curr_x + 1] == -1)
            {
                visited[curr_x + 1] = count;
                q.push({curr_x + 1, count});
            }
            else
            {
                if (visited[curr_x + 1] > count)
                {
                    visited[curr_x + 1] = count;
                    q.push({curr_x + 1, count});
                }
            }
        }

        if (curr_x * 2 >= 0 && curr_x * 2 <= 100000)
        {
            if (visited[curr_x * 2] == -1)
            {
                visited[curr_x * 2] = count;
                q.push({curr_x * 2, count});
            }
            else
            {
                if (visited[curr_x * 2] > count)
                {
                    visited[curr_x * 2] = count;
                    q.push({curr_x * 2, count});
                }
            }
        }
    }

    return 0;
}
