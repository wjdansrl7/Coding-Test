import java.util.*;
import java.io.*;
/**
 *packageName    : _250731
 * fileName       : BOJ_G5_13549_숨바꼭질3
 * author         : moongi
 * date           : 7/31/25
 * description    :
 */
public class Main {
	static class Point implements Comparable<Point> {
		int x;
		long cnt;

		public Point(int x, long cnt) {
			this.x = x;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Point o) {
			return Long.compare(this.cnt, o.cnt);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		PriorityQueue<Point> pq = new PriorityQueue<>();
		long[] visited = new long[100001];
		Arrays.fill(visited, Long.MAX_VALUE);

		long ans = Long.MAX_VALUE;
		pq.offer(new Point(N, 0));
		visited[N] = 0;

		while (!pq.isEmpty()) {

			Point p = pq.poll();

			if (p.x == K) {

				if (ans > p.cnt) {
					visited[K] = p.cnt;
					ans = p.cnt;
				}
				continue;
			}

			if (p.x * 2 <= 100000 && visited[p.x * 2] > p.cnt) {
				visited[p.x * 2] = p.cnt;
				pq.offer(new Point(p.x * 2, p.cnt));
			}

			if (p.x - 1 >= 0 && visited[p.x - 1] > p.cnt + 1) {
				visited[p.x - 1] = p.cnt + 1;
				pq.offer(new Point(p.x - 1, p.cnt + 1));
			}

			if (p.x + 1 <= 100000 && visited[p.x + 1] > p.cnt + 1) {
				visited[p.x + 1] = p.cnt + 1;
				pq.offer(new Point(p.x + 1, p.cnt + 1));
			}
		}

		System.out.println(ans);
	}
}