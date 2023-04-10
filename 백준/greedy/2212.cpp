#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int sen_x[10000];
    int sen_length[10000];

    cin >> n;

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> sen_x[i];
    }

    sort(sen_x, sen_x + n);

    for (int i = 0; i < n - 1; i++)
    {
        sen_length[i] = sen_x[i + 1] - sen_x[i];
    }

    sort(sen_length, sen_length + n - 1);

    int result = 0;

    for (int i = 0; i < n - k; i++)
    {
        result += sen_length[i];
    }

    cout << result << "\n";

    return 0;
}
