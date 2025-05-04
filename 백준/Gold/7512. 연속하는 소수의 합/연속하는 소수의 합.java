
import java.io.*;
import java.util.*;

public class Main {

	static boolean[] prime;
	static List<Integer> sosu;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = null;
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());
		int M;

		sosu = new ArrayList<>();
		prime = new boolean[10_000_001];

		makePrime();

		int tc = 1;
		while (T-- > 0) {
			M = Integer.parseInt(br.readLine());
			sb = new StringBuilder();
			Map<Long, Integer> map = new HashMap<>();

			st = new StringTokenizer(br.readLine());

			int res = 10_000_002;
			for (int i = 0; i < M; i++) {
				// 슬라이딩 윈도우의 개수
				int N = Integer.parseInt(st.nextToken());
				long sum = 0L;

				// check 해야함.
				for (int j = 0; j < N; j++) {
					sum += sosu.get(j);
				}

				if (sum <= 10_000_000 && prime[(int)sum]) {
					map.put(sum, map.getOrDefault(sum, 0) + 1);
				}

				int idx = 0;
				while (idx + N < sosu.size()) {
					sum -= sosu.get(idx);
					sum += sosu.get(idx++ + N);

					if (sum > 10_000_000) continue;

					if (!prime[(int)sum]) continue;

					map.put(sum, map.getOrDefault(sum, 0) + 1);

					if (map.getOrDefault(sum, 0) == M) {
						sb.append("Scenario " + tc++ + ":\n");
						sb.append(sum + "\n");
						break;
					}
				}
			}


			System.out.println(sb);
		}

	}

	static void makePrime() {

		for (int i = 0; i < 10_000_001; i++) {
			prime[i] = true;
		}

		prime[0] = false;
		prime[1] = false;

		for (int i = 2; i < Math.sqrt(10_000_001); i++) {

			if (prime[i]) {
				for (int j = i * i; j < 10_000_001; j+= i) {
					prime[j] = false;
				}
			}
		}

		for (int i = 0; i < 10_000_001; i++) {
			if (prime[i]) sosu.add(i);
		}
	}
}