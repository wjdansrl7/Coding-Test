
import java.io.*;
import java.util.*;
/**
 *packageName    : _250729
 * fileName       : BOJ_S4_11508_21세일
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return Integer.compare(o2, o1);
			}
		});

		int amount;
		for (int i = 0; i < N; i++) {
			amount = Integer.parseInt(br.readLine());
			pq.offer(amount);
		}

		int div = 1;
		long ans = 0;
		while (!pq.isEmpty()) {
			if (div++ % 3 != 0) {
				ans += pq.poll();
			} else
				pq.poll();
		}

		System.out.println(ans);
	}
}