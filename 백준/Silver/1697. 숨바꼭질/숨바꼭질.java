
import java.io.*;
import java.util.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_S1_1697_숨바꼭질
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {

	static class Point implements Comparable<Point> {

		int x, cnt;

		public Point(int x, int cnt) {
			this.x = x;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Point o) {

			return this.cnt - o.cnt;
		}

	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// 해당 위치로부터 X - 1 or X + 1 or 2 * X

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int ans = 0;

		PriorityQueue<Point> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[100_001];
		pq.offer(new Point(N, 0));
		visited[N] = true;

		while (!pq.isEmpty()) {

			Point p = pq.poll();

			if (p.x == K) {
				ans = p.cnt;
				break;
			}

			if (p.x-1 >= 0 && !visited[p.x - 1]) {
				visited[p.x - 1] = true;
				pq.offer(new Point(p.x - 1, p.cnt + 1));
			}

			if (p.x + 1 <= 100_000 && !visited[p.x + 1]) {
				visited[p.x + 1] = true;
				pq.offer(new Point(p.x + 1, p.cnt + 1));
			}

			if (p.x * 2 <= 100_000 && !visited[p.x * 2]) {
				visited[p.x*2] = true;
				pq.offer(new Point(p.x * 2, p.cnt + 1));
			}
		}

		System.out.println(ans);
	}
}