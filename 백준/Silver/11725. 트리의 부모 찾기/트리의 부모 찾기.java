import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static List<Integer>[] p;
    static boolean[] visited;
    static int[] parent;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        p = new List[n + 1];
        parent = new int[n + 1];
        visited = new boolean[n + 1];
        visited[1] = true;

        for (int i = 0; i < n + 1; i++) p[i] = new ArrayList<>();

        int a, b;
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            p[a].add(b);
            p[b].add(a);
        }

        dfs(1);

        for (int i = 2; i < n + 1; i++) sb.append(parent[i]).append('\n');
        System.out.println(sb);
    }

    private static void dfs(int x) {
        for (Integer i : p[x]) {
            if (!visited[i]) {
                parent[i] = x;
                visited[i] = true;
                dfs(i);
            }
        }
    }
}