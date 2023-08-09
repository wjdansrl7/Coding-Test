#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> s;
    vector<int> h(n + 1), res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = n; i >= 1; i--)
    {
        // stack에 학생 키를 넣는 것보다는 학생의 번호를 넣는게 훨씬 유연하게 코드가 짜진다.
        while (!s.empty() && h[i] > h[s.top()])
        {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
