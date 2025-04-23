import java.util.*;
import java.io.*;

public class Main {
	static int N, M;
	static boolean[] visited;
	static long[] guitar;
	static int res = -1;
	static long max = 0;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		visited = new boolean[N];

		guitar = new long[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			st.nextToken();

			String str = st.nextToken();
			int length = str.length() - 1;
			for (int j = 0; j < M; j++) {
				if (str.charAt(j) == 'Y') {
					guitar[i] += 1L << length;
				}
				length--;
			}
		}

		combination(0, 0);

		System.out.println(res);
	}

	static void combination(int cnt, long sum) {
		if (sum > 0) {
			if (sum > max) {
				res = cnt;
				max = sum;
			} else if (sum == max) {
				if (res > cnt) {
					res = cnt;
				}
			}
		}

		if (cnt == N) {
			return;
		}

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			combination(cnt + 1, sum | guitar[i]);
			visited[i] = false;
		}

	}
}