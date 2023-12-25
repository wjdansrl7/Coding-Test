#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int r, c;
int pan[41][41] = {
    0,
};
int sticker[11][11] = {
    0,
};
void findSpace(int L);
void patchSpace(int st_x, int st_y);
void rotation(int L);
void input()
{
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;

        memset(sticker, 0, sizeof(sticker) / sizeof(int));

        for (int j = 0; j < r; j++)
            for (int t = 0; t < c; t++)
                cin >> sticker[j][t];
        findSpace(0);
    }
}

void findSpace(int L)
{
    if (L == 4)
        return;

    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            bool endFlag = false;
            for (int t = 0; t < r; t++)
            {
                for (int s = 0; s < c; s++)
                {
                    // 스티커 붙일 자리가 채워진 경우
                    if (sticker[t][s] == 1)
                    {
                        if (sticker[t][s] == pan[i + t][j + s])
                        {
                            endFlag = true;
                            break;
                        }
                    }
                }
                if (endFlag)
                    break;
            }
            if (!endFlag)
            {
                // 스티커를 붙일 수 있다면
                patchSpace(i, j);
                return;
            }
        }
    }

    rotation(L);
}

void patchSpace(int st_x, int st_y)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (pan[i + st_x][j + st_y] != 1)
                pan[i + st_x][j + st_y] = sticker[i][j];
}

void rotation(int L)
{
    int tmp[11][11] = {
        0,
    };

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];

    memset(sticker, 0, sizeof(sticker) / sizeof(int));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sticker[j][r - i - 1] = tmp[i][j];
    swap(r, c);
    findSpace(L + 1);
}

int solution()
{
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (pan[i][j] == 1)
                res++;
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    cout << solution();

    return 0;
}
