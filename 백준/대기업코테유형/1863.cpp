#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int x, y;

    stack<int> stk;
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i != n)
            cin >> x >> y;
        else
            y = 0;

        while (!stk.empty() && stk.top() >= y)
        {
            if (stk.top() != y)
                cnt++;

            stk.pop();
        }
        stk.push(y);
    }

    cout << cnt;

    return 0;
}
