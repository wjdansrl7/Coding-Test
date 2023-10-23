/*
청소년 상어
*/

#include <iostream>
using namespace std;

int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int arr[10][10];
int fish[17];
int res = 0;
int st_x, st_y, dShark;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> x;
            if (j % 2 == 0)
            {
                arr[i + 1][j + 1] = x;
            }
            else
            {
                fish[i * 4 + j / 2 + 1] = x;
            }
        }
    }

    // 상어의 시작위치
    res += arr[1][1];
    st_x = 1;
    st_y = 1;
    dShark = fish[1];

    return 0;
}
