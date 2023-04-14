#include <iostream>
#include <stdio.h>
#define MAX_N 10

using namespace std;

int E, N;
int graph[MAX_N][MAX_N];
int queue[20], front, rear;

void bfs(int node);

int main(int argc, char const *argv[])
{
    cin >> N >> E;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    bfs(0);

    return 0;
}

void bfs(int node)
{
    bool visited[MAX_N] = {false};
    front = rear = -1;
    visited[node] = true;
    queue[++rear] = node;

    while (front != rear)
    {
        int curr = queue[++front];

        cout << curr << ' ';

        for (int next = 0; next < N; next++)
        {
            if (!visited[next] && graph[curr][next])
            {
                visited[next] = true;
                queue[++rear] = next;
            }
        }
    }
}
