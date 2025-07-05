
import java.util.*;
import java.io.*;

/**
 *packageName    : _250703
 * fileName       : BOJ_G3_1644_소수의연속합
 * author         : moongi
 * date           : 7/5/25
 * description    :
 * 연속된 소수의 합으로 나타낼 수 있는 경우의수
 * 소수는 한번만 사용 가능
 * 8 * 10^9
 */
public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		// 에라토스테네스의 체를 통한 소수 구현
		boolean[] prime = sieveOfEratosthenes(N);
		List<Integer> sosu = new ArrayList<>();
		sosu.add(0);

		// 소수들을 리스트에 저장
		for (int i = 0; i < N + 1; i++) {
			if (!prime[i]) sosu.add(i);
		}

		long[] sum = new long[sosu.size()];

		for (int i = 1; i < sosu.size(); i++) {
			sum[i] = sum[i - 1] + sosu.get(i);
		}

		// i <= j
		// sum[j] - sum[i] = N
		// sum[i] = sum[j] - N

		Map<Long, Integer> map = new HashMap<>();
		int ans = 0;

		map.put(0L, 1);

		for (int j = 1; j < sosu.size(); j++) {

			ans += map.getOrDefault(sum[j] - N, 0);

			map.put(sum[j], map.getOrDefault(sum[j], 0) + 1);
		}

		System.out.println(ans);

	}

	static boolean[] sieveOfEratosthenes(int N) {

		boolean[] prime = new boolean[N + 1];

		prime[0] = true;
		prime[1] = true;

		for (int i = 2; i <= Math.sqrt(N); i++) {

			if (prime[i]) continue;

			for (int j = i * i; j < prime.length; j += i) {
				prime[j] = true;
			}
		}

		return prime;
	}
}