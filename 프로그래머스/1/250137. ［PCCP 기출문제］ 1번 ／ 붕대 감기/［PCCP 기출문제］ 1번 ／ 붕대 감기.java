import java.util.*;
import java.io.*;

/**
* 시전 시간(t) 동안 1초에 x만큼 회복, t초 연속으로 회복 성공할 시, y만큼 추가 회복

* 조건 : 
* 1. 최대 체력을 넘어서 체력을 회복하지 못한다.
* 2. 몬스터에게 공격 당할 시, 체력 회복 하지 못하고 연속 시간은 0으로 초기화
* 3. 체력이 0 이하가 되면 캐릭터가 사망하며, -1을 return 한다.
*/
class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        
        // 연속 시간
        int connection = 0;
        int currHealth = health;
        
        Arrays.sort(attacks, (o1, o2) -> 
                    Integer.compare(o1[0], o2[0]));
        
        // 최대 시간
        int time = attacks[attacks.length-1][0];
        int idx = 0;
        

        for(int i = 0; i <= time; i++) {            
            // 연속 시간이 시전 시간과 동일하다면 추가 체력을 회복한다.
            if(connection == bandage[0]) {
                currHealth = Math.min(currHealth + bandage[2], health);
                connection = 0;
            }
            
            // 몬스터에게 공격 당하는 순간
            if(attacks[idx][0] == i) {
                
                currHealth -= attacks[idx][1];
                connection = 0;
                
                if(currHealth <= 0) return -1;
                
                
                idx++;
            } else {
                // 공격 당하지 않는다면
                currHealth = Math.min(currHealth + bandage[1], health);
                connection++;
            }
        }
        
        return currHealth;
    }
}