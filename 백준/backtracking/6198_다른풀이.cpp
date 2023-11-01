#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    stack<int> s;
    long long answer = 0;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int height;
        cin >> height;

        // 1. 첫번째 건물은 바로 스택에 넣어줌
        if (s.empty())
        {
            s.push(height);
            continue;
        }

        // 2. 스택에 있는 건물들 중에, 현재 건물 보다 작은 건물들은 다 pop
        while (!s.empty() && s.top() <= height)
        {
            s.pop();
        }

        // 3. 해당 입력을 스택에 넣어줍니다.
        answer += s.size();

        s.push(height);
    }

    cout << answer;

    return 0;
}
