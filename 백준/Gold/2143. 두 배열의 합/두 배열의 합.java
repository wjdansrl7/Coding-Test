import java.util.*;
import java.io.*;
/**
 *packageName    : _250518
 * fileName       : BOJ_G3_2143_두배열의합
 * author         : moongi
 * date           : 5/18/25
 * description    :
 *
 * 두 배열의 연속된 부 배열의 합이 T가 되는 쌍의 개수를 구하는 문제
 *
 * long 타입 합
 *
 *
 */
public class Main {
	static int T, n, m;
	static int[] A, dpA, B, dpB;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		T = Integer.parseInt(br.readLine());

		n = Integer.parseInt(br.readLine());
		A = new int[n];
		dpA = new int[n + 1];
		long[] sumA = new long[n];
		Map<Long, Integer> mapA = new HashMap<>();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			A[i] = Integer.parseInt(st.nextToken());

			dpA[i+1] = dpA[i] + A[i];

		}

		long target = 0, tmp;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {

				if (i == j) {
					target = A[i-1];
				} else {
					target = dpA[j] - dpA[i - 1];
				}

				mapA.put(target, mapA.getOrDefault(target, 0) + 1);
			}
		}

		m = Integer.parseInt(br.readLine());
		B = new int[m];
		dpB = new int[m+1];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			B[i] = Integer.parseInt(st.nextToken());

			dpB[i + 1] = dpB[i] + B[i];
		}

		long res = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = i; j <= m; j++) {

				if (i == j) {
					target = B[i-1];
				}
				else {
					target = dpB[j] - dpB[i - 1];
				}

				tmp = T - target; // A에 존재하는지에 대한 여부

				if (mapA.containsKey(tmp)) {
					res += mapA.get(tmp);
				}

			}
		}

		System.out.println(res);
		
	}
}