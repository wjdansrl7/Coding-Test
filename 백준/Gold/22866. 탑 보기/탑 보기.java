import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] h = new int[n + 1];
        int[] cnt = new int[n + 1], near = new int[n + 1];
        ArrayDeque<Integer> stk;

        for (int i = 1; i <= n; i++) {
            h[i] = Integer.parseInt(st.nextToken());
            near[i] = -100_000;
        }

        // left
        stk = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            while (!stk.isEmpty() && h[stk.peek()] <= h[i]) {
                stk.pop();
            }
            cnt[i] = stk.size();
            if (cnt[i] > 0) near[i] = stk.peek();
            stk.push(i);
        }

        // right
        stk = new ArrayDeque<>();
        for (int i = n; i > 0; i--) {
            while (!stk.isEmpty() && h[stk.peek()] <= h[i]) {
                stk.pop();
            }
            int s = stk.size();
            cnt[i] += s;
            if (s > 0 && stk.peek()-i < i-near[i]) near[i] = stk.peek();
            stk.push(i);
        }

        // result
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(cnt[i]);
            if (cnt[i] > 0) {
                sb.append(" ").append(near[i]);
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }
}