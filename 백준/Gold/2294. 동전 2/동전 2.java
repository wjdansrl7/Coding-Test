
import java.util.*;
import java.io.*;

public class Main {
	static class Coin implements Comparable<Coin>{
		int sum;
		int cnt;

		public Coin(int sum, int cnt) {
			this.sum = sum;
			this.cnt = cnt;
		}

		@Override
		public int compareTo(Coin o) {
			if (this.sum == o.sum) {
				return this.cnt - o.cnt;
			}
			return o.sum - this.sum;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(arr);

		PriorityQueue<Coin> pq = new PriorityQueue<>();

		int[] cnt = new int[K + 1];

		for (int i = 0; i < N; i++) {
			if (arr[i] <= K) {
				cnt[arr[i]]++;
				pq.offer(new Coin(arr[i], 1));
			}
		}

		int res = Integer.MAX_VALUE;
		while (!pq.isEmpty()) {
			Coin curr = pq.poll();

			if (curr.sum > K) continue;
			else if (curr.sum == K) {
				res = res > curr.cnt ? curr.cnt : res;
				continue;
			}

			for (int i = 0; i < N; i++) {
				int nSum = curr.sum + arr[i];

				if (nSum <= K) {
					if (cnt[nSum] == 0) {
						pq.offer(new Coin(nSum, curr.cnt + 1));
						cnt[nSum] = curr.cnt + 1;
					}
					else if (cnt[nSum] > 0 && curr.cnt + 1 < cnt[nSum]) {
						pq.offer(new Coin(nSum, curr.cnt + 1));
						cnt[nSum] = curr.cnt + 1;
					}
				} else break;
			}
		}

		if(res == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(res);

	}
}
