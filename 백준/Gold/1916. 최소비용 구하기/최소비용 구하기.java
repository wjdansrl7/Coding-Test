import java.util.*;
import java.io.*;

public class Main {
    static int N, M;

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
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        nodes = new List[N + 1];
        for (int i = 0; i < N + 1; i++) nodes[i] = new ArrayList<>();
        int[] dist = new int[N + 1];
        boolean[] v = new boolean[N + 1];

        int from, to, weight;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());
            nodes[from].add(new Node(to, weight));
//            nodes[to].add(new Node(from, weight));
        }

        for (int i = 0; i < N + 1; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        int start, end;
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        dist[start] = 0;

        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.offer(new Node(start, dist[start]));

        while (!pq.isEmpty()) {
            Node p = pq.poll();
            int minVertex = p.to;
//            int min = p.weight;
            int min = dist[p.to];

            if (v[minVertex]) continue;

            v[minVertex] = true;
//            if (minVertex == end) break;
            for (Node node : nodes[minVertex]) {
                if (!v[node.to] && dist[node.to] > min + node.weight) {
                    dist[node.to] = min + node.weight;
//                    System.out.println("node.to = " + node.to + "dist[node.to] = " + dist[node.to]);
                    pq.offer(new Node(node.to, dist[node.to]));
//                    pq.offer(node);
                }
            }
        }

//        for (int i = 0; i < N + 1; i++) {
//            System.out.println("dist = " + dist[i]);
//        }

        System.out.println(dist[end]);


    }
}