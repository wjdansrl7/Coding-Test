#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> pocketmonNum;
    int numCount = nums.size();

    for (int i = 0; i < numCount; i++)
    {
        pocketmonNum.insert(nums[i]);
    }

    if (pocketmonNum.size() > numCount / 2)
    {
        answer = numCount / 2;
    }
    else
    {
        answer = pocketmonNum.size();
    }

    return answer;
}