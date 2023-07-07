#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        long long a, b;
        cin >> a >> b; // 6, 5
        int endflag = 0;

        for (long long i = 1; i <= a; i++)
        {
            if (i == 1)
            {
                if (a + i == b)
                {
                    endflag = 1;
                    break;
                }
            }

            if (a % i == 0)
            {
                long long x = a / i;
                if (i + x == b || i + x + 1 == b)
                {
                    endflag = 1;
                    break;
                }
            }
        }

        if (endflag)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }

    return 0;
}
