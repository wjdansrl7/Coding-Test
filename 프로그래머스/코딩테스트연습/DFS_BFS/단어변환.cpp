#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<string, int>> q;
int answer = 987654321;
int nCount = 0;
bool visited[51] = {
    false,
};

void bfs(string begin, string target, vector<string> words)
{
    q.push({begin, 0});

    while (!q.empty())
    {
        string curr_s = q.front().first;
        int curr_t = q.front().second;
        int u = 0;

        q.pop();

        if (curr_s == target)
        {
            if (answer > curr_t)
                answer = curr_t;
            return;
        }

        for (auto w : words)
        {
            for (int i = 0; i < w.size(); i++)
            {
                if (curr_s[i] == w[i])
                {
                    nCount++;
                }
            }
            if (nCount == w.size() - 1 && !visited[u])
            {
                visited[u] = true;
                q.push({w, curr_t + 1});
            }

            nCount = 0;
            u++;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{

    if (find(words.begin(), words.end(), target) == words.end())
        answer = 0;
    else
        bfs(begin, target, words);

    return answer;
}