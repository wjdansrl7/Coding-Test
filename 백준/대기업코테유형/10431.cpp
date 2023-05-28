#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int arr[30] = {
        0,
    };
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < 20; i++)
        {
            cin >> arr[i];
        }

        int changedNum;
        int sum = 0;
        for (int i = 1; i < 20; i++)
        {
            changedNum = -1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] < arr[j])
                {
                    changedNum = j;
                }
            }
            int tmp = arr[i];

            if (changedNum != -1)
            {
                for (int j = i - 1; j >= changedNum; j--)
                {
                    arr[j + 1] = arr[j];
                    sum++;
                }
                arr[changedNum] = tmp;
            }
        }

        cout << tc + 1 << " " << sum << '\n';
    }

    return 0;
}
