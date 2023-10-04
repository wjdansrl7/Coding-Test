#include <iostream>
using namespace std;

int arr[501] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    int max_pos = 0, max_h = 0;
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i];
        if (arr[i] > max_h)
        {
            max_h = arr[i];
            max_pos = i;
        }
    }

    int lh = 0, rh = 0;
    int res = 0;
    // 왼쪽
    for (int i = 0; i < max_pos; i++)
    {
        lh = max(lh, arr[i]);
        res += lh - arr[i];
    }

    // 오른쪽
    for (int i = w - 1; i > max_pos; i--)
    {
        rh = max(rh, arr[i]);
        res += rh - arr[i];
    }

    cout << res;

    return 0;
}
