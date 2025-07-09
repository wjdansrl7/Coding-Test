
import java.io.*;
import java.util.*;
/**
 *packageName    : _250709
 * fileName       : BOJ_S3_1463_1로만들기
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	static final int INF = 1_000_000;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int X = Integer.parseInt(br.readLine());
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return Integer.compare(o1[0], o2[0]);
			}
		});

		pq.offer(new int[] {X, 0});
		int ans = INF + 1;
		int[] count = new int[INF + 1];
		Arrays.fill(count, INF + 1);

		while (!pq.isEmpty()) {

			int[] p = pq.poll();

			if (p[0] == 1) {
				if (ans > p[1])
					ans = p[1];
				continue;
			}

			if (p[0] % 3 == 0 && count[p[0] / 3] > p[1] + 1) {
				count[p[0] / 3] = p[1] + 1;
				pq.offer(new int[] {p[0] / 3, p[1] + 1});
			}

			if (p[0] % 2 == 0 && count[p[0] / 2] > p[1] + 1) {
				count[p[0] / 2] = p[1] + 1;
				pq.offer(new int[] {p[0] / 2, p[1] + 1});
			}

			if (count[p[0] - 1] > p[1] + 1) {
				count[p[0] - 1] = p[1] + 1;
				pq.offer(new int[] {p[0] - 1, p[1] + 1});
			}

		}

		System.out.println(ans);
	}
}
