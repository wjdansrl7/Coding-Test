#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str, target, tmp;
    stack<char> stk;

    cin >> str >> target;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != target[0])
        {
            tmp += str[i];
        }
        else
        {
            stk.push(str[i]);
            while (!stk.empty())
            {
                int k = 1;
                for (int j = i + 1; j < i + target.size(); j++)
                {
                    if (str[j] == target[k++])
                    {
                        stk.push(str[j]);
                    }
                }

                // for (int j = i+1; j < i+target.size(); j++)
                // {
                //     if (/* condition */)
                //     {
                //         /* code */
                //     }

                // for (int k = 1; k < target.size(); k++)
                // {
                //     stk.push(str[j]);
                // }

                // }
            }

            stk.push(str[i]);
        }
    }

    return 0;
}
