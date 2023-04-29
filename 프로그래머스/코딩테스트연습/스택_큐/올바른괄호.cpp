#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            stk.push('(');
        else if (!stk.empty())
        {
            stk.pop();
        }
        else // "(" 값이 없는 경우
        {
            answer = false;
            return answer;
        }
    }

    if (!stk.empty())
    {
        answer = false;
        return answer;
    }

    return answer;
}