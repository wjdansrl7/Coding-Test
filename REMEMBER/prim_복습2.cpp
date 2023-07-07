#include <iostream>
#include <vector>
#include <queue>
#define PII pair<int, int>
using namespace std;

const int N = 1005, INF = 2140000000;

vector<PII> ad[N];                                   // ad[i]: 노드가 출발지인 간선들, first = 비용, second = 목적지
priority_queue<PII, vector<PII>, greater<PII>> dist; // dist: 선택될 가능성이 있는 간선들
bool selected[N];                                    // selected[i] : i가 이전에 선택된 노드인가? visited 개념

void add_edge(int node)
{
    for (auto edge : ad[node])
    {
        dist.push(edge);
    }
}

long long prim(int pn)
{
    long long ret = 0;
    for (int i = 1; i <= pn; i++)
    {
        selected[pn] = false;
    }

    dist.push(PII(0, 1));
    for (int i = 1; i <= pn; i++)
    {
        int now = -1, min_dist = INF;
        while (!dist.empty())
        {
            now = dist.top().second;
            if (!selected[now])
            {
                min_dist = dist.top().first;
                break;
            }
            dist.pop();
        }

        if (min_dist == INF)
        {
            return (long long)INF;
        }
        ret += min_dist;
        selected[now] = true;
        add_edge(now);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        ad[v1].push_back(PII(c, v2));
        ad[v2].push_back(PII(c, v1));
    }

    cout << prim(n);

    return 0;
}
