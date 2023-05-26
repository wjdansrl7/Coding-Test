#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input (21).txt", "r", stdin);
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N, M;
        int arr[16][16];

        cin >> N >> M;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
        int sum = 0, maxSum = 0;
        for (int i = 0; i <= N - M; i++)
        {
            for (int j = 0; j <= N - M; j++)
            {
                sum = 0;
                for (int k = i; k < i + M; k++)
                {
                    for (int l = j; l < j + M; l++)
                    {
                        sum += arr[k][l];
                    }
                }
                if (sum > maxSum)
                {
                    maxSum = sum;
                }
            }
        }

        cout << "#" << tc + 1 << " " << maxSum << '\n';
    }

    return 0;
}
