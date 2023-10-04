#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int l, h;
    int max_pos = 0, max_h = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> h;
        arr[l] = h;
        if (max_h < h)
        {
            max_h = h;
            max_pos = l;
        }
    }

    int lh = 0, rh = 0;
    int res = 0;
    for (int i = 0; i < max_pos; i++)
    {
        lh = max(lh, arr[i]);
        res += lh;
    }

    for (int i = 1000; i >= max_pos; i--)
    {
        rh = max(rh, arr[i]);
        res += rh;
    }
    cout << res;

    return 0;
}
