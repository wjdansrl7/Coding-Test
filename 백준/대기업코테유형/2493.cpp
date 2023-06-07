/*
문제를 풀지 못해서 참고함.
stack을 이용하여 풀이
나는 queue를 이용해서 다음 건물이 더 높으면 해당 인덱스를 반환하고 작다면 반복문을 통해서 높은 건물을 찾으면 이전까지 모아놓은 건물들에게 해당 인덱스를 반환하도록
문제를 풀려고 하였으나 코드를 짜는 과정에서 복잡해서 풀지 못하였다.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    stack<pair<int, int>> stk;

    cin >> n;

    long long height;
    int result[500001];
    for (int i = 0; i < n; i++)
    {
        cin >> height;

        while (!stk.empty())
        {
            if (stk.top().second < height)
            {
                stk.pop();
            }
            else
            {
                cout << stk.top().first << " ";
                stk.push({i + 1, height});
                break;
            }
        }

        if (stk.empty())
        {
            cout << 0 << " ";
            stk.push({i + 1, height});
        }
    }

    return 0;
}
