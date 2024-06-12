import java.io.*;
import java.util.*;

public class Main {
    static int V, E;

    static class Node implements Comparable<Node>{
        int to, weight;

        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
    static List<Node>[] nodes;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        nodes = new List[V + 1];

        for (int i = 0; i < V + 1; i++) nodes[i] = new ArrayList<>();

        boolean[] v = new boolean[V+1];

        int from, to, weight;
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());

            nodes[from].add(new Node(to, weight));
            nodes[to].add(new Node(from, weight));
        }

        int result = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.offer(new Node(1, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (v[cur.to]) continue;

            v[cur.to] = true;
            result += cur.weight;

            for (Node node : nodes[cur.to]) {
                if (!v[node.to]) {
                    pq.add(node);
                }
            }
        }
        System.out.println(result);
    }
}