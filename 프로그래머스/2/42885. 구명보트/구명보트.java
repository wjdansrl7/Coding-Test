import java.util.*;
import java.io.*;

// 한번에 최대 2명
// 50 50 70 80
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int N = people.length;
        
        Arrays.sort(people);
        
        int j = 0;
        for(int i = N - 1; i >= j; i--) {
            if (people[i] + people[j] <= limit) {
                j++;
            }
            answer++;
        }
        
        return answer;
    }
}