#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int h, w, n, m;
    int cnt = 0;

    cin >> h >> w >> n >> m;

    for (int i = 0; i < h; i += n + 1)
    {
        for (int j = 0; j < w; j += m + 1)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}
