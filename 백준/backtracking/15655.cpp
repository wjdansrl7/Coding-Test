#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int res[10];
bool visited[10];

void dfs(int L, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << res[i] << " ";
        }
        cout << '\n';

        return;
    }
    else
    {
        for (int i = L; i < v.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }

            res[cnt] = v[i];
            visited[i] = true;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    dfs(0, 0);

    return 0;
}
