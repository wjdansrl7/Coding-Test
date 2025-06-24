
import java.util.*;
import java.io.*;

/**
 *packageName    : _250624
 * fileName       : BOJ_G4_1027_고층건물
 * author         : moongi
 * date           : 6/24/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		int[] height = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		// 더 작아져야 보임
		for (int i = 0; i < N; i++) {
			double dist = Double.MAX_VALUE;

			// 타겟 건물 이전 위치
			for (int j = i - 1; j >= 0; j--) {

				double tmp = (double)(arr[i] - arr[j]) / (i - j);

				if (dist > tmp) {
					dist = tmp;
					height[i]++;
				}
			}

			dist = -Integer.MAX_VALUE;

			// 타겟 건물 이후 위치
			for (int j = i + 1; j < N; j++) {

				double tmp = (double)(arr[j] - arr[i]) / (j - i);

				if (dist < tmp) {
					dist = tmp;
					height[i]++;
				}
			}
		}

		Arrays.sort(height);

		System.out.println(height[N-1]);
	}
}
