import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        int[] dp1 = new int[N];
        int[] dp2 = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            dp1[i] = 1;
        }

        for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) if (arr[j] < arr[i]) dp1[i] = Math.max(dp1[i], dp1[j] + 1);
        for (int i = N-1; i >= 0; i--) for (int j = i; j < N; j++) if (arr[j] < arr[i]) dp2[i] = Math.max(dp2[i], dp2[j] + 1);

        int max = 0;
        for (int i = 0; i < N; i++) if(max < dp1[i]+dp2[i]) max = dp1[i] + dp2[i];
        System.out.println(max);
    }
}