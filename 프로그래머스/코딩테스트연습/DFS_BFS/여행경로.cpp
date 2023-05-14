/*
TC에서 1번 테스트 케이스가 계속 막혔다. 내가 테스트 케이스를 통과하지 못한 이유는 문제를 잘못 이해한 것 같다.
문제 제한사항에서
"주어진 항공권은 모두 사용해야 합니다."
"모든 도시를 방문할 수 없는 경우는 주어지지 않습니다."
이 두 제한사항을 보고 경로가 끊기는 경우를 고려하지 않아서 테스트 케이스를 통과하지 못하였다.

따라서 다른 참고 코드를 읽고, 나의 문제점을 깨달았다. 아쉬웠다.
더 잘하고 싶다.
*/
// 내가 작성한 코드
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

bool visited[10001] = {
    false,
};
stack<pair<string, string>> stk;
vector<string> answer;

void dfs(int index, vector<vector<string>> roads)
{
    visited[index] = true;
    stk.push({roads[index][0], roads[index][1]});
    answer.push_back(roads[index][0]);

    while (!stk.empty())
    {
        string curr_a = stk.top().first;
        string curr_b = stk.top().second;
        stk.pop();
        answer.push_back(curr_b);

        for (int i = 0; i < roads.size(); i++)
        {
            if (curr_b == roads[i][0] && !visited[i])
            {
                stk.push({roads[i][0], roads[i][1]});
                visited[i] = true;
                break;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < tickets.size(); i++)
    {
        int endflag = 0;

        if (tickets[i][0] == "ICN")
        {
            dfs(i, tickets);

            for (int i = 0; i < tickets.size(); i++)
            {
                if (!visited[i])
                {
                    endflag = 1;
                    memset(visited, 0, sizeof(visited));
                    answer.clear();
                    break;
                }
            }
            if (endflag == 0)
                break;
        }
    }

    return answer;
}

// 참고 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[1000001] = {
    false,
};
bool flag = false;
int cnt = 0;

void dfs(string curr, vector<vector<string>> tickets)
{
    if (cnt == (int)tickets.size())
        flag = true;
    answer.push_back(curr);

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == curr)
        {
            visited[i] = true;
            cnt++;
            dfs(tickets[i][1], tickets);

            if (!flag)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets);

    return answer;
}