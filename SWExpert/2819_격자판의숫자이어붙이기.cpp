#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

set<string> m;
char arr[4][4];

void bfs(int start_x, int start_y, string s)
{
    s += arr[start_x][start_y];

    if (s.size() == 7)
    {
        // m.insert(stoi(s));
        m.insert(s);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
            continue;
        else
        {
            bfs(nx, ny, s);
        }
    }
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

        for (int tc = 0; tc < T; tc++)
    {
        memset(arr, 0, sizeof(arr));
        m.clear();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                bfs(i, j, "");
            }
        }

        // for (auto a : m)
        // {
        //     cout << a << " ";
        // }

        cout << "#" << tc + 1 << " " << m.size() << '\n';
    }

    return 0;
}
