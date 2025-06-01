
import java.util.*;
import java.io.*;
/**
 *packageName    : _250601
 * fileName       : BOJ_G1_1242_소풍
 * author         : moongi
 * date           : 6/1/25
 * description    :
 *
 */
public class Main {
	static int N, K, M;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		int pos = M - 1;

		int prev = 0;
		int cnt = 0;

		for (int i = N; i > 0; i--) {

			int idx = (prev + (K - 1)) % i;
			cnt++;

			if (pos == idx) {
				sb.append(cnt);
				System.out.println(sb);
				return;
			}

			if (idx < pos) {
				pos--;
			}
			
			prev = idx;
		}
	}
}