#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int res[7];
bool visited[14];

void dfs(vector<int> &n, int L, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << res[i] << " ";
        cout << '\n';
        return;
    }
    else
    {
        for (int i = L; i < n.size(); i++)
        {
            if (visited[i])
                continue;

            visited[i] = true;
            res[cnt] = n[i];
            dfs(n, i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, x;
    while (1)
    {
        vector<int> n;
        cin >> k;

        if (k == 0)
            break;
        else
        {
            for (int i = 0; i < k; i++)
            {
                cin >> x;
                n.push_back(x);
            }
        }

        sort(n.begin(), n.end());

        dfs(n, 0, 0);
        cout << '\n';
    }
    return 0;
}
