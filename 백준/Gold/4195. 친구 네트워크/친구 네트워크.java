
import java.util.*;
import java.io.*;

public class Main {

	static int find(int a) {
		if (p[a] == a) return a;

		return p[a] = find(p[a]);
	}

	static int union(int a, int b) {
		a = find(a);
		b = find(b);

		if (a != b) {
			p[b] = a;
			cnt[a] += cnt[b];

		}

		return cnt[a];
	}

	static int[] p;
	static int[] cnt;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = null;
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			Map<String, Integer> map = new HashMap<>();
			int idx = 0;
			int F = Integer.parseInt(br.readLine());

			p = new int[F * 2];
			cnt = new int[F * 2];

			for (int i = 0; i < F * 2; i++) {
				p[i] = i;
				cnt[i] = 1;
			}
			String f1, f2;
			for (int i = 0; i < F; i++) {
				st = new StringTokenizer(br.readLine());

				f1 = st.nextToken();
				f2 = st.nextToken();

				if (!map.containsKey(f1)) {
					map.put(f1, idx++);
				}

				if (!map.containsKey(f2)) {
					map.put(f2, idx++);
				}

				sb.append(union(map.get(f1), map.get(f2)) + "\n");

			}
		}

		System.out.println(sb);

	}
}