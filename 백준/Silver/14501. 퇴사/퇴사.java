
import java.io.*;
import java.util.*;


public class Main {
	static class Consume {
		int time;
		int pay;

		public Consume(int time, int pay) {
			this.time = time;
			this.pay = pay;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());

		Consume[] consumes = new Consume[N+1];
		int res = 0;
		ArrayDeque<int[]> q = new ArrayDeque<>();

		for (int i = 1; i < N+1; i++) {
			st = new StringTokenizer(br.readLine());
			consumes[i] = new Consume(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

			if (i + consumes[i].time <= N+1) {
				q.offer(new int[] {i + consumes[i].time, consumes[i].pay});
			}
		}

		while (!q.isEmpty()) {

			int[] p = q.poll();

			res = p[1] > res ? p[1] : res; // maxProfit

			for (int i = p[0]; i < N + 1; i++) {
				if (i + consumes[i].time <= N+1) {
					q.offer(new int[] {i + consumes[i].time, p[1] + consumes[i].pay});
				}

			}

		}

		System.out.println(res);
	}
}
