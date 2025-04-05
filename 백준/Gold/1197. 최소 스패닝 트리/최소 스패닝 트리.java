
import java.util.*;
import java.io.*;

public class Main {
	static int V, E;
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

		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		nodes = new List[V + 1];

		for (int i = 0; i < V + 1; i++) {
			nodes[i] = new ArrayList<Node>();
		}
		int a, b, w;
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());

			nodes[a].add(new Node(b, w));
			nodes[b].add(new Node(a, w));
		}

		PriorityQueue<Node> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[V + 1];
		long res = 0;

		pq.offer(new Node(1, 0));

		while (!pq.isEmpty()) {
			Node curr = pq.poll();

			if (visited[curr.to]) continue;
			visited[curr.to] = true;

			res += curr.weight;

			for (Node node : nodes[curr.to]) {
				if (!visited[node.to]) {
					pq.offer(new Node(node.to, node.weight));
				}
			}
		}

		System.out.println(res);
	}
}