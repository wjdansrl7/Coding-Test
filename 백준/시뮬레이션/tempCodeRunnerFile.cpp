#include <iostream>
#include <stack>
using namespace std;

int n, w, l;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> w >> l;

    stack<int> stk;
    int res = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (stk.empty())
        {
            stk.push(x);
            res += w;
        }
        else
        {
            int curr = stk.top();
            stk.pop();

            if (curr + x <= l)
            {
                stk.push(curr + x);
                res++;
            }
            else
            {
                stk.push(x);
                res += w;
            }
        }
    }

    cout << res + 1;

    return 0;
}
