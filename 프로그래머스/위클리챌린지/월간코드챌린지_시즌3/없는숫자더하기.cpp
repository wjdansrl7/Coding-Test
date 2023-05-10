/*
1. vector내에 해당 원소가 존재하는지 확인
#include <algorithm>

find(v.begin(), v.end(), 찾을 대상)
리턴 값이 v.end()인 경우 -> 해당 원소가 존재하지 않는 것.
리턴 값이 v.end()가 아닌 경우 => 해당 원소 존재하는 것

2. vector내에서 해당 원소가 위치하는 인덱스 찾기
find(v.begin(), v.end(), 찾을 대상) - v.begin()
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;

    for (int i = 0; i < 10; i++)
    {
        if (find(numbers.begin(), numbers.end(), i) != numbers.end())
            continue;
        else
            answer += i;
    }
    return answer;
}