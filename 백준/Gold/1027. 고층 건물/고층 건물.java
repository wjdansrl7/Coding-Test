import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr, cnt;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        cnt = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {

            double curve = Double.MAX_VALUE;
            for (int j = i-1; j >= 0; j--) {
                if (curve > (double) (arr[i] - arr[j]) / (i - j)) {
                    curve = (double) (arr[i] - arr[j]) / (i - j);
                    cnt[i]++;
                }
            }

            curve = -Double.MAX_VALUE;
            for (int j = i+1; j < N; j++) {
                if (curve < (double) (arr[j] - arr[i]) / (j - i)) {
                    curve = (double) (arr[j] - arr[i]) / (j - i);
                    cnt[i]++;
                }
            }
        }
        Arrays.sort(cnt);

        System.out.println(cnt[N-1]);
    }
}