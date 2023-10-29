#include <iostream>
using namespace std;

int n, m;
int arr[9];

void dfs(int num, int k)
{
    if (k == m)
    {
        for (auto i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        for (auto i = num; i <= n; i++)
        {
            arr[k] = i;
            dfs(i + 1, k + 1);
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
