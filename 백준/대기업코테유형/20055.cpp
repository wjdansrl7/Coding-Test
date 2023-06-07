/*
문제를 이해하지 못해서 풀지 못하고 헤맸다.
deque라는 STL을 제대로 이해했다. 일반적인 queue는 뒤쪽에서 계속 push를 해줬는데
deque는 양쪽에서 삽입과 삭제가 가능해서 편리하였다.

또한 컨베이어벨트가 회전하는 경우 나가는 위치에 도달하면 바로 내보내야하는데,
컨베이어 벨트의 회전에 대한 조건을 놓쳤다.
*/

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int answer;
deque<int> belt;
deque<bool> check;

void roll()
{
    belt.push_front(belt.back());
    belt.pop_back();

    check.push_front(check.back());
    check.pop_back();

    if (check[n - 1])
    {
        check[n - 1] = false;
    }
}

void execute()
{
    for (int i = n - 2; i > 0; i--)
    {
        if (check[i])
        {
            if (!check[i + 1] && belt[i + 1] != 0)
            {
                check[i] = false;
                check[i + 1] = true;
                belt[i + 1]--;

                if (i + 1 == n - 1)
                {
                    check[i + 1] = false;
                }
            }
        }
    }

    if (belt[0] != 0 && !check[0])
    {
        belt[0]--;
        check[0] = true;
    }
}
bool check_K()
{
    int ret = 0;
    for (int i = 0; i < belt.size(); i++)
    {
        if (belt[i] == 0)
        {
            ret++;
        }
    }

    if (ret >= k)
    {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    answer = 0;

    int num;
    for (int i = 0; i < n * 2; i++)
    {
        cin >> num;
        belt.push_back(num);

        check.push_back(false);
    }

    while (1)
    {
        answer++;
        roll();
        execute();
        if (check_K())
            break;
    }

    cout << answer << '\n';

    return 0;
}
