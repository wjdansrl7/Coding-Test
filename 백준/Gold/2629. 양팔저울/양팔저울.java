import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		Set<Integer> weight = new HashSet<>();

		for (int i = 0; i < N; i++) {
			Set<Integer> next = new HashSet<>();
			for (Integer w : weight) {
				next.add(w + arr[i]);
				next.add(Math.abs(w - arr[i]));
			}
			next.add(arr[i]);
			weight.addAll(next);
		}

		int T = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		while (T-- > 0) {
			// 구하고자하는 추의 무게
			int W = Integer.parseInt(st.nextToken());

			if (weight.contains(W)) sb.append("Y ");
			else sb.append("N ");
		}

		System.out.println(sb);
	}
}