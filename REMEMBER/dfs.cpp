#include <iostream>
#include <stdio.h>
#define MAX_N 10

using namespace std;

int E, N, graph[MAX_N][MAX_N];
bool visited[MAX_N];

int Stack[MAX_N];
int top;

// 재귀 예제
void dfs(int node)
{
    visited[node] = true;
    cout << node << ' ';

    for (int next = 0; next < N; next++)
    {
        if (!visited[next] && graph[node][next])
        {
            dfs(next);
        }
    }
}

// 스택 예제
void dfs1(int node)
{
    bool visited[MAX_N] = {false};
    top = -1;
    stack[++top] = node;

    while (top != -1)
    {
        int curr = stack[top--];

        if (!visited[curr])
        {
            visited[curr] = true;
            cout << curr << ' ';

            for (int next = 0; next < N; next++)
            {
                if (!visited[next] && graph[curr][next])
                {
                    stack[++top] = next;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> E;

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;

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

    dfs(0);

    return 0;
}
