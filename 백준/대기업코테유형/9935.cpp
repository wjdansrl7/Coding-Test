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
    // priority_queue<int> index;
    deque<int> index;
    cin >> str >> target;

    // 문자열을 한바퀴돌면서 시작위치가 일치하는 index를 저장
    for (int i = str.size(); i >= 0; i--)
    {
        if (str[i] == target[0])
        {
            index.push_back(i);
        }
    }

    while (!index.empty())
    {
        int cnt = 0;
        for (int i = 0; i < target.size(); i++)
        {
            if (target[i] == str[index[0] + i])
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
            // 일치하는 문자열
            str.erase(index[0], target.size());
        }
        index.pop_front();
    }

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
