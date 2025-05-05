
import java.util.*;
import java.io.*;

public class Main {
	static int[] p;
	static List<Integer>[] graphs;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;

		int K = Integer.parseInt(br.readLine());

		int V, E;
		while (K-- > 0) {
			st = new StringTokenizer(br.readLine());

			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());

			p = new int[V + 1];

			graphs = new List[V + 1];
			for (int i = 0; i < V + 1; i++) {
				graphs[i] = new ArrayList<>();
			}

			int a, b;
			for (int i = 0; i < E; i++) {
				st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());

				graphs[a].add(b);
				graphs[b].add(a);
			}

			boolean flag = false;
			for (int i = 1; i < V + 1; i++) {
				if (p[i] != 0) continue;
				if(!BFS(i)) {
					flag = true;
					break;
				}
			}
			if (!flag) sb.append("YES\n");
			else sb.append("NO\n");
		}


		System.out.println(sb);


	}

	static boolean BFS(int start) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		p[start] = 1;
		q.offer(start);

		while (!q.isEmpty()) {

			int curr = q.poll();

			for (Integer next : graphs[curr]) {
				if (p[next] == 0) {
					p[next] = -p[curr];
					q.offer(next);
				} else if (p[next] == p[curr]){
					return false;
				}
			}
		}

		return true;
	}
}