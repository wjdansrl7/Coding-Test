
import java.util.*;
import java.io.*;
/**
 *packageName    : _250822
 * fileName       : BOJ_G4_1106_호텔
 * author         : moongi
 * date           : 8/22/25
 * description    :
 */
public class Main {
	static class City {
		int cost, cnt;

		public City(int cost, int cnt) {
			this.cost = cost;
			this.cnt = cnt;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int C = Integer.parseInt(st.nextToken()); // 늘리고자 하는 고객의 수 <= 1000
		int N = Integer.parseInt(st.nextToken()); // 도시의 개수 <= 20

		City[] cities = new City[N];
		int[] dp = new int[1090]; // 최대 한 도시에서 99명을 충당할 수 있는 경우 99 * 11 = 1089명까지가 최대
		Arrays.fill(dp, Integer.MAX_VALUE);

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int cost = Integer.parseInt(st.nextToken()); // 필요한 비용
			int cnt = Integer.parseInt(st.nextToken()); // 늘어나는 고객수

			cities[i] = new City(cost, cnt);
			dp[cnt] = Math.min(dp[cnt], cost); // 해당 고객을 모집하는데 이만큼의 비용이 들어.
		}

		// 최소 C명만큼을 늘릴 수 없는 경우에는 0을 출력해야함.
		for (int i = 1; i < 1090; i++) {
			for (int j = 0; j < N; j++) {
				int cur = i - cities[j].cnt;
				// 현재 해당하는 인원이 자연수이면서, 존재할 경우
				if (cur > 0 && dp[cur] != Integer.MAX_VALUE) {
					dp[i] = Math.min(dp[i], dp[cur] + cities[j].cost);
				}
			}
		}

		int min = Integer.MAX_VALUE;
		for (int i = C; i < 1090; i++) {
			if (min > dp[i]) min = dp[i];
		}
		System.out.println(min);

	}
}
