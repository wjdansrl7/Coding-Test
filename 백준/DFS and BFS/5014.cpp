#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define MAXN 1000001

using namespace std;

queue<pair<int, int>> q;
int visited[MAXN];
int f, s, g, u, d;

extern void bfs(int start, int count);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, -1, sizeof(visited));

    cin >> f >> s >> g >> u >> d;

    bfs(s, 0);
}

void bfs(int start, int count)
{
    if (s == g)
    {
        cout << 0 << "\n";
        return;
    }

    q.push({start, count});
    visited[start] = count;

    while (!q.empty())
    {
        int curr = q.front().first;
        int curr_count = q.front().second;
        // cout << curr << " " << curr_count << "\n";

        if (curr == g)
        {
            cout << curr_count << endl;
            return;
        }

        curr_count++;

        q.pop();

        if (curr + u <= f && u > 0)
        {
            if (visited[curr + u] != -1)
            {
                if (visited[curr + u] > curr_count)
                {
                    q.push({curr + u, curr_count});
                    visited[curr + u] = curr_count;
                }
            }
            else
            {
                q.push({curr + u, curr_count});
                visited[curr + u] = curr_count;
            }
        }

        if (curr - d >= 1 && d > 0)
        {
            if (visited[curr - d] != -1)
            {
                if (visited[curr - d] > curr_count)
                {
                    q.push({curr - d, curr_count});
                    visited[curr - d] = curr_count;
                }
            }
            else
            {
                q.push({curr - d, curr_count});
                visited[curr - d] = curr_count;
            }
        }
    }

    cout << "use the stairs"
         << "\n";
}