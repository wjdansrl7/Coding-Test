#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        vector<int> arr;
        vector<int> temp;
        bool visited[10001] = {
            false,
        };

        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;

            arr.push_back(a);
        }

        temp.push_back(0);
        visited[0] = true;

        for (int i = 0; i < arr.size(); i++)
        {
            int tmpSize = temp.size();

            for (int j = 0; j < tmpSize; j++)
            {
                int sum = temp[j] + arr[i];
                if (!visited[sum])
                {
                    visited[sum] = true;
                    temp.push_back(sum);
                }
            }
        }

        cout << "#" << tc + 1 << " " << temp.size() << '\n';
    }

    return 0;
}
