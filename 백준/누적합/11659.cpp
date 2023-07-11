#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> psum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        psum[i] = psum[i - 1] + v[i];
    }

    int start, end;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;

        cout << psum[end] - psum[start - 1] << '\n';
    }

    return 0;
}
