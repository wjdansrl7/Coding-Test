/**
 * @file 3584_다른해설.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-28
 *
 * 두 노드 u, v를 입력받으면 u부터 루트 노드까지 올라가면서 방문 표시를 한다.
 * 그리고 v에서 위로 거슬러 올라갈 때 만약 그곳이 u가 방문했던 곳이라면 최소 공통 조상입니다.
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

int parent[10001];
bool visited[10001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        memset(parent, 0, sizeof(parent));
        memset(visited, 0, sizeof(visited));
        int n;
        cin >> n;
        int a, b;

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            parent[b] = a;
        }

        int u, v;
        cin >> u >> v;
        visited[u] = true;

        while (u != parent[u])
        {
            u = parent[u];
            visited[u] = true;
        }
        while (1)
        {
            if (visited[v])
            {
                cout << v << '\n';
                break;
            }
            v = parent[v];
        }
    }

    return 0;
}
