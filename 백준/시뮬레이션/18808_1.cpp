#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int pan[41][41] = {
    0,
};
int tmp[11][11] = {
    0,
};
int sticker[11][11] = {
    0,
};

void findSpace(int x, int y, int arr[11][11], int l);
void input()
{
    cin >> n >> m >> k;

    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;

        memset(sticker, 0, sizeof(sticker) / sizeof(int));
        for (int l = 0; l < a; l++)
            for (int j = 0; j < b; j++)
                cin >> sticker[l][j];
        findSpace(a, b, sticker, 0);
    }
}

void rotation(int x, int y, int arr[11][11])
{
    memset(tmp, 0, sizeof(tmp) / sizeof(int));

    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            tmp[i][j] = arr[j][x - i - 1];

    memset(arr, 0, sizeof(arr) / sizeof(int));
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            arr[i][j] = tmp[i][j];
}

void pretty(int st_x, int st_y, int x, int y, int arr[11][11])
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (arr[i][j] == 1)
                pan[st_x + i][st_y + j] = 1;
}

void findSpace(int x, int y, int arr[11][11], int L)
{
    if (L >= 1)
    {
        if (L < 4)
            rotation(x, y, arr);
        else
            return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << pan[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 0; i < n - x; i++)
    {
        for (int j = 0; j < m - y; j++)
        {
            bool endflag = true;
            for (int l = 0; l < x; l++)
            {
                for (int m = 0; m < y; m++)
                {
                    if (arr[l][m] == 1 && pan[i + l][j + m] == 1)
                    {
                        if (pan[i + l][j + m] == 1)
                        {
                            endflag = false;
                            cout << i << " " << j << " " << l << m << '\n';
                        }
                    }
                }
            }

            if (endflag)
            {
                pretty(i, j, x, y, arr);
                return;
            }
        }
    }

    findSpace(x, y, arr, L + 1);
}

void solution()
{
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (pan[i][j] == 1)
                res++;
    cout << res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solution();

    return 0;
}
