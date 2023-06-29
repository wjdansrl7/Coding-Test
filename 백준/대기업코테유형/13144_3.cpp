#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    int visited[100001] = {
        0,
    };
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int start = 0, end = 0;
    while (start <= end)
    {
        for (; end < n; end++)
        {
            if (visited[v[end]] != 0)
            {
                break;
            }
            else
            {
                visited[v[end]] = 1;
            }
        }

        sum += (end - start);
        visited[v[start]] = 0;
        start++;
    }

    cout << sum << '\n';

    return 0;
}
