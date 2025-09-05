import java.util.*;
import java.io.*;
/**
 *packageName    : _250905
 * fileName       : BOJ_G4_17179_케이크자르기
 * author         : moongi
 * date           : 9/5/25
 * description    :
 */
public class Main {
	static int N, M, L;
	static int[] pos;

	static boolean feasible(int needPieces, int x) {
		int cnt = 0, last = 0;
		for (int i = 1; i < pos.length; i++) {
			if (pos[i] - pos[last] >= x) {
				cnt++;
				last = i;
				if (cnt >= needPieces) return true;
			}
		}
		return false;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());

		int[] cuts = new int[M];
		for (int i = 0; i < M; i++) {
			cuts[i] = Integer.parseInt(br.readLine());
		}

		pos = new int[M + 2];
		pos[0] = 0;
		System.arraycopy(cuts, 0, pos, 1, M);
		pos[M + 1] = L;

		for (int q = 0; q < N; q++) {
			int Q = Integer.parseInt(br.readLine());
			int needPieces = Q + 1;

			int lo = 1, hi = L, ans = 0;
			while (lo <= hi) {
				int mid = lo + ((hi - lo) >> 1);
				if (feasible(needPieces, mid)) {
					ans = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			sb.append(ans).append('\n');
		}
		System.out.println(sb);
	}
}