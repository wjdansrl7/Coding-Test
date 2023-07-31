#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("in5.txt", "r", stdin);

    string str1, str2;
    cin >> str1 >> str2;

    int str1Size = str1.size();
    int str2Size = str2.size();

    str1 = ' ' + str1;
    str2 = ' ' + str2;

    int dy[1001][1001] = {
        0,
    };

    for (int i = 1; i <= str1Size; i++)
    {
        for (int j = 1; j <= str2Size; j++)
        {
            if (str1[i] == str2[j])
            {
                dy[i][j] = dy[i - 1][j - 1] + 1;
            }
            else
            {
                dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]);
            }
        }
    }
    cout << dy[str1Size][str2Size] << '\n';

    return 0;
}
