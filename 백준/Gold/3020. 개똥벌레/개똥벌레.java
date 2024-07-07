import java.util.*;
import java.io.*;

public class Main {
    static int N, H;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        int[] imos = new int[H + 1];

        int x;
        for (int i = 0; i < N; i++) {
            x = Integer.parseInt(br.readLine());
            if (i % 2 == 0) {
                imos[0]++;
                imos[x]--;
            } else {
                imos[H]--;
                imos[H-x]++;
            }
        }

        int sum = 0;
        for (int i = 0; i < H + 1; i++) {
            sum += imos[i];
            imos[i] = sum;
        }

        int min = N, cnt = 0;

        for (int i = 0; i < H; i++) {
            if (min > imos[i]) {
                min = imos[i];
                cnt = 1;
            } else if (min == imos[i]) cnt++;
        }
        System.out.println(min + " " + cnt);
    }
}