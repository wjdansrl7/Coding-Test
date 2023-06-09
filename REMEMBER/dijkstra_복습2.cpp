#include <iostream>
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 6
#define INF (987654321)

using namespace std;

int graph[MAX_N][MAX_N] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}};

int getMinIdx(int nodes[MAX_N], int visited[MAX_N])
{
    int min = -1;

    for (int i = 0; i < MAX_N; i++)
    {
        if (visited[i])
        {
            continue;
        }
        if (min < 0 || nodes[min] > nodes[i])
        {
            min = i;
        }
    }
    return min;
}

void dijkstra2(int arr[MAX_N][MAX_N], int start, int dist[MAX_N])
{
    int visited[MAX_N] = {
        0,
    };
    for (int i = 0; i < MAX_N; i++)
    {
        dist[i] = arr[start][i];
    }
    visited[start] = 1;

    for (int i = 0; i < MAX_N - 1; i++)
    {
        int n_new = getMinIdx(dist, visited);
        visited[n_new] = 1;

        for (int j = 0; j < MAX_N; j++)
        {
            if (visited[j])
            {
                continue;
            }
            if (dist[j] > dist[n_new] + arr[n_new][j])
            {
                dist[j] = dist[n_new] + arr[n_new][j];
            }
        }
    }
}