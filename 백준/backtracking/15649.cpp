#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v(8);
vector<int> res(8);

bool visited[8] = {
    false,
};

void print()
{
    for (int i = 0; i < m; i++)
    {
        cout << res[i] << " ";
    }
    cout << '\n';
}

void permutation(int depth)
{
    if (depth == m)
    {
        print();
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            res[depth] = i;
            permutation(depth + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    permutation(0);

    return 0;
}
