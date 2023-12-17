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

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        stk.push(x);
    }

    int sum = 0;
    int top = 0;
    int res = 0;
    while (!stk.empty())
    {
        top = stk.top();
        stk.pop();

        if (sum == 0)
        {
            res += w;
            sum += top;
            continue;
        }

        if (sum + top <= l)
        {
        }
        else
        {
            sum = top;
        }
    }

    return 0;
}
