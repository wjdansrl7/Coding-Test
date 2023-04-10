#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    long x, y;
    int w, s;
    long result[3];

    memset(result, 0, sizeof(result));

    cin >> x >> y >> w >> s;

    if (x > y)
    {
        if (x & 1)
        {
            result[0] = y * s + (x - y) * w;
            result[1] = (x + y) * w;
            result[2] = w + (x - 1) * s;
        }
        else
        {
            result[0] = (x + y) * w;
            result[1] = x * s;
            result[2] = y * s + (x - y) * w;
        }
    }
    else
    {
        if (y & 1)
        {
            result[0] = x * s + (y - x) * w;
            result[1] = (x + y) * w;
            result[2] = w + (y - 1) * s;
        }
        else
        {
            result[0] = (x + y) * w;
            result[1] = y * s;
            result[2] = x * s + (y - x) * w;
        }
    }

    sort(result, result + 3);

    cout << result[0] << "\n";

    return 0;
}
