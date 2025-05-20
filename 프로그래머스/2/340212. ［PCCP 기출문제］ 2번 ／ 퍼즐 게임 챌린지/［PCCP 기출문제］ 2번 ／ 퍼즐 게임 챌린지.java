import java.util.*;
import java.io.*;

/**
* 퍼즐 : 난이도, 소요시간
* 나의 레벨: level
* 퍼즐의 난이도: diff, 퍼즐의 소요 시간: time_cur, 이전 퍼즐의 소요 시간: time_prev
* 
* if(diff <= level) solved (time_cur);
* else solved in (diff - level) * time_cur + time_prev -> 이전 문제를 다시 풀고 와야함;
* time_prev = time_cur * 이전 문제의 개수
* 
* 퍼즐의 난이도: diffs, 소요시간:times, 제한시간: limit
* 제한시간내의 퍼즐을 모두 해결하는데 필요한 최소 숙련도
* bianrySearch
*/

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        int N = diffs.length;
        
        int minLevel = 100_001;
        int maxLevel = 0;
        
        for(int i = 0; i < N; i++) {
            if(diffs[i] > maxLevel) maxLevel = diffs[i];   
            if(minLevel > diffs[i]) minLevel = diffs[i];
        }
        
        int result = maxLevel;
        while(minLevel < maxLevel) {

            int level = (minLevel + maxLevel) >> 1;
            long time = 0;
            int time_prev = 0;
            for(int i = 0; i < N; i++) {
                
                if(level >= diffs[i]) {
                    time += times[i];
                } else {
                    int cnt = diffs[i] - level;
                    
                    // 문제 해결
                    if(i != 0) time += ((times[i] + times[i-1]) * cnt + times[i]);
                    else time += times[i] * (cnt+1);
                }
            }
            
            if(time <= limit) {
                if(result > level) {
                    result = level;
                }
                maxLevel = level;
            } else {
                minLevel = level + 1;
            }
        }
        
        return result;
    }
}