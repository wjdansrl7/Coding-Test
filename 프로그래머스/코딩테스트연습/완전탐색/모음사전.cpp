// 모든 경우의 수가 많지 않으므로 모든 경우의 수를 arr에 저장하고, 완전탐색을 하는 경우

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr;
string temp[5] = {"A", "E", "I", "O", "U"};

void go(int maxlen, string s)
{
    if (maxlen == s.size())
    {
        arr.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        go(maxlen, s + temp[i]);
    }
}

int solution(string word)
{
    int answer = 0;
    for (int i = 1; i <= 5; i++)
    {
        go(i, "");
    }

    sort(arr.begin(), arr.end());
    answer = find(arr.begin(), arr.end(), word - arr.begin() + 1);

    return answer;
}

// 두 번째 풀이
/*
1. ""을 시작으로 dfs 수행
2. "AEIOU" 문자열을 순회하면서 dfs 수행
3. dfs 수행할 때마다 cnt++(사전에서의 단어 위치)
4. 현재 단어가 사전에서 몇 번째인지 탐색하려는 단어와 같으면 answer = cnt
*/

#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string aeiou = "AEIOU";

void dfs(string word)
{
    cnt++;

    if (word == target)
    {
        answer = cnt;
        return;
    }

    if (word.length() >= 5)
    {
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        dfs(word + aeiou[i]);
    }
}

int solution(string word)
{
    target = word;
    dfs("");

    return answer;
}