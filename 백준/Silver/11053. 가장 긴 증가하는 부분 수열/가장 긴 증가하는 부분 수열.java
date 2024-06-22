import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());

        int[] dp = new int[n];
        for (int i = 0; i < n; i++) dp[i] = 1;

        for (int i = 0; i < n; i++) for (int j = i; j >= 0; j--) if (arr[j] < arr[i]) dp[i] = Math.max(dp[i], dp[j] + 1);
        int res = 0;
        for (int i = 0; i < n; i++) if (res < dp[i]) res = dp[i];
        System.out.println(res);
    }
}