
import java.util.*;
import java.io.*;

/**
 *packageName    : _250623
 * fileName       : BOJ_S2_DFS와BFS
 * author         : moongi
 * date           : 6/23/25
 * description    :
 */
public class Main {
	static List<Integer>[] graphs;
	static int N, M, V;
	static StringBuilder sb;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		graphs = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			graphs[i] = new ArrayList<>();
		}

		int a, b;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			graphs[a].add(b);
			graphs[b].add(a);
		}

		for (int i = 1; i < N + 1; i++) {
			Collections.sort(graphs[i]);
		}

		boolean[] visited = new boolean[N + 1];
		visited[V] = true;
		
		DFS(V, visited);
		sb.append('\n');
		BFS(V);

		System.out.println(sb);

	}

	static void DFS(int start, boolean[] visited) {

		sb.append(start).append(" ");

		for (Integer next : graphs[start]) {
			if (visited[next]) continue;

			visited[next] = true;
			DFS(next, visited);
		}

	}

	static void BFS(int start) {

		ArrayDeque<Integer> q = new ArrayDeque<>();
		boolean[] visited = new boolean[N + 1];

		q.offer(start);
		visited[start] = true;

		while (!q.isEmpty()) {

			int p = q.poll();
			sb.append(p).append(" ");

			for (Integer next : graphs[p]) {
				if (visited[next]) continue;

				visited[next] = true;
				q.offer(next);
			}
		}
	}
}
