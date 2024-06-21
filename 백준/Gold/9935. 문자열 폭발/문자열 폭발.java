import java.util.*;
import java.io.*;

// 문자열의 최대 길이는 1_000_000
// 폭밞 문자열의 길이는 최대 36이기 때문에 시간초과를 걱정하지 않아도 괜찮다.
// stack을 사용하면 get() 메서드를 사용해서 인덱스 접근이 가능하다.

// iter을 사용하면 stack을 순차적으로 출력할 수 있다.
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String str = br.readLine();
        String target = br.readLine();

        Stack<Character> stk = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            stk.push(str.charAt(i));
            int cnt = 0;
            if (stk.size() >= target.length() && stk.peek() == target.charAt(target.length()-1)) {
                for (int j = 0; j < target.length(); j++) if (stk.get(stk.size() - target.length() + j) == target.charAt(j)) cnt++;
                if (cnt == target.length()) for (int j = 0; j < cnt; j++) stk.pop();
            }
        }
        String res = "";
        if (stk.size() == 0) System.out.println("FRULA");
        else {
            for (char c : stk) sb.append(c);
            System.out.println(sb);
        }
    }
}