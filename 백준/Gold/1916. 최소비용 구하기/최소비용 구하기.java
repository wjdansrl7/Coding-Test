
import java.io.*;
import java.util.*;

/**
 *packageName    : _250706
 * fileName       : BOJ_G5_1916_최소비용구하기
 * author         : moongi
 * date           : 7/6/25
 * description    :
 */
public class Main {
	static class Node implements Comparable<Node> {
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
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());

		List<Node>[] graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		int a, b, c;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			graphs[a].add(new Node(b, c));
		}

		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());

		int[] dist = new int[N + 1];
		for (int i = 0; i < N + 1; i++) {
			dist[i] = Integer.MAX_VALUE;
		}

		dist[start] = 0;

		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[N + 1];
		pq.offer(new Node(start, 0));
		

		while (!pq.isEmpty()) {

			Node curr = pq.poll();
			
			if (!visited[curr.to]) {
				
				visited[curr.to] = true;
				
				for (Node next : graphs[curr.to]) {
	
					if (!visited[next.to] && dist[next.to] > dist[curr.to] + next.weight) {
						dist[next.to] = dist[curr.to] + next.weight;

						pq.offer(new Node(next.to, dist[curr.to] + next.weight));
					}
				}
				
			}

		}

		sb.append(dist[end]);
		System.out.println(sb);

	}
}