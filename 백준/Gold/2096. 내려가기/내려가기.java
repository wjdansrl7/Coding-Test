import java.util.*;
import java.io.*;
/**
 *packageName    : _250517
 * fileName       : BOJ_G5_2096_내려가기
 * author         : moongi
 * date           : 5/17/25
 * description    :
 */
public class Main {
	static int N;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		int[][] arr = new int[N][3];
		int[][] max = new int[N][3];
		int[][] min = new int[N][3];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < 3; i++) {
			max[0][i] = arr[0][i];
			min[0][i] = arr[0][i];
		}

		for (int i = 1; i < N; i++) {

			max[i][0] = Math.max(max[i - 1][0], max[i - 1][1]) + arr[i][0];
			max[i][1] = Math.max(Math.max(max[i - 1][1], max[i - 1][0]), max[i - 1][2]) + arr[i][1];
			max[i][2] = Math.max(max[i - 1][2], max[i - 1][1]) + arr[i][2];

			min[i][0] = Math.min(min[i - 1][0], min[i - 1][1]) + arr[i][0];
			min[i][1] = Math.min(Math.min(min[i - 1][1], min[i - 1][0]), min[i - 1][2]) + arr[i][1];
			min[i][2] = Math.min(min[i - 1][2], min[i - 1][1]) + arr[i][2];
		}

		int maxScore = 0, minScore = 1_000_000;

		for (int i = 0; i < 3; i++) {
			if(max[N-1][i] > maxScore) maxScore = max[N-1][i];
			if(minScore > min[N-1][i]) minScore = min[N-1][i];
		}

		System.out.println(maxScore + " " + minScore);

	}
}