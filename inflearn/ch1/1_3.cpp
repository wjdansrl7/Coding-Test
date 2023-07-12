#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("in5.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> student;

    int height;
    for (int i = 0; i < n; i++)
    {
        cin >> height;
        student.push_back({height, i + 1});
    }

    stack<pair<int, int>> stk;

    for (int i = 0; i < n; i++)
    {
        while (!stk.empty())
        {
            if (stk.top().first > student[i].first)
            {
                cout << stk.top().second << " ";
                stk.push({student[i].first, student[i].second});
                break;
            }
            else
            {
                stk.pop();
            }
        }

        if (stk.empty())
        {
            cout << 0 << " ";
            stk.push({student[i].first, student[i].second});
        }
    }

    return 0;
}
