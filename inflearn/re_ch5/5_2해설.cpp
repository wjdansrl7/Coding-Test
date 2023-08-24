#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, res;
    cin >> str;
    stack<char> s;
    for (auto x : str)
    {
        if (x == ')')
        {
            string tmp;
            while (!s.empty() && s.top() != '(')
            {
                tmp += s.top();
                s.pop();
            }
            s.pop();
            reverse(tmp.begin(), tmp.end());
            string num;
            if (s.empty())
                num = "1";
            while (!s.empty())
            {
                num += s.top();
                s.pop();
            }
            reverse(num.begin(), num.end());
            int n = stoi(num);
            for (int i = 0; i < n; i++)
            {
                res += tmp;
            }
        }
        else
        {
            s.push(x);
        }
    }
    cout << res;
    return 0;
}
