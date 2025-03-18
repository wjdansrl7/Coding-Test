
import java.io.*;
import java.util.*;

public class Main {
	static class Home {
		int x, y;

		public Home(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static Home[] homes;
	static int res = 200001;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		homes = new Home[N];

		int x, y;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());

			homes[i] = new Home(x, y);
		}

		boolean[] visited = new boolean[N];
		int[] idx = new int[K];
		Arrays.fill(idx, 200001);

		comb(N, K, 0, visited, idx);

		System.out.println(res);

	}

	static void comb(int N, int K, int cnt, boolean[] visited, int[] idx) {
		if (cnt == K) {
			solve(N, K, visited, idx);
			return;
		}

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			idx[cnt] = i;
			comb(N, K, cnt + 1, visited, idx);
			idx[cnt] = 200001;
			visited[i] = false;
		}
	}

	static void solve(int N, int K, boolean[] visited, int[] idx) {
		int max = 0;

		int[] dist = new int[N];
		Arrays.fill(dist, 200001);

		for (int i = 0; i < K; i++) {
			int start = idx[i];

			for (int j = 0; j < N; j++) {
				if (visited[j]) continue;
				dist[j] = Math.min(dist[j], distance(homes[start], homes[j]));
			}
		}

		for (int i = 0; i < N; i++) {
			if(dist[i] != 200001) max = Math.max(max, dist[i]);
		}

		res = Math.min(res, max);
	}

	static int distance(Home home1, Home home2) {
		return Math.abs(home1.x - home2.x) + Math.abs(home1.y - home2.y);
	}
}
