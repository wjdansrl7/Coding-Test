import java.io.*;
import java.util.*;

/**
 * packageName    : _250102
 * fileName       : BOJ_S3_11441_합구하기
 * author         : moongi
 * date           : 1/2/25
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] sum = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (i == 0) sum[i] = arr[i];
            else sum[i] += sum[i - 1] + arr[i];
        }

        int M = Integer.parseInt(br.readLine());

        int a, b;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken())-1;
            b = Integer.parseInt(st.nextToken())-1;
            sb.append(sum[b] - sum[a] + arr[a]).append('\n');
        }
        System.out.println(sb);
    }
}