#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n;
    while (T--)
    {
        // vector<int> fund;
        stack<int> stk;
        cin >> n;

        int x, MAX = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (MAX <= x)
            {
                MAX = x;
                stk.push(x);
            }
            else
            {
                while (!stk.empty())
                {
                    res += MAX - stk.top();
                    stk.pop();
                }
                MAX = x;
                stk.push(x);
            }
        }

        while (!stk.empty())
        {
            res += MAX - stk.top();
            stk.pop();
        }
        cout << res << '\n';
    }

    return 0;
}
