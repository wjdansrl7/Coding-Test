#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("sample_input (22).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {

        char arr[8][8];
        vector<pair<int, int>> look;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'O')
                {
                    look.push_back({i, j});
                }
            }
        }

        bool flag = true;
        for (int i = 0; i < look.size(); i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (arr[look[i].first][j] == 'O' && j != look[i].second)
                {
                    flag = false;
                }

                if (arr[j][look[i].second] == 'O' && j != look[i].first)
                {
                    flag = false;
                }
            }
        }

        if (look.size() != 8)
        {
            flag = false;
        }

        if (flag)
            cout << "#" << tc + 1 << " yes" << '\n';
        else
            cout << "#" << tc + 1 << " no" << '\n';
    }

    return 0;
}