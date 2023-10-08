#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int alpha[26] = {
    0,
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string target, str;
    int res = 0;

    cin >> target;

    for (int i = 0; i < target.size(); i++)
    {
        alpha[target[i] - 'A']++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int str_alpha[26] = {
            0,
        };
        cin >> str;

        for (int j = 0; j < str.size(); j++)
            str_alpha[str[j] - 'A']++;

        int sum = 0;
        for (int j = 0; j < 26; j++)
            sum += abs(alpha[j] - str_alpha[j]);

        int diff_len = target.size() - str.size();
        if (sum <= 2 && abs(diff_len) <= 1)
            res++;
    }

    cout << res;

    return 0;
}
