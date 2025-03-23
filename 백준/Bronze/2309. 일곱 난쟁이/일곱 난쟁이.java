
import java.util.*;
import java.io.*;

public class Main {
	static int[] h;
	static boolean[] visited;
	static boolean flag;
	static boolean[] res;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		h = new int[9];
		flag = false;

		for (int i = 0; i < 9; i++) {
			st = new StringTokenizer(br.readLine());
			h[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(h);

		res = new boolean[9];
		boolean[] visited = new boolean[9];
		find(0, visited);

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 9; i++) {
			if (!res[i])
				sb.append(h[i]).append('\n');
		}

		System.out.println(sb);
	}

	static void find(int cnt, boolean[] visited) {
		if (cnt == 2) {
			int sum = 0;
			for (int i = 0; i < 9; i++) {
				if (!visited[i]) sum += h[i];
			}
			if (sum == 100) {
				if (!flag) {
					flag = true;
					for (int i = 0; i < 9; i++) {
						res[i] = visited[i];
					}
				}
				return;
			}
		}

		for (int i = 0; i < 9; i++) {
			if (!visited[i]) {
				visited[i] = true;
				find(cnt + 1, visited);
				visited[i] = false;
			}
		}
	}
}
