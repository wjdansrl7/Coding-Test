#include <string>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

int graph[101][101] = {
    0,
};
bool visited[101] = {
    false,
};
int nCount;

void dfs(int start, int n)
{
    stack<int> stk;

    visited[start] = true;
    stk.push(start);
    nCount++;

    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();

        for (int i = 1; i <= n; i++)
        {
            if (graph[curr][i] == 1 && !visited[i])
            {
                stk.push(i);
                visited[i] = true;
                nCount++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 987654321;

    for (int i = 0; i < wires.size(); i++)
    {
        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;
    }

    for (int i = 0; i < wires.size(); i++)
    {
        nCount = 0;
        graph[wires[i][0]][wires[i][1]] = 0;
        graph[wires[i][1]][wires[i][0]] = 0;

        if (!visited[wires[i][0]])
            dfs(wires[i][0], n);

        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;
        memset(visited, 0, sizeof(visited));
        if (answer > abs(n - 2 * nCount))
            answer = abs(n - 2 * nCount);
    }

    return answer;
}