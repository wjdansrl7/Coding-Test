
import java.io.*;
import java.util.*;

public class Main {
	static int N, M;
	static int[] p;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int a, b;
		p = new int[N + 1];

		List<Integer>[] computer = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			computer[i] = new ArrayList<>();
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			computer[b].add(a);
		}

		ArrayDeque<Integer> q = new ArrayDeque<>();
		int[] count = new int[N + 1];
		boolean[] visited;

		for (int i = 1; i < N + 1; i++) {
			visited = new boolean[N + 1];
			if (!computer[i].isEmpty()) {
				q.offer(i);
				visited[i] = true;
			}

			while (!q.isEmpty()) {
				int p = q.poll();

				for (Integer com : computer[p]) {
					if (!visited[com]) {
						q.add(com);
						count[i]++;
						visited[com] = true;
					}
				}
			}
		}

		List<Integer> res = new ArrayList<>();
		int result = 0;
		for (int i = 1; i < N + 1; i++) {

			if (count[i] > result) {
				result = count[i];
				res.clear();
				res.add(i);
			} else if (count[i] == result) {
				res.add(i);
			}
		}

		StringBuilder sb = new StringBuilder();

		for(Integer r : res) {
			sb.append(r).append(' ');
		}
		System.out.println(sb);
	}
}
