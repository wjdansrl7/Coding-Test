#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> sh;

    for (int i = 0; i < clothes.size(); i++)
    {
        sh[clothes[i][1]]++;
    }

    for (auto cl : sh)
        answer *= cl.second + 1;

    answer -= 1;

    return answer;
}