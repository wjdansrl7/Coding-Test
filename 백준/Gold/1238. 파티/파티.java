
import java.util.*;
import java.io.*;

/**
 *packageName    : _250627
 * fileName       : BOJ_G3_1238_파티
 * author         : moongi
 * date           : 6/27/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());

		int[][] graph = new int[N + 1][N + 1];

		int a, b, w;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());

			graph[a][b] = w;
		}

		int[][] res = new int[N+1][2];

		for (int i = 1; i < N+1; i++) {
			Arrays.fill(res[i], 100_001);
		}

		// 1. 현재 위치에서 X로 이동하는 경우

		PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[1], o2[1]);
			}
		});
		int[] dist = new int[N+1];

		for (int i = 1; i < N + 1; i++) {
			q.clear();
			Arrays.fill(dist, 100_001);

			q.offer(new int[] {i, 0});
			dist[i] = 0;

			while (!q.isEmpty()) {

				int[] p = q.poll();

				if(p[0] == X) {
					if (res[i][0] > p[1]) res[i][0] = p[1];
					break;
				}

				for (int j = 1; j < N + 1; j++) {
					if (graph[p[0]][j] == 0) continue;

					if (dist[j] > p[1] + graph[p[0]][j]) {
						dist[j] = p[1] + graph[p[0]][j];
						q.offer(new int[] {j, p[1] + graph[p[0]][j]});
					}
				}
			}
		}

		// 2. X에서 자신의 집으로 이동하는 경우

		for (int i = 1; i < N + 1; i++) {
			q.clear();
			q.offer(new int[] {X, 0});
			Arrays.fill(dist, 100_001);

			while (!q.isEmpty()) {

				int[] p = q.poll();

				if (p[0] == i) {
					if (res[i][1] > p[1]) res[i][1] = p[1];
					break;
				}

				for (int j = 1; j < N + 1; j++) {
					if (graph[p[0]][j] == 0) continue;

					if (dist[j] > p[1] + graph[p[0]][j]) {
						dist[j] = p[1] + graph[p[0]][j];
						q.offer(new int[] {j, p[1] + graph[p[0]][j]});
					}

				}
			}
		}

		int max = 0;

		for (int i = 1; i < N + 1; i++) {
			if (res[i][0] == 100_001 || res[i][1] == 100_001) continue;

			if (res[i][0] + res[i][1] > max) {
				max = res[i][0] + res[i][1];
			}
		}

		System.out.println(max);

	}
}