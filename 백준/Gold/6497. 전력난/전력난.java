import java.util.*;
import java.io.*;

public class Main {
    static int m, n;
    static int[] p;

    static class Node implements Comparable<Node>{
        int from, to, weight;

        public Node(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }

    static boolean union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot==bRoot) return false;

        p[bRoot] = aRoot;

        return true;
    }

    static int find(int a) {
        if (p[a]==a) return a;

        return p[a] = find(p[a]);
    }

    static List<Node> nodes;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            if (m == 0 && n == 0) return;

            p = new int[m];

            for (int i = 0; i < m; i++) p[i] = i;

            nodes = new ArrayList<>();
            int from, to, weight;

            long sum = 0;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                from = Integer.parseInt(st.nextToken());
                to = Integer.parseInt(st.nextToken());
                weight = Integer.parseInt(st.nextToken());
                sum += weight;

                nodes.add(new Node(from, to, weight));
            }
            Collections.sort(nodes);

            long result = 0, cnt = 0;
            for (Node node : nodes) {
                if (union(node.from, node.to)) {
                    result += node.weight;

                    if (++cnt == m - 1) {
                        break;
                    }
                }
            }
            System.out.println(sum - result);
        }

    }
}