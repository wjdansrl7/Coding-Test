#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

int n;
int arr[101];
stack<int> stk;
bool visited[101];
vector<int> tmp;
set<int> ans;

void dfs(int start)
{
    visited[start] = true;
    stk.push(start);

    while (!stk.empty())
    {
        int curr = stk.top();
        tmp.push_back(curr);
        stk.pop();

        if (!visited[arr[curr]])
        {
            stk.push(arr[curr]);
            visited[arr[curr]] = true;
        }
        else
        {
            if (arr[curr] == start)
            {
                for (int i = 0; i < tmp.size(); i++)
                {
                    ans.insert(tmp[i]);
                }
            }

            tmp.clear();
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i);
    }

    cout << ans.size() << '\n';

    for (auto var : ans)
    {
        cout << var << '\n';
    }

    return 0;
}
