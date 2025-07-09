
import java.io.*;
import java.util.*;
/**
 *packageName    : _250709
 * fileName       : BOJ_S5_1010_다리놓기
 * author         : moongi
 * date           : 7/9/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		while (T-- > 0) {

			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());

			if (M / 2 < N) N = M - N;

			long sum = 1;

			for (int i = M - N + 1; i <= M; i++) {
				sum *= i;
			}

			for (int i = 1; i <= N; i++) {
				sum /= i;
			}

			sb.append(sum).append('\n');
		}

		System.out.println(sb);
	}
}