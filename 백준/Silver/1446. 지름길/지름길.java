
import java.util.*;
import java.io.*;

public class Main {
	static class Road{
		int start;
		int end;
		int dist;

		public Road(int start, int end, int dist) {
			this.start = start;
			this.end = end;
			this.dist = dist;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int D = Integer.parseInt(st.nextToken());

		Road[] roads = new Road[N];

		int s, e, d;
		int idx = 0;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			e = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			if(e <= D) roads[idx++] = new Road(s, e, d);
		}

		ArrayDeque<int[]> q = new ArrayDeque<>();
		int res = D;
		q.offer(new int[] {0, 0});

		while (!q.isEmpty()) {
			int[] p = q.poll();

			if (p[0] > D) continue;

			// System.out.println(p[0] + " " + p[1]);
			if (p[0] == D) {
				if (p[1] < res) {
					res = p[1];
					continue;
				}
			}

			for (int i = 0; i < idx; i++) {
				if (roads[i].start >= p[0]) {
					q.offer(new int[] {roads[i].end, p[1] + roads[i].dist + roads[i].start - p[0]});
				}
			}
			
			if (res > p[1] + D - p[0]) {
				q.offer(new int[] {D, p[1] + D - p[0]});
			}
		}

		System.out.println(res);
	}
}
