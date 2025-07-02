import java.util.*;
import java.io.*;

/**
 *packageName    : _250701
 * fileName       : BOJ_G4_2015_수들의합4
 * author         : moongi
 * date           : 7/1/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		long[] sum = new long[N + 1];

		// 누적합
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			sum[i] = sum[i-1] + Integer.parseInt(st.nextToken());
		}

		// 누적합이 동일한 경우에 대하여 map에 저장
		HashMap<Long, Long> map = new HashMap<>();
		long ans = 0;

		// if arr[i]를 뺴는 것 없이 ==> arr[i] = 0일 경우, arr[j] == K이기 떄문에, map에 해당 key, value를 저장.
		map.put(0L, 1L);
		for (int i = 1; i < N + 1; i++) {
			// 1 <= i <= j <= N 라고 문제에서 나와있을때,
			// arr[j] - arr[i] = K
			// arr[i] = arr[j] - K 이므로 해당하는 누적합의 개수를 추가해주는 것.
			// j > i 이므로 이전에 누적합 중에 만들 수 있는 수들을 조회하므로 다음과 같이 된다.
			ans += map.getOrDefault(sum[i] - K, 0L);
			map.put(sum[i], map.getOrDefault(sum[i], 0L) + 1);
		}

		sb.append(ans);
		System.out.println(sb);

	}
}