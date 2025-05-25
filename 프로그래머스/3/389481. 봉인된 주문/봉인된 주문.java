import java.util.*;
import java.io.*;

class Solution {
    public String solution(long n, String[] bans) {
        String answer = "";
        
        Map<String, Integer> map = new HashMap<>();
        long[] count = new long[12];
        
        count[1] = 26;
        for(int i = 2; i < 12; i++) {
            count[i] = count[i-1] * 26;
        }
        
        for(int i = 0; i < bans.length; i++) {
            map.put(bans[i], 1);
            count[bans[i].length()]--;
        }
        
        long sum = 0;
        
        int size = 0; // 글자 길이
        long idx = 0; // 같은 자리수에서 구해야하는 순서
        for(int i = 1; i < 12; i++) {
            
            if(sum + count[i] < n) sum += count[i];
            else {
                size = i;
                idx = n - sum - 1;
                break;
            }
        }

        int length = size;
        
        
        for (int i = 0; i < size; i++) {
            long pow = (long) Math.pow(26, size - i - 1);
            answer += (char) (idx / pow + 'a');
            idx %= pow;
        }
        
        // 문자열을 길이대로 나눠서 관리?
        
        long ct = 0;
        for(String key : map.keySet()) {
            if(key.length() == length && answer.compareTo(key) >= 0) {
                ct++;
            }
        }
        
        
        while(ct > 0) {

            char[] answers = answer.toCharArray();
            
            int upper = answer.length()-1;
            
            while(upper >= 0 && answers[upper] == 'z') {
                answers[upper] = 'a';
                upper--;
            }
            
            if(upper < 0) {
                answer = "a" + String.valueOf(answers);
                if(map.containsKey(answer)) ct++;
            }
            else {
                answers[upper] += 1;
                if(map.containsKey(String.valueOf(answers))) ct++;
                answer = String.valueOf(answers);
            }
            
            ct--;
        }
           
        return answer;
    }
}