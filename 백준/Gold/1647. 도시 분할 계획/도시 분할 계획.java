import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] p;
    static List<Node> nodes;

    static boolean union(int a, int b) {
        int aRoot = find(a);
        int bRoot = find(b);

        if (aRoot == bRoot) return false;
        p[bRoot] = aRoot;

        return true;
    }

    static int find(int a) {
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    static class Node implements Comparable<Node> {
        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }

        int from, to, weight;

        public Node(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        p = new int[N + 1];
        for (int i = 1; i < N + 1; i++) p[i] = i;

        int from, to, weight;
        nodes = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());
            nodes.add(new Node(from, to, weight));
        }

        Collections.sort(nodes);

        int result = 0, cnt = 0;
        int maxRoad = 0;
        for (Node node : nodes) {
            if (union(node.from, node.to)) {
                result += node.weight;
                maxRoad = node.weight;
                if (++cnt == N - 1) {
                    result -= maxRoad;
                    break;
                }
            }
        }
        System.out.println(result);
    }
}