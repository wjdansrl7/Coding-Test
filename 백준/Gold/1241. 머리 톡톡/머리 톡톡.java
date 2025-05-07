import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		// 해당 위치에 적혀있는 모자의 숫자
		int[] arr = new int[N];
		// 현재 모자에 적혀져있는 숫자들의 개수
		Map<Integer, Integer> map = new HashMap<>();

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
		}

		int[] cnt = new int[N];

		for (int i = 0; i < N; i++) {
			int curr = arr[i];
			int sq = (int) Math.sqrt(curr);

			// 동일한 약수인 경우 하나만 나와야한다.
			if (sq * sq == curr) {
				cnt[i] -= map.getOrDefault(sq, 0);
			} else {
				cnt[i] = 0;
			}

			for (int j = 1; j <= sq; j++) {
				if (curr % j == 0) {
					cnt[i] += map.getOrDefault(j, 0) + map.getOrDefault(curr / j, 0);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			sb.append(cnt[i] - 1).append('\n');
		}

		System.out.println(sb);

	}
}