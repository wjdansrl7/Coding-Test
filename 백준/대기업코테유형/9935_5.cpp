#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    string str, target, tmp;
    deque<char> q;

    cin >> str >> target;

    for (int i = 0; i < str.size(); i++)
    {
        q.push_back(str[i]);
    }

    while (!q.empty())
    {
        char curr_str = q.front();

        if (curr_str != target[0])
        {
            tmp += curr_str;
            q.pop_front();
        }
        else
        {
            int endflag = 1;
            for (int i = 1; i < target.size(); i++)
            {
                if (q[i] != target[i])
                {
                    for (int j = 0; j <= i; j++)
                    {
                        tmp += str[j];
                        q.pop_front();
                    }
                    endflag = 0;
                    break;
                }
            }

            if (endflag)
            {
                for (int j = 0; j < target.size(); j++)
                {
                    q.pop_front();
                }
            }
        }
    }

    cout << tmp << '\n';

    return 0;
}
