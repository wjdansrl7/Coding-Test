#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int r, c;
char pan[1501][1501];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    string str;
    vector<pair<int, int>> goose;
    queue<pair<int, int>> water;

    for (int i = 0; i < r; i++)
    {
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            pan[i][j] = str[j];

            if (pan[i][j] == 'L')
            {
                // 처음 백조의 위치
                goose.push_back({i, j});
            }
            else if (pan[i][j] == '.')
            {
                // 처음 물의 위치
                water.push({i, j});
            }
        }
    }

    return 0;
}
