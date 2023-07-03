#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<string> word;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        word.push_back(str);
    }

    int maxResult = 0;
    string str1, str2;
    for (int i = 0; i < n - 1; i++) // 기준이 되는 대상
    {
        for (int j = i + 1; j < n; j++) // 비교할 대상 선택
        {
            int cnt = 0;
            if (word[i] == word[j])
                continue;

            int cmpSize;
            if (word[i].size() < word[j].size())
                cmpSize = word[i].size();
            else
                cmpSize = word[j].size();

            for (int k = 0; k < cmpSize; k++) // 각각의 알파벳 비교
            {
                if (word[i][k] == word[j][k])
                    cnt++;
                else
                    break;

                if (maxResult < cnt)
                {
                    str1 = word[i];
                    str2 = word[j];
                    maxResult = cnt;
                }
            }
        }
    }

    cout << str1 << '\n';
    cout << str2 << '\n';

    return 0;
}