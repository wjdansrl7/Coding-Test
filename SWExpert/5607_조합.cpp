#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N, R;

        cin >> N >> R;

        if (R > N / 2)
        {
            R = N - R;
        }

        long long a = 1, b = 1;

        for (int i = 1; i <= R; i++)
        {
            a *= (N - i + 1);

            b *= i;
        }

        long long result = 1;
        if (b != 0)
            result = (a / b) % 1234567891;

        cout << "#" << tc + 1 << " " << result << '\n';
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int T;
//     cin >> T;

//     for (int tc = 0; tc < T; tc++)
//     {
//         int N, R;
//         vector<int> arr;

//         cin >> N >> R;

//         for (int i = 0; i < N - R; i++)
//         {
//             arr.push_back(0);
//         }

//         for (int i = 0; i < R; i++)
//         {
//             arr.push_back(1);
//         }

//         int cnt = 0;

//         do
//         {
//             cnt++;
//         } while (next_permutation(arr.begin(), arr.end()));

//         cnt %= 1234567891;

//         cout << "#" << tc + 1 << " " << cnt << '\n';
//     }

//     return 0;
// }
