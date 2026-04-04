
import java.util.*;
import java.io.*;
/**
 *packageName    : _260404
 * fileName       : BOJ_S2_1260_DFS와BFS
 * author         : moongi
 * date           : 4/4/26
 * description    :
 */
public class Main {
	static List<Integer>[] nodes;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int V = Integer.parseInt(st.nextToken());

		nodes = new List[N + 1];
		for (int i = 1; i < N + 1; i++) {
			nodes[i] = new ArrayList<>();
		}

		int v1, v2;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());

			nodes[v1].add(v2);
			nodes[v2].add(v1);
		}

		for (int i = 1; i < N + 1; i++) {
			Collections.sort(nodes[i]);
		}

		boolean[] visited = new boolean[N + 1];
		DFS(V, visited);
		visited = new boolean[N + 1];
		sb.append('\n');
		BFS(V, visited);

		System.out.println(sb);
	}

	static void DFS(int start, boolean[] visited) {
		ArrayDeque<Integer> stk = new ArrayDeque<>();
		stk.push(start);

		while (!stk.isEmpty()) {
			int curr = stk.pop();

			if (!visited[curr]) {
				visited[curr] = true;
				sb.append(curr).append(' ');
			}

			for (int i = nodes[curr].size() - 1; i >= 0; i--) {
				int nxt = nodes[curr].get(i);
				if (!visited[nxt]) {
					stk.push(nxt);
				}
			}
		}
	}

	static void BFS(int start, boolean[] visited) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.offer(start);
		visited[start] = true;

		while (!q.isEmpty()) {
			int curr = q.poll();
			sb.append(curr).append(' ');

			for (Integer nxt : nodes[curr]) {
				if (visited[nxt]) continue;
				visited[nxt] = true;
				q.offer(nxt);
			}
		}
	}
}