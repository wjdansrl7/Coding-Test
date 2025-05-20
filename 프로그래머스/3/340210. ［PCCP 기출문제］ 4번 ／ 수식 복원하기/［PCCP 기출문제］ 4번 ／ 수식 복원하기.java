import java.util.*;
import java.io.*;

/**
* 가장 큰 자리수 구하기
* 연산했을 때의 결과값을 비교한다.
* 진법을 알았을 경우, 해당 진법을 활용해서 결과값 유추

*/


class Solution {
    
    // 해당 숫자가 진법에 맞는지 판별 여부
    static boolean isValid(String number, int check) {
        
        for(Character c : number.toCharArray()) {
            
            int value = Character.getNumericValue(c);
            
            if(value < 0 || value >= check) return false;
        }
        
        return true;
    }
    
    // 나올 수 있는 최소 진법
    static int getMaxDigit(String number) {
        int max = 0;
        
        for(Character c : number.toCharArray()) {
            if(Character.isDigit(c)) {
                max = Math.max(max, Character.getNumericValue(c));    
            }
        }
        
        return max;
    }
    
    // 주어진 수식에 대하여 진법을 활용해서 나온 결과값 비교
    static void solve(int check, String[] splits, Map<Integer, Integer> map) {
        
        if(!isValid(splits[0], check) || !isValid(splits[2], check)
            || !isValid(splits[4], check)) {
            return;
        }
        
        // 진법에 대한 계산 결과 일치를 map에 저장
        // for(int i = check; i <= 9; i++) {
        int a = Integer.parseInt(splits[0], check);
        int b = Integer.parseInt(splits[2], check);

        int c = splits[1].equals("+") ? a + b : a - b;
        String res = Integer.toString(c, check);

        if(res.equals(splits[4])) {
            map.put(check, map.getOrDefault(check, 0) + 1);
        }
        // }
           
    }
    
    // 여러 진법을 사용해서 나오는 결과값이 하나가 아닌 경우, 해당 수식의 결과값을 확정지을 수 없다.
    static void solveProblem(int check, String[] splits, Set<String> result) {
        
        if(!isValid(splits[0], check) || !isValid(splits[2], check)) {
            return;
        }
        
        int a = Integer.parseInt(splits[0], check);
        int b = Integer.parseInt(splits[2], check);
        int c = splits[1].equals("+") ? a + b : a - b;

        String ans = Integer.toString(c, check);

        result.add(ans);

    }
    
    public String[] solution(String[] expressions) {
        List<String> completeExpressions = new ArrayList<>();
        List<String> notCompleteExpressions = new ArrayList<>();
        
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < expressions.length; i++) {
            if (expressions[i].contains("X")) {
                notCompleteExpressions.add(expressions[i]);
            } else {
                completeExpressions.add(expressions[i]);
            }
        }
        
        // 숫자들로부터 가장 큰 진법 구하기
        int check = 0, min = 0;
        for(String complete : completeExpressions) {

            String[] splits = complete.split(" ");
            
            min = Math.max(getMaxDigit(splits[0]), 
                             Math.max(getMaxDigit(splits[2]), getMaxDigit(splits[4])));
            check = Math.max(check, min + 1);
        }
        
        // 완성된 수식으로부터 어떤 이진법이 올바른 결과값인지 확인하기
        for(String complete : completeExpressions) {
            String[] splits = complete.split(" ");
            
            for(int i = check; i <= 9; i++) {
                solve(i, splits, map);
            }
        }
        
        int nCheck = 0, nMin = 0;
        
        for(String nComplete : notCompleteExpressions) {
            String[] splits = nComplete.split(" ");
            
            nMin = Math.max(Math.max(getMaxDigit(splits[0]), 
                                     getMaxDigit(splits[2])), getMaxDigit(splits[4]));
            nCheck = Math.max(nCheck, nMin + 1);
        }
        
        String[] answer = new String[notCompleteExpressions.size()];
        
        for(int i = 0; i < notCompleteExpressions.size(); i++) {
            String[] splits = notCompleteExpressions.get(i).split(" ");
            
            Set<String> result = new HashSet<>();
            
            for(int j = nCheck; j <= 9; j++) {
                int value = map.getOrDefault(j, 0);
                if(value == completeExpressions.size()) {
                    solveProblem(j, splits, result);        
                }
            }
            
            if(result.size() != 1) {
                answer[i] = splits[0] + " " + splits[1] + " " + splits[2] + " "
                    + splits[3] + " " + "?";
            } else {
                Iterator<String> it = result.iterator();
                if(it.hasNext()) {
                    String value = it.next();
                    answer[i] = splits[0] + " " + splits[1] + " " + splits[2] + " "
                    + splits[3] + " " + value;
                }
            }
        }
      
        
        
        
        
        return answer;
    }
}