#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;

    sort(times.begin(), times.end());

    long long low = 1;
    long long high = n * (long long)times[times.size() - 1];
    // long long high = n * (long long)times.back();

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long tmp = 0;

        for (long long i = 0; i < times.size(); i++)
        {
            tmp += (mid / (long long)times[i]);
        }

        if (tmp >= n)
        {
            high = mid - 1;
            answer = mid;
        }
        else
            low = mid + 1;
    }

    return answer;
}