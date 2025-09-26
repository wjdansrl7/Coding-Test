
import java.util.*;
import java.io.*;
/**
 *packageName    : _250926
 * fileName       : BOJ_S1_1697_숨바꼭질
 * author         : moongi
 * date           : 9/26/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		if (N >= K) {
			System.out.println(N - K);
			return;
		}

		long res = Long.MAX_VALUE;
		ArrayDeque<int[]> q = new ArrayDeque<>();
		int[] visited = new int[100_001];
		Arrays.fill(visited, Integer.MAX_VALUE);

		q.offer(new int[] {N, 0});
		visited[N] = 0;

		while (!q.isEmpty()) {
			int[] curr = q.poll();

			if (curr[0] == K) {
				res = res > curr[1] ? curr[1] : res;
				continue;
			}

			if (curr[0] + 1 <= 100_000 && visited[curr[0] + 1] > curr[1] + 1) {
				visited[curr[0] + 1] = curr[1] + 1;
				q.offer(new int[] {curr[0] + 1, curr[1] + 1});
			}

			if (curr[0] - 1 >= 0 && visited[curr[0] - 1] > curr[1] + 1) {
				visited[curr[0] - 1] = curr[1] + 1;
				q.offer(new int[] {curr[0] - 1, curr[1] + 1});
			}

			if (curr[0] * 2 <= 100_000 && visited[curr[0] * 2] > curr[1] + 1) {
				visited[curr[0] * 2] = curr[1] + 1;
				q.offer(new int[] {curr[0] * 2, curr[1] + 1});
			}

		}

		System.out.println(res);
	}
}