import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        ArrayDeque<Character> q = new ArrayDeque<>();
        String str;
        for (int i = 0; i < n; i++) {
            str = br.readLine();
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == '(') {
                    q.offer('(');
                } else {
                    if (!q.isEmpty() && q.peekLast() == '(') q.pollLast();
                    else q.offer(')');
                }
            }
            if (q.isEmpty()) sb.append("YES").append('\n');
            else {
                sb.append("NO").append('\n');
                q.clear();
            }
        }
        System.out.println(sb);
    }
}