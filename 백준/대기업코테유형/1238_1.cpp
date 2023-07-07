/*
정점들의 정보를 입력 받을 때 역방향 간선을 따로 입력 받는다
-> 역방향으로 입력을 받으면 각 정점들(A)에서 X로 가는 최단 거리를 X->A 최단 거리로 바꿀 수 있다.
다익스트라 한 번이면 각 정점들에서 X로 가는 최단 거리 배열을 구할 수 있다는 것이다.
*/

#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M, X;
const int INF = 1e9 + 7;
vector<pii> graph[2][1001];
vector<int> dist[2];
int redist[1001];

void input()
{
    int u, v, t;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> t;
        graph[0][u].push_back({t, v});
        graph[1][v].push_back({t, u});
    }

    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);
}

void Dijstra(int k)
{
    dist[k][X] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push({0, X});

    while (!que.empty())
    {
        int min_cost = que.top().first;
        int now = que.top().second;
        que.pop();

        if (min_cost > dist[k][now])
        {
            continue;
        }

        for (int i = 0; i < graph[k][now].size(); i++)
        {
            int next = graph[k][now][i].second;
            int next_cost = min_cost + graph[k][now][i].first;

            if (next_cost < dist[k][next])
            {
                dist[k][next] = next_cost;
                que.push({next_cost, next});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    Dijstra(1);
    Dijstra(0);

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res = max(res, dist[0][1] + dist[1][i]);
    }

    cout << res;
    return 0;
}
