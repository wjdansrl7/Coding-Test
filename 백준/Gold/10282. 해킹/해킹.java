import java.util.*;
import java.io.*;

public class Main {
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
    static int[] p;
    static List<Node>[] nodes;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());

        int n, d, c, a, b, s;
        int[] dist;
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            // 초기화
            nodes = new List[n + 1];
            for (int i = 0; i < n + 1; i++) {
                nodes[i] = new ArrayList<>();
            }
            dist = new int[n + 1];

            for (int i = 0; i < n + 1; i++) {
                dist[i] = Integer.MAX_VALUE;
            }

            for (int i = 0; i < d; i++) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                s = Integer.parseInt(st.nextToken());

                nodes[b].add(new Node(a, s));
            }

            PriorityQueue<Node> pq = new PriorityQueue<>();
            boolean[] v = new boolean[n + 1];
            int result = 0, cnt = 0;

            dist[c] = 0;
            pq.offer(new Node(c, dist[c]));

            while (!pq.isEmpty()) {
                Node p = pq.poll();
                int cur = p.to;

                if (v[cur]) continue;

                v[cur] = true;
                cnt++;

                for (Node node : nodes[cur]) {

                    if (!v[node.to] && dist[node.to] > dist[cur] + node.weight) {
                        dist[node.to] = dist[cur] + node.weight;
                        pq.offer(new Node(node.to, dist[node.to]));
                    }
                }
            }
            for (int i = 1; i < n + 1; i++) if (dist[i] != Integer.MAX_VALUE) result = result < dist[i] ? dist[i] : result;
            System.out.println(cnt + " " + result);
        }
    }
}