#include <iostream>
#include <vector>
#include <queue>
#define MAX 100
#define INF 999999
using namespace std;

vector<int> dijkstra(int start, int V, vector<pair<int, int>> adj[])
{
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i].first;
            int nCost = cost + adj[cur][i].second;
            if (nCost < dist[next])
            {
                dist[next] = nCost;
                pq.push(nCost, next);
            }
        }
    }

    return dist;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    vector<pair<int, int>> adj[MAX];
    cout << "정점 개수 입력";
    cin >> V;
    cout << "간선 갯수 입력";
    cin >> E;

    for (int i = 0; i < E; i++)
    {
        int from, to, cost;

        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    vector<int> dist = dijkstra(0, V, adj);
    for (int i = 0; i < V; i++)
    {
        cout << i << dist[i] << '\n';
    }

    return 0;
}
