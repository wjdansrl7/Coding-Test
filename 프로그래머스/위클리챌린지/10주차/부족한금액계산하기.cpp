using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long usePrice = 0;
    
    for(int i=1; i <= count; i++)
    {
        usePrice += price * i;
    }
    
    if(usePrice - money >= 0)
    {
        answer = usePrice - money;
    }
    else
    {
        answer = 0;
    }

    return answer;
}