
import java.util.*;
import java.io.*;
/**
 *packageName    : _250811
 * fileName       : BOJ_G2_1766_문제집
 * author         : moongi
 * date           : 8/11/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		List<Integer>[] problems = new List[N + 1];
		for (int i = 0; i < N + 1; i++) {
			problems[i] = new ArrayList<>();
		}

		int[] indegree = new int[N + 1];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			problems[a].add(b);
			indegree[b]++;
		}

		PriorityQueue<Integer> q = new PriorityQueue<>();

		for (int i = 1; i < N + 1; i++) {
			if (indegree[i] == 0)
				q.offer(i);
		}

		StringBuilder sb = new StringBuilder();

		while (!q.isEmpty()) {

			int p = q.poll();

			sb.append(p + " ");

			for(Integer next : problems[p]) {

				indegree[next]--;
				if (indegree[next] == 0) {
					q.offer(next);
				}
			}
		}

		System.out.println(sb);
	}
}