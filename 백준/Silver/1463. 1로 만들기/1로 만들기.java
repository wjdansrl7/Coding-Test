import java.util.*;
import java.io.*;

public class Main {
    static int res = Integer.MAX_VALUE;

    static class Node implements Comparable<Node>{
        int v;
        int cnt;

        public Node(int v, int cnt) {
            this.v = v;
            this.cnt = cnt;
        }
        @Override
        public int compareTo(Node o) {
            if (this.cnt == o.cnt) return this.v - o.v;
            return this.cnt - o.cnt;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x = Integer.parseInt(br.readLine());

        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.offer(new Node(x, 0));

        while (!pq.isEmpty()) {
            Node p = pq.poll();
            if (p.v == 1) {
                res = res > p.cnt ? p.cnt : res;
                break;
            }
            if (p.v % 3 == 0) pq.offer(new Node(p.v/3, p.cnt+1));
            if (p.v % 2 == 0) pq.offer(new Node(p.v/2, p.cnt+1));
            pq.offer(new Node(p.v-1, p.cnt+1));
        }
        System.out.println(res);
    }
}