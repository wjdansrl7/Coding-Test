
import java.io.*;
import java.util.*;

public class Main {
	static class Nation implements Comparable<Nation> {
		int num;
		int gold;
		int silver;
		int bronze;

		public Nation(int num, int gold, int silver, int bronze) {
			this.num = num;
			this.gold = gold;
			this.silver = silver;
			this.bronze = bronze;
		}

		@Override
		public int compareTo(Nation o) {
			if (this.gold == o.gold) {

				if (this.silver == o.silver) {
					return o.bronze - this.bronze;
				}
				return o.silver - this.silver;
			}

			return o.gold - this.gold;
		}
	}

	static Nation[] nations;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		nations = new Nation[N];

		PriorityQueue<Nation> pq = new PriorityQueue<>();
		int idx, n1, n2, n3;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			idx = Integer.parseInt(st.nextToken());
			n1 = Integer.parseInt(st.nextToken());
			n2 = Integer.parseInt(st.nextToken());
			n3 = Integer.parseInt(st.nextToken());
			nations[i] = new Nation(idx, n1, n2, n3);
			pq.offer(nations[i]);
		}
		
		int res = 1, curr = 0;
		for (Nation nation : pq) {
			if (nation.num == K) {
				curr = res - 1;
				break;
			}
			res++;
		}
		
		for (int i = curr - 1; i >= 0; i--) {
			if (nations[i].gold == nations[curr].gold) {
				if (nations[i].silver == nations[curr].silver) {
					if (nations[i].bronze == nations[curr].bronze) {
						res--;
						continue;
					}
				}
			}
			break;
		}
		System.out.println(res);
	}
}