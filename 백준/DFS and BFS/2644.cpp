#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 100
#define endl "\n"

using namespace std;

int parents[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int depth[MAXN];
int maxCount;

void DFS(int node, int dep)
{
    visited[node] = true;
    depth[node] = dep;
    for (int i = 0; i < adj[node].size(); i++)
    {
        int next_node = adj[node][i];
        if (visited[next_node])
        {
            continue;
        }
        parents[next_node] = node;
        DFS(next_node, dep + 1);
    }
}

int LCA(int node_a, int node_b)
{
    if (node_a == node_b)
    {
        return node_a;
    }
    if (depth[node_a] == depth[node_b])
    {
        maxCount += 2;
        return LCA(parents[node_a], parents[node_b]);
    }
    else if (depth[node_a] > depth[node_b])
    {
        maxCount += 1;
        return LCA(parents[node_a], node_b);
    }
    else
    {
        maxCount += 1;
        return LCA(node_a, parents[node_b]);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(depth, 0, sizeof(depth));
    memset(visited, 0, sizeof(visited));
    memset(parents, 0, sizeof(parents));

    for (int i = 0; i < MAXN; i++)
    {
        adj[i].clear();
    }

    maxCount = 0;

    int N;
    int node_a, node_b;
    int rel;

    cin >> N;

    cin >> node_a >> node_b;

    cin >> rel;
    for (int i = 0; i < rel; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // DFS(1, 0);

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS(i, 0);
        }
    }

    if (LCA(node_a, node_b) == 0)
        cout << -1 << endl;
    else
    {
        cout << maxCount << endl;
    }

    return 0;
}
