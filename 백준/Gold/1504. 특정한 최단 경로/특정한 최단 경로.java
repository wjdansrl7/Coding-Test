import java.io.*;
import java.util.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_G4_1504_특정한최단경로
 * author         : moongi
 * date           : 7/30/25
 * description    :
 */
public class Main {
	static int N, E;

	static class Node implements Comparable<Node> {
		int vertex, weight;

		public Node(int vertex, int weight) {
			this.vertex = vertex;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o) {

			return weight - o.weight;
		}
	}

	static List<Node>[] graphs;
	static final int INF = 160_000_001;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		int a, b, c;
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			graphs[a].add(new Node(b, c));
			graphs[b].add(new Node(a, c));

		}

		st = new StringTokenizer(br.readLine());
		int v1 = Integer.parseInt(st.nextToken());
		int v2 = Integer.parseInt(st.nextToken());

		// 1 -> v1 -> v2 -> N
		long ans1 = 0, ans2 = 0;
		ans1 += dijkstra(1, v1);
		ans1 += dijkstra(v1, v2);
		ans1 += dijkstra(v2, N);

		// 1 -> v2 -> v1 -> N
		ans2 += dijkstra(1, v2);
		ans2 += dijkstra(v2, v1);
		ans2 += dijkstra(v1, N);

		long ans = (ans1 >= INF && ans2 >= INF) ? -1 : Math.min(ans1, ans2);
		System.out.println(ans);

	}

	static int dijkstra(int start, int end) {

		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[N + 1];

		int[] dist = new int[N + 1];
		Arrays.fill(dist, INF);

		dist[start] = 0;
		pq.offer(new Node(start, 0));

		while (!pq.isEmpty()) {

			Node curr = pq.poll();

			if (!visited[curr.vertex]) {
				visited[curr.vertex] = true;

				for (Node next : graphs[curr.vertex]) {

					if (!visited[next.vertex] && dist[next.vertex] > dist[curr.vertex] + next.weight) {
						dist[next.vertex] = dist[curr.vertex] + next.weight;
						pq.offer(new Node(next.vertex, dist[next.vertex]));
					}
				}
			}
		}

		return dist[end];
	}
}