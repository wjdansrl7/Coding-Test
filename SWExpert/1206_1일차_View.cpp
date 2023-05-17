#include <iostream>
#include <cstring>

using namespace std;

int dy[2] = {-1, 1};

int arr[2003][2003] = {
    0,
};
int main(int argc, char const *argv[])
{
    freopen("input (16).txt", "r", stdin);

    for (int tc = 0; tc < 10; tc++)
    {
        int N;
        cin >> N;

        int result = 0;
        memset(arr, 0, sizeof(arr));

        for (int i = 1; i <= N; i++)
        {
            int a;
            cin >> a;
            if (a == 0)
            {
                continue;
            }
            for (int j = 1; j <= a; j++)
            {
                arr[j][i] = 1;
            }
        }
        int nCount;

        for (int i = 1; i <= 255; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                nCount = 0;
                if (arr[i][j] == 1)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        int ny = j + dy[k];
                        if (arr[i][ny] == 0)
                        {
                            if (ny > 0 && ny <= N)
                            {
                                ny += dy[k];
                                if (arr[i][ny] == 0)
                                {
                                    if (ny > 0 && ny <= N)
                                        nCount++;
                                }
                            }
                            // else
                            // break;
                        }
                        // else
                        // break;
                    }
                    if (nCount == 2)
                        result++;
                }
            }
        }
        cout << "#" << tc + 1 << " " << result << '\n';
    }

    return 0;
}
