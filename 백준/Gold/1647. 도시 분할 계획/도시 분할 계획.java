import javax.management.remote.JMXAddressable;
import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] p;
    static int[][] g;

    static boolean union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot==bRoot) return false;
        p[bRoot] = aRoot;

        return true;
    }

    static int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        p = new int[N+1];
        for (int i = 1; i < N+1; i++) p[i] = i;

        int from, to, weight;
        g = new int[M][3];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());
            g[i] = new int[]{from, to, weight};
        }

        Arrays.sort(g, (o1, o2) -> Integer.compare(o1[2], o2[2]));

        int result = 0, cnt = 0;
        int maxRoad = 0;
        for (int[] edge : g) {
            if (union(edge[0], edge[1])) {
                maxRoad = edge[2] > maxRoad ? edge[2] : maxRoad;
                result += edge[2];
                if(++cnt==N-1) break;
            }
        }
        System.out.println(result - maxRoad);
    }
}