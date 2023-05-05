/*
모든 사람들의 무게를 내림차순으로 정렬한 후, 가장 큰 몸무게와 가장 작은 몸무게를 더했을 때,
limit를 넘지 않는다면 하나의 구명보트로 묶어서 태우는 개념으로 문제를 풀이하였다.
그러나, 효율성 부분에서 문제가 생겨서 O(n^2)으로 풀어서 문제가 생긴 것 같아
다른사람의 힌트를 보았는데 나는 차례대로 모든 사람들과 몸무게를 합한 것을 비교했는데 그럴 필요가 없는게
애초에 가장 작은 몸무게의 사람과 합했을 때, limit를 넘는다면 당연히 다른 사람들과 같이 구명보트를
탈 수 없으므로 O(n)으로 문제를 풀이할 수 있었다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    for (int i = 0; i < people.size(); i++)
    {
        int j = people.size() - 1;

        if (people[i] + people[j] <= limit)
        {
            people.erase(people.begin() + j);
        }

        answer++;
    }

    return answer;
}