
import java.util.*;
import java.io.*;

/**
 *packageName    : _250820
 * fileName       : BOJ_S1_2304_창고다각형
 * author         : moongi
 * date           : 8/20/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[1001];

		int max = 0, idx = 1, size = 0;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int L = Integer.parseInt(st.nextToken());
			int H = Integer.parseInt(st.nextToken());

			arr[L] = H;

			if (L > size) size = L;

			if (H > max) {
				idx = L;
				max = H;
			}
		}

		int curr = 0, ans = 0;
		for (int i = 1; i <= idx; i++) {

			if (arr[i] > curr) {
				curr = arr[i];
			}

			ans += curr;
		}

		curr = 0;
		for (int i = size; i > idx; i--) {

			if (arr[i] > curr) {
				curr = arr[i];
			}

			ans += curr;
		}

		System.out.println(ans);
	}
}