#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int node[1001];
int answer;

deque<pair<int, pair<int, int>>> q;
extern bool isCycle(int a, int b);
extern void mergeParent(int a, int b);
extern int getParent(int a);
extern void prim();

bool isCycle(int a, int b)
{
    if (getParent(a) == getParent(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 그래프가 연결되면 부모가 같아진다.
void mergeParent(int a, int b)
{

    if (a < b)
    {
        a = getParent(a);
        b = getParent(b);
        node[b] = a;
    }
    else
    {
        a = getParent(a);
        b = getParent(b);
        node[a] = b;
    }
}

// 부모 노드를 반환
int getParent(int a)
{
    if (node[a] == a)
    {
        return a;
    }
    else
    {
        return getParent(node[a]);
    }
}

void prim()
{
    while (!q.empty())
    {
        int a = q.front().second.first;
        int b = q.front().second.second;
        int cost = q.front().first;

        q.pop_front();

        // 두 노드가 연결되어 있지 않음
        if (!isCycle(a, b))
        {
            answer += cost;
            mergeParent(a, b);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    answer = 0;

    for (int i = 1; i < 1001; i++)
    {
        node[i] = i;
    }

    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        q.push_back({z, {x, y}});
    }

    // 비용에 따라서 정렬
    sort(q.begin(), q.end());

    prim();

    cout << answer << '\n';

    return 0;
}
