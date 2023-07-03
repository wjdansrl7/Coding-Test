/*
다익스트라 알고리즘 - 최단 경로 탐색 알고리즘
특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로

그래프의 모든 간선이 0이상의 cost를 가져야 다익스트라 알고리즘을 사용할 수 있다.
또한 그래프에서 연결되지 않는 간선의 가중치는 INF로 표현하여 다익스트라 알고리즘을 사용하면 편하다.
하나의 최단 거리는 다른 여러 개의 최단 거리로 이루어져 있기 떼문에
하나의 최단 거리를 구할 때 그 이전까지 구했던 최단 거리 정보를 그대로 사용하여 구하므로 다이나믹 알고리즘 방식과
유사하다.

2.2 동작 단계
1. 출발 노드를 설정한다.
2. 최단 거리 테이블(dist)을 초기화한다.
3. 현재 위치한 노드의 인접 노드 중 방문하지 않은 노드를 구별하고, 방문하지 않은 노드 중 거리가 가장 짧은 노드를 선택한다.
4. 해당 노드를 거쳐 다른 노드로 넘어가는 간선 비용(가중치)를 계산해 '최단 거리 테이블'을 업데이트 한다.
5. 1~4 과정을 반복한다.

최단 거리 테이블은 1차원 배열로 start에서 N개 노드까지 가는 데 필요한 최단 거리를 기록한다.

*/

#include <iostream>
#include <stdio.h>
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

int getMindIdx(int nodes[MAX_N], int visited[MAX_N])
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

// sequential search
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
        int n_new = getMindIdx(dist, visited);
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

// priority queue search
void dijkstra(int arr[MAX_N][MAX_N], int start, int dist[MAX_N])
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < MAX_N; i++)
    {
        dist[i] = INF;
    }

    pq.push({0, start}); // {dist, destination}

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = -pq.top().second;
        pq.pop();

        for (int i = 0; i < MAX_N; i++)
        {
            int nxt_dist = cur_dist + arr[cur_node][i];

            if (nxt_dist < dist[i])
            {
                dist[i] = nxt_dist;
                pq.push({-nxt_dist, i});
            }
        }
    }
}

void dijkstra3(int arr[MAX_N][MAX_N], int start, int dist[MAX_N])
{
    int visited[MAX_N] = {
        0,
    };

    for (int i = 0; i < MAX_N; i++)
    {
        dist[i] = arr[start][i];
    }

    visited[start] = 1;

    for (int i = 0; i < MAX_N; i++)
    {
        int n_new = getMindIdx(dist, visited);
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

void dijkstra4(int arr[MAX_N][MAX_N], int start, int dist[MAX_N])
{
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < MAX_N; i++)
    {
        dist[i] = INF;
    }

    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = -pq.top().second;
        pq.pop();
    }

    for (int i = 0; i < MAX_N; i++)
    {
        int nxt_dist = cur_dist + arr[cur_node][i];

        if (nxt_dist < dist[i])
        {
            dist[i] = nxt_dist;
            pq.push(-nxt_dist, i);
        }
    }
}