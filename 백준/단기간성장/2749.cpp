#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int x;
    stack<int> stk;

    stk.push(0);
    stk.push(1);
    // q.push(0);
    // q.push(1);

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        // int curr_x = q.front();
        // q.pop();
        int curr_x = stk.top();
        stk.pop();
        // x = curr_x + q.front();
        x = curr_x + stk.top();
        // cout << x << '\n';

        // if (x >= 1000000)
        // x %= 1000000;
        stk.push(curr_x);
        stk.push(x);
    }
    cout << stk.top();

    return 0;
}
