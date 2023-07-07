#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str;
    stack<int> stk;

    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        if (str == "push")
        {
            cin >> num;
            stk.push(num);
        }
        else if (str == "pop")
        {
            if (!stk.empty())
            {
                cout << stk.top() << '\n';
                stk.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (str == "size")
        {
            cout << stk.size() << '\n';
        }
        else if (str == "empty")
        {
            if (stk.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            if (stk.empty())
            {
                cout << -1 << '\n';
            }
            else
                cout << stk.top() << '\n';
        }
    }

    return 0;
}
