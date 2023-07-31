#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string a, b;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dy(n, vector<int>(m, 0));
    for (int i = 1; i < n; i++)
        dy[i][0] = n2 * i;
    for (int i = 1; i < n; i++)
        dy[0][i] = n2 * i;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i] == b[i])
            {
                dy[i][j] = dy[i - 1][j - 1] + n1;
            }
            else
            {
                int max;
                if (dy[i - 1][j] + n2 > dy[i][j - 1] + n2)
                {
                    max = dy[i - 1][j] + n2;
                }
                else
                    max = dy[i][j - 1] + n2;
                if (dy[i - 1][j - 1] + n3 > max)
                {
                    max = dy[i - 1][j - 1] + n3;
                }
                if (dy[i - 1][j - 1] + (n2 * 2) > max)
                {
                    max = dy[i - 1][j - 1] + (n2 * 2);
                }
                dy[i][j] = max;
            }
        }
    }
    cout << dy[n - 1][m - 1];

    return 0;
}
