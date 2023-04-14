// TODO: 이 문제는 다시 한 번 풀어보자.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> result;

bool comp(const string &a, const string &b)
{
    if (a + b > b + a)
    {
        return true;
    }
    else
        return false;
}

string solution(vector<int> numbers)
{
    string answer = "";

    for (int i = 0; i < numbers.size(); i++)
    {
        result.push_back(to_string(numbers[i]));
    }

    sort(result.begin(), result.end(), comp);

    for (string str : result)
    {
        answer += str;
    }

    if (answer[0] == '0')
        return "0";

    return answer;
}