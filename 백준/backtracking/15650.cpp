#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visited[10];

void dfs(int L, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';

        return;
    }
    else
    {
        for (int i = L; i <= n; i++)
        {
            if (visited[i])
            {
                continue;
            }

            arr[cnt] = i;
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

    dfs(1, 0);

    return 0;
}
