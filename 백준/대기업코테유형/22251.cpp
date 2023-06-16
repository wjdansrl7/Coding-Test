/**
 * @file 22251.cpp / 백준
 * @author 정문기 (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-16
 *
 * @copyright Copyright (c) 2023
 *
 * 처음 문제를 봤을 때 어떻게 풀지 막막했지만, 보여지는 led를 인덱스로 두고 0~9까지 켜지는 값들을
 * vector에 저장했다.
 * 이후 n층부터 1층까지 현재층과 각자리마다 하나의 자리를 기준으로 다른 자리가 없는 led가 있다면 추가하고 겹친다면 제외하는 식으로 해서
 * count를 해주었고, 총 count의 값인 sum이 p보다 작거나 같다면 +1해주는 방식으로 진행하였다.
 */
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string n, x;
int k, p;
vector<int> led[10] = {{1, 2, 3, 5, 6, 7}, {3, 7}, {1, 3, 4, 5, 6}, {1, 3, 4, 6, 7}, {2, 3, 4, 7}, {1, 2, 4, 6, 7}, {1, 2, 4, 5, 6, 7}, {1, 3, 7}, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 6, 7}};
vector<int> c;

int calc(char a, char b)
{
    int cnt = 0;
    if (a == b)
    {
        return cnt;
    }
    else
    {
        c = led[a - '0'];
        cnt = c.size();

        for (int i = 0; i < led[b - '0'].size(); i++)
        {
            if (find(c.begin(), c.end(), led[b - '0'][i]) != c.end())
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    cin >> n >> k >> p >> x;

    // 자리수보다 현재 층의 자리수가 더 낮다면 개수만큼 0은 총 led가 6개이므로
    // 각자리인 0을 제거하려면 6을 빼줘야함.

    // if (n.size() != k)
    // {
    //     for (int i = 0; i < k - n.size(); i++)
    //     {
    //         n.insert(0, 1, '0');
    //     }
    // }
    if (x.size() != k)
    {
        for (int i = 0; i < k - x.size(); i++)
        {
            x.insert(0, 1, '0');
        }
    }

    for (int i = stoi(n); i > 0; i--)
    {
        string str = to_string(i);
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            if (str.size() != k)
            {
                for (int l = 0; l < k - str.size(); l++)
                {
                    str.insert(0, 1, '0');
                }
            }

            sum += calc(str[j], x[j]);
        }

        if (sum <= p)
        {
            // cout << str << '\n';
            ans++;
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}
