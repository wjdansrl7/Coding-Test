#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;

        cin >> N;

        cout << "#" << tc + 1 << " " << N * N << '\n';
    }

    return 0;
}
