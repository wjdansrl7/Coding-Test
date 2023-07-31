#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    // freopen("in5.txt", "r", stdin);

    string str, res;
    deque<char> q;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        q.push_back(str[i]);
    }

    string tmp, tmp_num;
    int num;
    while (!q.empty())
    {
        char curr = q.front();
        q.pop_front();

        if (curr < 48)
        {
            if (curr == '(')
            {
                if (!tmp_num.empty())
                {
                    num = stoi(tmp_num);
                }
                else
                    num = 1;
            }

            if (curr == ')')
            {
                for (int i = 0; i < num; i++)
                {
                    res += tmp;
                }
                tmp.clear();
                tmp_num.clear();
            }
        }
        else if (curr >= 48 && curr < 97)
        {
            tmp_num += curr;
        }
        else
        {
            tmp += curr;
        }
    }
    cout << res << '\n';

    return 0;
}
