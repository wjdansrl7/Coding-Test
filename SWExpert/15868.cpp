#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n, m;

        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>{m, 0});
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if ((arr[i][0] ^ arr[i][j]) % 2 == 0)
                    continue;
                else
                {
                    flag = false;
                    break;
                }

                if (flag)
                {
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "#" << tc + 1 << "no" << '\n';
        }
        else
            cout << "#" << tc + 1 << "yes" << '\n';
    }

    return 0;
}
