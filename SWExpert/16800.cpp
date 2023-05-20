#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        long long N;
        cin >> N;

        long long minCnt = pow(10, 12) + 1;

        for (int i = 1; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                long long j = N / i;

                if (minCnt > i + j - 2)
                {
                    minCnt = i + j - 2;
                }
            }
        }

        cout << "#" << tc + 1 << " " << minCnt << '\n';
    }
    return 0;
}

// for (int tc = 0; tc < T; tc++)
// {
//     long long N;
//     long long minCnt = pow(10, 12) + 1;

//     cin >> N;

//     for (long long i = 1; i <= N; i++)
//     {
//         for (long long j = 1; j <= N; j++)
//         {
//             if (i * j == N)
//             {
//                 if (minCnt > i + j)
//                 {
//                     minCnt = i + j - 2;
//                 }
//             }
//         }
//     }

//     cout << "#" << tc + 1 << " " << minCnt << '\n';
// }
