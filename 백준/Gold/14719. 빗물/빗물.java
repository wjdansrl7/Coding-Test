import java.util.*;
import java.io.*;

/**
 *packageName    : _250820
 * fileName       : BOJ_G5_14719_빗물
 * author         : moongi
 * date           : 8/20/25
 * description    :
 *
 * 현재 인덱스를 기준으로 왼쪽에서 가장 높은 블록과 오른쪽에서 가장 높은 블록에서
 * 최솟값의 블록을 현재 인덱스의 높이와 빼서 빗물의 값을 저장한다.
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int H = Integer.parseInt(st.nextToken()); // 세로
		int W = Integer.parseInt(st.nextToken()); // 가로
		int[] col = new int[W]; // 블록들의 높이

		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < W; i++) {
			col[i] = Integer.parseInt(st.nextToken());
		}

		int ans = 0;
		for (int i = 1; i < W - 1; i++) {

			// 왼쪽
			int left = col[i], right = col[i];
			for (int j = 0; j < i; j++) {
				left = Math.max(col[j], left);
			}

			// 오른쪽
			for (int j = i + 1; j < W; j++) {
				right = Math.max(col[j], right);
			}

			ans += Math.min(left, right) - col[i];
		}

		System.out.println(ans);
	}
}