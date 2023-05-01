/*
문제 풀지 X
나는 sequence별로 스케줄링하는 케이스와 non-preemptive sjf로 스케줄링하는 케이스로
나누어서 그 중 min값을 구하려고 했으나, 다른 사람의 풀이는 애초에 sjf로 하는 경우가
가장 최소일 것으로 가정하고 문제를 푼 것 같다. 풀이를 확인하는 과정에서 priority_queue에서
안에 값들을 정렬하는 부분에서 까먹은 부분을 보완했던 것 같다.

#TODO: priority_queue는 기본적으로 내림차순 정렬이기 때문에 cmp함수에서 ">" 하면 일반적으로
정렬함수라고 생각한다면 내림차순으로 되겠지만, 반대이므로 오름차순으로 정렬되어서
실행시간을 기준으로 오름차순 정렬되어진다.

*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, j = 0, time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

    sort(jobs.begin(), jobs.end());

    while (j < jobs.size() || !pq.empty())
    {
        if (jobs.size() > j && time >= jobs[j][0])
        {
            pq.push(jobs[j++]);
            continue;
        }

        if (!pq.empty())
        {
            time += pq.top()[1];

            answer += time - pq.top()[0];

            pq.pop();
        }
        else
            time = jobs[j][0];
    }

    return answer / jobs.size();
}