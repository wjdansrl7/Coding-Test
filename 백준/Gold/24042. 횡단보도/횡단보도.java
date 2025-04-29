import java.util.*;
import java.io.*;

public class Main {
	static class Node implements Comparable<Node> {
		int to;
		long cost;

		public Node(int to, long cost) {
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Node o1) {
			return Long.compare(this.cost, o1.cost);
		}
	}
	static int N, M;
	static List<Node>[] nodes;
	static long[] dist;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		nodes = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			nodes[i] = new ArrayList<>();
		}

		dist = new long[N + 1]; // 각 도로까지 이동했을 떄 최소한의 시간을 저장

		for (int i = 0; i < N + 1; i++) {
			dist[i] = Long.MAX_VALUE;
		}

		int a, b;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			nodes[a].add(new Node(b, i));
			nodes[b].add(new Node(a, i));

		}

		// 해당 위치에 도착했을 때, 종료
		PriorityQueue<Node> pq = new PriorityQueue<>();

		dist[1] = 0;
		pq.offer(new Node(1, 0)); // 현재 위치, 현재 위치까지 걸린 시간

		while (!pq.isEmpty()) {

			Node curr = pq.poll();

			if (curr.cost > dist[curr.to]) {
				continue;
			}

			for (Node next : nodes[curr.to]) {
				int nextIdx = next.to;
				long nextCost;

				if (curr.cost <= next.cost) {
					nextCost = next.cost + 1;
				} else {
					nextCost = ((long)Math.ceil(((double)curr.cost - next.cost) / M)) * M + next.cost + 1;
				}
				if (nextCost < dist[nextIdx]) {
					dist[nextIdx] = nextCost;
					pq.offer(new Node(nextIdx, nextCost));
				}
			}
		}

		System.out.println(dist[N]);

	}
}
