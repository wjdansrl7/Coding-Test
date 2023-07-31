#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[3001][3001] = {
    0,
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("in10.txt", "r", stdin);

    int n1, n2, n3;
    string str1, str2;

    cin >> n1 >> n2 >> n3;

    cin >> str1 >> str2;

    int s1Size = str1.size();
    int s2Size = str2.size();

    str1 = ' ' + str1;
    str2 = ' ' + str2;

    vector<long long> s;

    for (int i = 1; i <= s1Size; i++)
        dy[i][0] = n2 * i;
    for (int i = 1; i <= s2Size; i++)
        dy[0][i] = n2 * i;

    for (int i = 1; i <= s1Size; i++)
    {
        for (int j = 1; j <= s2Size; j++)
        {
            if (str1[i] == str2[j])
            {
                dy[i][j] = dy[i - 1][j - 1] + n1;
            }
            else
            {
                s.push_back(dy[i - 1][j] + n2);
                s.push_back(dy[i][j - 1] + n2);
                s.push_back((dy[i - 1][j - 1] + (n2 * 2)));
                s.push_back(dy[i - 1][j - 1] + n3);
                sort(s.begin(), s.end(), greater<>());
                dy[i][j] = s[0];
                s.clear();
            }
        }
    }

    cout << dy[s1Size][s2Size] << '\n';

    return 0;
}
