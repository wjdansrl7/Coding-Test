
import java.io.*;
import java.util.*;

/**
 *packageName    : _250707
 * fileName       : BOJ_P5_13308_주유소
 * author         : moongi
 * date           : 7/7/25
 * description    :
 */
public class Main {
	static class Edge {
		int to, cost;

		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}

	static class Node implements Comparable<Node> {
		int pos, minOilCost;
		long totalOilCost;

		public Node(int pos, int minOilCost, long totalOilCost) {
			this.pos = pos;
			this.minOilCost = minOilCost;
			this.totalOilCost = totalOilCost;
		}

		@Override
		public int compareTo(Node o) {
			return Long.compare(this.totalOilCost, o.totalOilCost);
		}
	}

	static int N, M;
	static int[] cost;
	static List<Edge>[] graphs;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		cost = new int[N + 1];
		graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			cost[i] = Integer.parseInt(st.nextToken());
		}

		int from, to, weight;

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			weight = Integer.parseInt(st.nextToken());

			graphs[from].add(new Edge(to, weight));
			graphs[to].add(new Edge(from, weight));
		}

		sb.append(dijkstra());
		System.out.println(sb);

	}

	static long dijkstra() {
		// dp[i][j] : i번 정점에 j(minOilCost)를 가지고 방문했을때의 최소 비용
		long[][] dp = new long[N + 1][2501];

		for (int i = 0; i < N + 1; i++) {
			Arrays.fill(dp[i], Long.MAX_VALUE);
		}

		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.offer(new Node(1, cost[1], 0));

		while (!pq.isEmpty()) {
			Node curr = pq.poll();

			if (curr.pos == N)
				return curr.totalOilCost;

			for (Edge next : graphs[curr.pos]) {
				// 다음으로 이동할 방향이 최소 주유비용으로 이동할 수 있을때
				if (dp[next.to][curr.minOilCost] <= curr.totalOilCost + next.cost * curr.minOilCost) continue;

				dp[next.to][curr.minOilCost] = curr.totalOilCost + next.cost * curr.minOilCost;
				pq.offer(new Node(next.to, Math.min(curr.minOilCost, cost[next.to]), dp[next.to][curr.minOilCost]));

			}
		}

		return -1;
	}
}