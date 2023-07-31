#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int x, y, et_x, et_y;

int arr[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int viisted[2][1001][1001];

void bfs()
{

}


int main(int argc, char const *argv[])
{
    cin >> w >> h;
    vector<pair<int, int>> strberry;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 2)
            {
                x = i;
                y = j;
            }
            if (arr[i][j] == 3)
            {
                et_x = i;
                et_y = j;
            }
            if (arr[i][j] == 4)
            {
                strberry.push_back({i, j});
            }
        }
    }

    return 0;
}
