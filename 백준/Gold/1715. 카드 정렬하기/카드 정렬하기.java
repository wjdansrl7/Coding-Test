import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		PriorityQueue<Long> pq = new PriorityQueue<>();

		for (int i = 0; i < N; i++) {
			pq.offer(Long.parseLong(br.readLine()));
		}

		if (pq.size() == 1) {
			System.out.println(0);
			return;
		}

		int res = 0;
		while (!pq.isEmpty()) {
			Long cur1 = pq.poll();
			Long cur2 = pq.poll();

			res += cur1 + cur2;

			if (pq.isEmpty()) {
				break;
			}

			pq.offer(cur1 + cur2);
		}

		System.out.println(res);
	}
}