import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        
        int connection = 0;
        int currHealth = health;
        
        Arrays.sort(attacks, (o1, o2) -> 
                    Integer.compare(o1[0], o2[0]));
        
        int time = attacks[attacks.length-1][0];
        int idx = 0;
        

        for(int i = 0; i <= time; i++) {            
            if(connection == bandage[0]) {
                currHealth = Math.min(currHealth + bandage[2], health);
                connection = 0;
            }
            
            if(attacks[idx][0] == i) {
                
                currHealth -= attacks[idx][1];
                connection = 0;
                
                if(currHealth <= 0) return -1;
                
                
                idx++;
            } else {
                currHealth = Math.min(currHealth + bandage[1], health);
                connection++;
            }
        }
        
        return currHealth;
    }
}