import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] routes) {
        int res = 1;
        Map<Integer, Integer> map = new HashMap<>();
        
        Arrays.sort(routes, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o1[0] - o2[0]);
        
        int tmp = routes[0][1];
        for(int[] r : routes) {
            
            if(tmp < r[0]) {
                res++;
                tmp = r[1];
            }
            
            if(tmp >= r[1]) tmp = r[1];
            
        }
        
        return res;
        
        
        
    }
}