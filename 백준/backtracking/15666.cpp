#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
void solve(int L, int cnt, vector<int> v)
{
    if (L == n || cnt == m)
    {
        return;
    }
    else
    {
        for (int i = L; i < n; i++)
        {
            cout << v[i] << " ";
            solve(i + 1, cnt + 1, v);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    set<int> u;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        u.insert(x);
    }

    vector<int> v(u.begin(), u.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << v[i] << " ";
            solve(j, 1, v);
        }
    }

    return 0;
}
