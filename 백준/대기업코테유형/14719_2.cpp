#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    int water[501];

    cin >> h >> w;

    for (int i = 0; i < w; i++)
    {
        cin >> water[i];
    }

    int answer = 0;
    for (int i = 0; i < w - 1; i++)
    {
        int left = 0, right = 0;
        for (int j = 0; j < i; j++)
        {
            if (left < water[j])
            {
                left = water[j];
            }
        }

        for (int j = i + 1; j < w; j++)
        {
            if (right < water[j])
            {
                right = water[j];
            }
        }

        answer += max(0, min(left, right) - water[i]);
    }
    cout << answer;

    return 0;
}
