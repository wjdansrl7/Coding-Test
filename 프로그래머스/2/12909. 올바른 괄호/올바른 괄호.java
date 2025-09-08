import java.util.*;
import java.io.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        ArrayDeque<Character> stk = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if(stk.isEmpty() && c == '(') {
                stk.push(c);
            } else if(!stk.isEmpty()) {
                if (c == '(') stk.push(c);
                else stk.pop();
            } else {
                return false;
            }
        }
        
        if(!stk.isEmpty()) return false;

        

        return answer;
    }
}