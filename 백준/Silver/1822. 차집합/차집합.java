
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		Map<Integer, Integer> map = new HashMap<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			map.put(Integer.parseInt(st.nextToken()), 1);
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			int target = Integer.parseInt(st.nextToken());
			if (map.containsKey(target)) {
				map.put(target, 0);
			}
		}

		StringBuilder sb = new StringBuilder();
		int cnt = 0;
		int[] res = new int[N];
		for (Integer key : map.keySet()) {
			if (map.get(key) == 1) {
				res[cnt++] = key;
			}
		}
		Arrays.sort(res, 0, cnt);

		if (cnt != 0) {
			sb.append(cnt).append('\n');
			for (int i = 0; i < cnt; i++) {
				sb.append(res[i]).append(' ');
			}
			System.out.println(sb);
		}
		else System.out.println(cnt);
	}
}
