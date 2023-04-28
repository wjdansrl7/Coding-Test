#include <iostream>

using namespace std;

/*
map을 key값이 아닌 value 기준으로 정렬

map의 기본 정렬 상태
- map은 key값을 기준으로 오름차순 정렬되어 있습니다.
- 내림차순으로 정렬하기를 원한다면
- key값이 int인 경우 맵을 선언 시 greater<int> 비교 함수를 넣어주면 됩니다.
- ex) map<string, int, greater<string>> m;

value값으로 정렬하기
- 정확히는 map을 정렬하는 것이 아니고 map의 요소들을 value값을 기준으로 정렬합니다.

- 두 단계로 진행이 되어야 합니다.
- [1] map을 vector로 이동
- [2] vector를 second 기준으로 정렬

map을 vector로 이동
map의 key value가 <int, int> 일때
vector<pair<int, int>> vec(m.begin(), m.end());

value 기준 비교 함수 작성
map의 key value가 <int, int> 일때

bool cmp(const pair<int, int>&ma, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

정렬
map의 key value가 <int, int> 일때
sort(vec.begin(), vec.end(), cmp);

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define pp pair<int, int>

using namespace std;

map<int, int> m;

bool cmp(const pp &a, const pp &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void Map_Setting()
{
    for (int i = 0; i < 1; ++i)
        m[1]++;
    for (int i = 0; i < 5; ++i)
        m[2]++;
    for (int i = 0; i < 3; ++i)
        m[3]++;
}

int main(int argc, char const *argv[])
{
    Map_Setting();
    for (auto num : m)
    {
        cout << "key:" << num.first << " | value: " << num.second << "\n";
    }

    cout << "\n==============sort=============\n\n";

    vector<pp> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    for (auto num : vec)
    {
        cout << "key: " << num.first << "| value: " << num.second << "\n";
    }
    return 0;
}
