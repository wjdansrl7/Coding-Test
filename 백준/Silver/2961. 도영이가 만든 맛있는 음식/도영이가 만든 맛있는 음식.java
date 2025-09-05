
import java.io.*;
import java.util.*;
/**
 *packageName    : _250905
 * fileName       : BOJ_S2_2961_도영이가만든맛있는음식
 * author         : moongi
 * date           : 9/5/25
 * description    :
 */
public class Main {
	static int[][] arr;
	static int N;
    static long ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		arr = new int[N][2];
		ans = Long.MAX_VALUE;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int S = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());

			arr[i][0] = S;
			arr[i][1] = B;
		}


		for (int i = 1; i < N + 1; i++) {
			boolean[] visited = new boolean[N];
			comb(0, i, 1, 0, visited);
		}

		System.out.println(ans);
		
	}

	static void comb(int cnt, int max, int cSum, int bSum, boolean[] visited) {

		if (cnt == max) {
			int res = Math.abs(cSum - bSum);
			ans = ans > res ? res : ans;

			return;
		}

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;

			visited[i] = true;
			comb(cnt + 1, max, cSum * arr[i][0], bSum + arr[i][1], visited);
			visited[i] = false;
		}
	}
}