import java.util.*;
import java.io.*;

/**
 *packageName    : _260315
 * fileName       : BOJ_G4_1197_최소스패닝트리
 * author         : moongi
 * date           : 3/15/26
 * description    :
 *
 * 최소 스패닝 트리(MST, Minimum Spanning Tree)
 * 모든 정점을 잇지만 사이클이 없는 부분 그래프
 *
 * V개의 모든 정점을 연결하는 간선의 수는 (V - 1)개
 */
public class Main {
	static class Node implements Comparable<Node> {
		int to;
		int weight;

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
        StringBuilder sb = new StringBuilder();
        
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());

		nodes = new List[V + 1];
		for (int i = 0; i < V + 1; i++) {
			nodes[i] = new ArrayList<>();
		}

		int A, B, C;
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());

			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());

			nodes[A].add(new Node(B, C));
			nodes[B].add(new Node(A, C));
		}

		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[V + 1];
		int res = 0;

		// 임의의 시작점
		pq.offer(new Node(1, 0));

		while (!pq.isEmpty()) {

			Node cur = pq.poll();

			if (visited[cur.to]) continue;

			visited[cur.to] = true;
			res += cur.weight;

			for (Node next : nodes[cur.to]) {

				if (!visited[next.to]) {
					pq.offer(new Node(next.to, next.weight));
				}
			}
		}
        
        sb.append(res);
		System.out.println(sb);
	}
}