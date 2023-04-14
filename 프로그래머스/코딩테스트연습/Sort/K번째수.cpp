#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> result;

    for (int u = 0; u < commands.size(); u++)
    {
        int i = commands[u][0];
        int j = commands[u][1];
        int k = commands[u][2];
        result.clear();

        for (int t = i - 1; t < j; t++)
            result.push_back(array[t]);

        sort(result.begin(), result.end());

        answer.push_back(result[k - 1]);
    }

    return answer;
}