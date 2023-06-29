#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, target;
    deque<int> index;
    cin >> str >> target;

    // 문자열을 한바퀴돌면서 시작위치가 일치하는 index를 저장
    // for (int i = str.size(); i >= 0; i--)
    // {
    //     if (str[i] == target[0])
    //     {
    //         index.push_back(i);
    //     }
    // }
    string tmp = str;
    for (int i = str.size(); i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 0; j < target.size(); j++)
        {
            if (i + j >= str.size())
            {
                break;
            }

            if (target[j] == str[i + j])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        if (cnt == target.size())
        {
            tmp.erase(str[i], target.size());
        }
    }

    // while (!index.empty())
    // {
    //     int cnt = 0;
    //     for (int i = 0; i < target.size(); i++)
    //     {
    //         if (target[i] == str[index[0] + i])
    //         {
    //             cnt++;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     if (cnt == target.size())
    //     {
    //         // 일치하는 문자열
    //         str.erase(index[0], target.size());
    //     }
    //     index.pop_front();
    // }

    str = tmp;
    if (str == "")
    {
        cout << "FRULA" << '\n';
    }
    else
    {
        cout << str << '\n';
    }

    return 0;
}
