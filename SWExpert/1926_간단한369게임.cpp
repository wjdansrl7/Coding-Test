#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    vector<string> arr;

    for (int i = 1; i <= N; i++)
    {
        arr.push_back(to_string(i));
    }

    for (int i = 0; i < N; i++)
    {
        bool flag = true;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '3')
            {
                flag = false;
                cout << "-";
            }
            if (arr[i][j] == '6')
            {
                flag = false;
                cout << "-";
            }
            if (arr[i][j] == '9')
            {
                flag = false;
                cout << "-";
            }
        }
        if (flag)
        {
            cout << arr[i] << " ";
        }
        else
            cout << " ";
    }
    cout << '\n';

    return 0;
}
