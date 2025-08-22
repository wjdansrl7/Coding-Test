
import java.util.*;
import java.io.*;
/**
 *packageName    : _250822
 * fileName       : BOJ_S4_26596_황금칵테일
 * author         : moongi
 * date           : 8/22/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int M = Integer.parseInt(br.readLine());

		Map<String, Long> byName = new HashMap<>();
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			String name = st.nextToken();
			long amount = Long.parseLong(st.nextToken());

			byName.put(name, byName.getOrDefault(name, 0L) + amount);
		}

		if (byName.size() < 2) {
			System.out.println("Not Delicious...");
			return;
		}

		// 값(총량) -> 해당 총량을 가진 재료의 개수
		Map<Long, Integer> freq = new HashMap<>();
		for (long v : byName.values()) {
			freq.put(v, freq.getOrDefault(v, 0) + 1);
		}

		boolean ok = false;
		for (long a : byName.values()) {
			long target = (a * 1618L) / 1000L;

			if (target != a) {
				if (freq.getOrDefault(target, 0) > 0) {
					ok = true;
					break;
				}
			} else {
				if (freq.getOrDefault(target, 0) >= 2) {
					ok = true;
					break;
				}
			}
		}

		System.out.println(ok ? "Delicious!" : "Not Delicious...");

	}
}