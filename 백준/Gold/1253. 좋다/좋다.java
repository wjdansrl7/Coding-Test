import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] arr;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        int res = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        for (int i = 0; i < N; i++) {
            int l = 0, r = N - 1;
            while (true) {
                if (l == i) l++;
                else if (r == i) r--;
                if (l >= r) break;
                if (arr[i] < arr[l] + arr[r]) {
                    r--;
                } else if (arr[i] > arr[l] + arr[r]) {
                    l++;
                } else {
                    if (r != i && l != i) {
                        res++;
                        break;
                    }
                }
            }
        }
        System.out.println(res);
    }
}