#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int sum, int current)
{
    int ans = 0;
    
    if (current == numbers.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }
    
    
    ans += dfs(numbers, target, sum + numbers[current], current + 1);
    ans += dfs(numbers, target, sum + numbers[current] * -1, current + 1);
    
    
    return ans;
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, target, 0, 0);
    
    
    return answer;
}