/*
해당 문제를 접근하기 위해 다익스트라 알고리즘이나 크루스칼 알고리즘, 프림 알고리즘을 생각하였으나,
해당 알고리즘들을 어떻게 짜야할지, 알고리즘 동작과정들에 대해서 기억이 나지 않아
다시 공부하였다.

해당 문제는 위 알고리즘들을 공부한 후, 크루스칼 알고리즘을 통해서 문제를 해결하였다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[101];

int getParent(int node)
{
    if (check[node] == node)
        return node;
    else
        getParent(check[node]);
}

void unionParent(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);

    if (node1 < node2)
        check[node2] = node1;
    else
        check[node1] = node2;
}

bool isCycle(int node1, int node2)
{
    node1 = getParent(node1);
    node2 = getParent(node2);

    if (node1 == node2)
        return true;
    else
        return false;
}

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[2] < b[2])
        return true;
    else
        return false;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    sort(costs.begin(), costs.end(), comp);

    for (int i = 1; i <= n; i++)
        check[i] = i;

    for (int i = 0; i < costs.size(); i++)
    {
        if (!isCycle(costs[i][0], costs[i][1]))
        {
            answer += costs[i][2];
            unionParent(costs[i][0], costs[i][1]);
        }
    }

    return answer;
}
