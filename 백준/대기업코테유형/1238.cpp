// 최단 경로 알고리즘 문제인 다익스트라를 사용하는 것을 알았지만
// 코드를 작성하는데 생각이 떠오르지 않았다.

#include <iostream>
#include <vector>
#include <queue>
#define INF (987654321)
using namespace std;

int n, m, x;

int getMinIdx(int dist[1001], int visited[1001])
{
    int min = -1;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        if (min < 0 || dist[min] > dist[i])
        {
            min = i;
        }
    }

    return min;
}

void dijstra(int arr[1001][1001], int start, int dist[1001])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }

    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_dist = pq.top().first;
        int cur_idx = pq.top().second;
        pq.pop();

        for (int i = 1; i <= n; i++)
        {
            int nxt_dist = cur_dist + arr[cur_idx][i];

            if (nxt_dist < dist[i])
            {
                dist[i] = nxt_dist;
                pq.push({nxt_dist, i});
            }
        }
    }
}

// void dijstra(int arr[1001][1001], int start, int dist[1001])
// {
//     int visited[1001] = {
//         0,
//     };

//     for (int i = 1; i <= n; i++)
//     {
//         dist[i] = arr[start][i];
//     }

//     visited[start] = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         int n_new = getMinIdx(dist, visited);
//         visited[n_new] = 1;

//         for (int j = 1; j <= n; j++)
//         {
//             if (visited[j])
//             {
//                 continue;
//             }

//             if (dist[j] > dist[n_new] + arr[n_new][j])
//             {
//                 dist[j] = dist[n_new] + arr[n_new][j];
//             }
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1001][1001];
    int dist[1001];
    int result[1001][1001] = {
        0,
    };

    cin >> n >> m >> x;

    int st, de, weight;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                arr[i][j] = 0;
            }
            else
                arr[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> st >> de >> weight;

        arr[st][de] = weight;
    }

    for (int i = 1; i <= n; i++)
    {
        dijstra(arr, i, dist);

        if (i != x)
        {
            result[i][x] = dist[x];
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                result[x][i] = dist[i];
            }
        }
    }

    int max = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max < result[i][x] + result[x][i])
        {
            max = result[i][x] + result[x][i];
        }
    }

    cout << max << '\n';

    return 0;
}
