import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] graph;
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        visited = new boolean[N + 1];
        graph = new List[N + 1];
        for (int i = 0; i < N + 1; i++) graph[i] = new ArrayList<>();

        int a, b;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }

        int res = 0;
        for (int i = 1; i < N + 1; i++) {
            if (!visited[i]) {
                bfs(i);
                res++;
            }
        }
        System.out.println(res);
    }
    static void bfs(int idx) {
        if (visited[idx]) return;

        visited[idx] = true;
        for (int i = 0; i < graph[idx].size(); i++) if (!visited[graph[idx].get(i)]) bfs(graph[idx].get(i));
    }
}