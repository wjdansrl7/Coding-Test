import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        int[] dp = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            dp[i] = arr[i];
        }
        int max = dp[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) if (arr[j] < arr[i]) dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            if (max < dp[i]) max = dp[i];
        }
        System.out.println(max);
    }
}