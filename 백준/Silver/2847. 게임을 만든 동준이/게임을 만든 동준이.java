import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(br.readLine());

        int tmp = arr[N - 1];
        int res = 0;
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] >= tmp) {
                res += (arr[i] - tmp) + 1;
                tmp--;
            } else tmp = arr[i];
        }
        System.out.println(res);
    }
}