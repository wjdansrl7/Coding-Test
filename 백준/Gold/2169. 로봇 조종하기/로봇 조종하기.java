
import java.io.*;
import java.util.*;

/**
 *packageName    : _250810
 * fileName       : BOJ_G2_2169_로봇조종하기
 * author         : moongi
 * date           : 8/10/25
 * description    :
 * 로봇은 왼쪽, 오른쪽, 아래쪽으로만 이동할 수 있다.
 * 한 번 지나간 지역은 다시 지나지 않는다.
 * (1,1) -> (N,M)으로 이동할 때, 지역들의 가치가 최대가 되도록 출력하시오.
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] map = new int[N + 1][M + 1], dp = new int[N + 1][M + 1], tmp = new int[2][M + 2];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		dp[1][1] = map[1][1];
		for (int i = 2; i < M + 1; i++) {
			dp[1][i] = dp[1][i - 1] + map[1][i];
		}

		for (int i = 2; i < N + 1; i++) {
			tmp[0][0] = dp[i - 1][1]; // 왼쪽 첫째 값보다 앞의 값(0,0)은 위에서 내려온 값
			for (int j = 1; j < M + 1; j++) { // 왼쪽 -> 오른쪽
				// 좌 -> 우 vs 위 -> 아래 중 큰 값 비교. 위의 tmp[0][0]을 여기서 좌->우 값 구할 때 사용
				tmp[0][j] = Math.max(tmp[0][j - 1], dp[i - 1][j]) + map[i][j];
			}

			tmp[1][M + 1] = dp[i - 1][M]; // 오른쪽 첫째 값보다 뒤의 값(1, M+1)도 위에서 내려온 값
			for (int j = M; j >= 1; j--) {
				tmp[1][j] = Math.max(tmp[1][j + 1], dp[i - 1][j]) + map[i][j];
			}

			for (int j = 1; j <= M; j++) {
				dp[i][j] = Math.max(tmp[0][j], tmp[1][j]);
			}
		}

		System.out.println(dp[N][M]);


	}
}