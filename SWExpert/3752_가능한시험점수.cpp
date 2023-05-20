#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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
        int N;
        cin >> N;
        set<int> m;
        vector<int> arr;

        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        for (int i = 0; i <= N; i++)
        {
            vector<int> temp(N - i, 0);
            int sum = 0;

            for (int j = 0; j < i; j++)
            {
                temp.push_back(1);
            }

            do
            {
                int cnt = 0;
                // for (auto u : temp)
                //     cout << u << " ";
                // cout << '\n';
                for (int k = 0; k < N; k++)
                {
                    if (temp[k] != 0)
                    {
                        cnt++;
                        sum += arr[k];
                        // cout << "sum : " << sum << '\n';
                    }
                    if (cnt == i)
                    {
                        break;
                    }
                }
                m.insert(sum);
                sum = 0;

            } while (next_permutation(temp.begin(), temp.end()));
        }

        // for (auto t : m)
        // {
        //     cout << t << " ";
        // }
        // cout << '\n';

        cout << "#" << tc + 1 << " " << m.size() << '\n';
    }

    return 0;
}
