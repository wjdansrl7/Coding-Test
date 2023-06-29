#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> index;
    vector<int> result;

    cin >> n;

    result.resize(n, 0);

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        index.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (result[j] == 0)
            {
                cnt++;
            }
            if (cnt == index[i] + 1)
            {
                result[j] = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}
