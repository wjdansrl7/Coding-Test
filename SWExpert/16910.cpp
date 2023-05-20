#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// x^2 + y^2 <= N^2

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        int cnt = 0;

        for (int y = -N; y <= N; y++)
        {
            if (pow(N, 2) - pow(y, 2) >= 0)
            {
                for (int x = -sqrt(pow(N, 2) - pow(y, 2)); x <= sqrt(pow(N, 2) - pow(y, 2)); x++)
                {
                    cnt++;
                }
            }
        }

        cout << "#" << tc + 1 << " " << cnt << '\n';
    }

    return 0;
}
