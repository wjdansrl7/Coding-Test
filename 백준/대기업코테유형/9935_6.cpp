#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, target, tmp;
    deque<char> q;

    cin >> str >> target;

    int curr = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == target[0])
        {
            q.push_back(str[i]);
            curr = 1;
            continue;
        }

        if (str[i] == target[curr])
        {
            q.push_back(str[i]);
            curr++;
            if (curr == target.size())
            {
                for (int j = 0; j < target.size(); j++)
                {
                    q.pop_back();
                }
                if (q.size() >= 1)
                {
                    if (q[q.size() - 1] == target[0])
                    {
                        curr = 1;
                    }
                    else
                    {
                        curr = q.size();
                    }
                }
            }
            if (q.empty())
            {
                curr = 0;
            }
            continue;
        }
        else
        {
            while (!q.empty())
            {
                tmp += q.front();
                q.pop_front();
            }
            curr = 0;
            tmp += str[i];
        }
    }

    if (tmp == "")
    {
        cout << "FRULA" << '\n';
    }
    else
        cout << tmp << '\n';

    return 0;
}
