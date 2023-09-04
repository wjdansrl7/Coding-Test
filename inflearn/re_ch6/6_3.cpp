#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dy(n, vector<int>(m, 0));
    vector<string> board;
    vector<int> answer(min(n, m) + 2);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '0')
            {
                continue;
            }
            int a = 0, b = 0, c = 0;
            if (i - 1 >= 0)
                a = dy[i - 1][i];
            if (j - 1 >= 0)
                b = dy[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                c = dy[i - 1][j - 1];
            int m = min(a, min(b, c));
            dy[i][j] = m + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 1; k <= dy[i][j]; k++)
            {
                answer[k]++;
            }
        }
    }
    for (int i = 1;; i++)
    {
        if (answer[i] == 0)
        {
            break;
        }
        cout << i << " " << answer[i] << '\n';
    }

    return 0;
}
