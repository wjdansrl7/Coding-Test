#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int nCount = 0;

    for (int i = 0; i < operations.size(); i++)
    {
        string s;
        if (operations[i][0] == 'I')
        {
            for (int j = 2; j < operations[i].size(); j++)
            {
                s += operations[i][j];
            }

            int a = stoi(s);
            minHeap.push(a);
            maxHeap.push(a);
            nCount++;
        }
        else if (operations[i] == "D 1")
        {
            maxHeap.pop();
            nCount--;
        }
        else if (operations[i] == "D -1")
        {
            minHeap.pop();
            nCount--;
        }
    }

    if (nCount <= 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    return answer;
}