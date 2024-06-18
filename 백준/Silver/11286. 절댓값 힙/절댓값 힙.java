import java.io.*;
import java.util.*;

public class Main {
    static int N;

    static class Node implements Comparable<Node>{
        long value;
        int dir; // -1: 음수, 1: 양수

        public Node(long value, int dir) {
            this.value = value; // 값을 저장
            this.dir = dir; // 부호
        }
        @Override
        public int compareTo(Node o) {
            if (this.value == o.value) return (int) (this.dir * this.value - o.dir * o.value);
            return (int) (this.value - o.value);
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(br.readLine());

        PriorityQueue<Node> pq = new PriorityQueue<>();
        long x;
        for (int i = 0; i < N; i++) {
            x = Long.parseLong(br.readLine());

            // 배열에 x라는 값을 추가하는 연산
            if (x != 0) {
                if (x < 0) pq.offer(new Node(-x, -1));
                else pq.offer(new Node(x, 1));
            } else {
                if (pq.isEmpty()) {
                    sb.append(0);
                } else {
                    Node p = pq.poll();
                    sb.append(p.value * p.dir);
                }
                sb.append('\n');
            }
        }
        System.out.println(sb);
    }
}