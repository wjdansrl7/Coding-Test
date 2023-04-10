#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long x, y;
    int w, s;
    long result;

    cin >> x >> y >> w >> s;

    if (x > y)
    {
        if (s < 2 * w)
        {
            if (s < w)
            {
                if ((x - y) & 1)
                {
                    result = (x - 1) * s + w;
                }
                else
                {
                    result = x * s;
                }
            }
            else
            {
                result = y * s + (x - y) * w;
            }
        }
        else
        {
            if (s < w)
            {
                if ((x - y) & 1)
                {
                    result = 2 * y * w + (x - y - 1) * s + w;
                }
                else
                {
                    result = 2 * y * w + (x - y) * s;
                }
            }
            else
            {
                result = (x + y) * w;
            }
        }
    }
    else
    {
        if (s < 2 * w)
        {
            if (s < w)
            {
                if ((y - x) & 1)
                {
                    result = (y - 1) * s + w;
                }
                else
                {
                    result = y * s;
                }
            }
            else
            {
                result = x * s + (y - x) * w;
            }
        }
        else
        {
            if (s < w)
            {
                if ((y - x) & 1)
                {
                    result = 2 * x * w + (y - x - 1) * s + w;
                }
                else
                {
                    result = 2 * x * w + (y - x) * s;
                }
            }
            else
            {
                result = (x + y) * w;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
