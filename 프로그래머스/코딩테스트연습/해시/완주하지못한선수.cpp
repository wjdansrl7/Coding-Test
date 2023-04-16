#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> result;

    for (int i = 0; i < completion.size(); i++)
    {
        if (result.find(completion[i]) != result.end())
        {
            result[completion[i]]++;
        }
        else
            result.insert({completion[i], 1});
    }

    for (int i = 0; i < participant.size(); i++)
    {
        if (--result[participant[i]] < 0)
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}