import java.util.*;
import java.io.*;

public class Main {
    static int N, M, W;

    static class Node {
        int to, weight;

        public Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static List<Node>[] nodes;
    static int[] dist;
    static final int INF = 987654321;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int TC = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < TC; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            nodes = new List[N + 1];
            dist = new int[N + 1];


            for (int i = 0; i < N + 1; i++) nodes[i] = new ArrayList<>();

            int S, E, T;

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                S = Integer.parseInt(st.nextToken());
                E = Integer.parseInt(st.nextToken());
                T = Integer.parseInt(st.nextToken());

                nodes[S].add(new Node(E, T));
                nodes[E].add(new Node(S, T));
            }

            for (int i = 0; i < W; i++) {
                st = new StringTokenizer(br.readLine());
                S = Integer.parseInt(st.nextToken());
                E = Integer.parseInt(st.nextToken());
                T = Integer.parseInt(st.nextToken());
                nodes[S].add(new Node(E, -T));
            }

            if(BellmanFord()) sb.append("YES").append('\n');
            else sb.append("NO").append('\n');
        }
        System.out.println(sb);
    }

    static boolean BellmanFord() {
        for (int i = 0; i < N + 1; i++) dist[i] = INF;
        boolean flag = false;
        dist[1] = 0;

        for (int i = 1; i < N; i++) {
            flag = false;
            for (int j = 1; j < N + 1; j++) {

                for (Node node : nodes[j]) {
                    if (dist[node.to] > dist[j] + node.weight) {
                        dist[node.to] = dist[j] + node.weight;
                        flag = true;
                    }
                }
            }
            // 더이상 값이 바뀌지 않는 경우
            if (!flag) break;
        }
        if (flag) {
            for (int i = 1; i < N + 1; i++) {
                for (Node node : nodes[i]) {
                    if (dist[node.to] > dist[i] + node.weight) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}