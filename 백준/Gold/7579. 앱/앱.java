import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] w = new int[n + 1];
        int[] v = new int[n + 1];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) w[i + 1] = Integer.parseInt(st.nextToken());

        int sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            v[i + 1] = Integer.parseInt(st.nextToken());
            sum += v[i + 1];
        }

        int[] dp = new int[sum + 1];

        for (int i = 1; i <= n; i++) for (int j = sum; j >= v[i]; j--) dp[j] = Math.max(dp[j], dp[j - v[i]] + w[i]);
        

        for (int i = 0; i < sum + 1; i++) {
            if (dp[i] >= m) {
                System.out.println(i);
                break;
            }
        }
    }
}