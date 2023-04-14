#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

bool visited[200];
stack<int> stk;

int result;

void dfs(int n, vector<vector<int>> computers, int start)
{
    visited[start] = true;
    stk.push(start);

    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();

        for (int next = 0; next < n; next++)
        {
            if (computers[curr][next] && !visited[next])
            {
                stk.push(next);
                visited[next] = true;
            }
        }
    }

    result++;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    result = 0;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(n, computers, i);
    }

    answer = result;

    return answer;
}