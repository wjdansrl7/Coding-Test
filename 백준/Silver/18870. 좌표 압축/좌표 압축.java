import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] sorted = new int[N];
        Map<Integer, Integer> rank = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) arr[i] = sorted[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(sorted);

        int ranked = 0;

        for (int v : sorted) if (!rank.containsKey(v)) rank.put(v, ranked++);
        for (int key : arr) sb.append(rank.get(key)).append(' ');

        System.out.println(sb);
    }
}