#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }
#define MAX_NODE 10001
using namespace std;

int n; // 총 노드의 개수
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int max_level;

vector<int> graph[MAX_NODE];

void getTree(int here, int parent)
{
    // here은 부모노드보다 depth가 하나 더 많다.
    depth[here] = depth[parent] + 1;

    // here의 부모 노드는 parent
    ac[here][0] = parent;

    max_level = (int)floor(log2(n));

    for (int i = 1; i <= max_level; i++)
    {
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    // dfs 알고리즘
    int len = graph[here].size();

    for (int i = 0; i < len; i++)
    {
        // here과 연결된 그래프에 대해서 ac 배열을 생성해준다.
        int there = graph[here][i];
        // there == parent일 경우 무한 재귀호출에 빠지게 되므로
        if (there != parent)
        {
            getTree(there, here);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        memset(depth, 0, sizeof(depth));
        memset(ac, 0, sizeof(ac));

        cin >> n;

        int a, b;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            // graph[b].push_back(a);
        }

        // depth[0] = -1;

        // getTree(1, 0);
        cout << "238931820 " << a << " " << b << '\n';
        getTree(b, a);

        int x, y;
        // 우리가 원하는 최소 공통 조상 노드 번호
        cin >> x >> y;

        if (depth[x] != depth[y])
        {
            if (depth[x] > depth[y])
            {
                swap(x, y);
            }

            for (int i = max_level; i >= 0; i--)
            {
                if (depth[x] <= depth[ac[y][i]])
                {
                    y = ac[y][i];
                }
            }
        }

        int lca = x;

        // 현재 높이만 같은 상태(같은 depth)
        if (x != y)
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[x][i] != ac[y][i])
                {
                    x = ac[x][i];
                    y = ac[y][i];
                }

                lca = ac[x][i];
            }
        }

        cout << lca << '\n';

        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
        }
    }

    return 0;
}
