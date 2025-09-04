import java.util.*;
import java.io.*;

/**
 *packageName    : _250904
 * fileName       : BOJ_B2_13300_방배정
 * author         : moongi
 * date           : 9/4/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		int[][] stu = new int[7][2];

		// S: 여학생: 0, 남학생: 1, Y: 학년

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			int S = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());

			stu[Y][S]++;
		}

		int ans = 0;
		for (int i = 1; i < 7; i++) {
			ans += stu[i][0] / K + stu[i][1] / K;

			if (stu[i][0] % K != 0) ans++;
			if (stu[i][1] % K != 0) ans++;
		}

		System.out.println(ans);
	}
}