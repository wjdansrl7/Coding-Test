import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        N = Integer.parseInt(br.readLine());

        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int sum1 = arr[i] + arr[j];
                int start = 0;
                int end = N - 1;

                while (start < end) {
                    if (start == i || start == j) {
                        start++;
                        continue;
                    }
                    if (end == i || end == j) {
                        end--;
                        continue;
                    }
                    int sum2 = arr[start] + arr[end];
                    min = Math.min(min, Math.abs(sum1 - sum2));
                    if (sum1 > sum2) {
                        start++;
                    } else if (sum1 < sum2) {
                        end--;
                    } else {
                        System.out.println(0);
                        return;
                    }
                }
            }
        }
        System.out.println(min);
    }
}