import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        
        int wMin = wallet[0] < wallet[1] ? wallet[0] : wallet[1];
        int wMax = wallet[0] < wallet[1] ? wallet[1] : wallet[0];
        
        int bMax = bill[0] < bill[1] ? bill[1] : bill[0];
        int bMin = bill[0] < bill[1] ? bill[0] : bill[1];
        
        while (wMin < bMin || bMax > wMax) {
            
            if(bill[0] < bill[1]) bill[1] /= 2;
            else bill[0] /= 2;
            
            bMax = bill[0] < bill[1] ? bill[1] : bill[0];
            bMin = bill[0] < bill[1] ? bill[0] : bill[1];
            
            answer++;
        }
        
        return answer;
    }
}