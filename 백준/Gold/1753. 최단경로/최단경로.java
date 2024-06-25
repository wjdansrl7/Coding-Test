import java.util.*;
import java.io.*;

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
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        int start = Integer.parseInt(br.readLine());

        List<Node>[] nodes = new List[V + 1];

        for (int i = 0; i < V + 1; i++) {
            nodes[i] = new ArrayList<>();
        }

        int u, v, w;
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            nodes[u].add(new Node(v, w));
        }

        int[] dist = new int[V + 1];
        for (int i = 0; i < V + 1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        dist[start] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[V + 1];
        pq.offer(new Node(start, dist[start]));

        while (!pq.isEmpty()) {
            Node curr = pq.poll();

            if (visited[curr.to]) continue;

            visited[curr.to] = true;

            for (Node n : nodes[curr.to]) {
                if (visited[n.to]) {
                    continue;
                }
                if (dist[n.to] > dist[curr.to] + n.weight) {
                    dist[n.to] = dist[curr.to] + n.weight;
                    pq.offer(new Node(n.to, dist[n.to]));
                }
            }
        }
        for (int i = 1; i < V + 1; i++) {
            if (dist[i] == Integer.MAX_VALUE) sb.append("INF").append('\n');
            else sb.append(dist[i]).append('\n');
        }
        System.out.println(sb);
    }
}