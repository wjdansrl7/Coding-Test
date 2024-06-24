import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        ArrayDeque<Integer> stk = new ArrayDeque<>();
        int x;
        for (int i = 0; i < K; i++) {
            x = Integer.parseInt(br.readLine());
            if (x == 0) stk.pop();
            else stk.push(x);
        }
        long sum = 0;
        while (!stk.isEmpty()) sum += stk.pop();
        System.out.println(sum);
    }
}