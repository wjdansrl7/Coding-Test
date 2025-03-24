
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());

		int res = Math.abs(100 - N);

		boolean[] visited = new boolean[10];

		if (M > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			for (int i = 0; i < M; i++) {
				visited[Integer.parseInt(st.nextToken())] = true;
			}
		}

		int tmp;
		for (int i = 0; i < 1_000_000; i++) {
			String num = String.valueOf(i);

			boolean flag = false;
			for (int j = 0; j < num.length(); j++) {
				if (visited[num.charAt(j)-'0']) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				tmp = Math.abs(N - i) + num.length();
				res = res > tmp ? tmp : res;
			}
		}
		System.out.println(res);
	}
}