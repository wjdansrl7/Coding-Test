
import java.util.*;
import java.io.*;

public class Main {
	static int N;
	static int[][] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		long B = Long.parseLong(st.nextToken());

		arr = new int[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken()) % 1000;
			}
		}

		int[][] res = pow(arr, B);
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sb.append(res[i][j]).append(' ');
			}
			sb.append('\n');
		}

		System.out.println(sb);

	}

	static int[][] pow(int[][] A, long B) {

		if (B == 1L) return A;

		int[][] ret = pow(A, B / 2);

		ret = multiply(ret, ret);

		if (B % 2 == 1L) ret = multiply(ret, arr);

		return ret;
	}

	private static int[][] multiply(int[][] o1, int[][] o2) {

		int[][] ret = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					ret[i][j] += o1[i][k] * o2[k][j];
					ret[i][j] %= 1000;
				}
			}
		}

		return ret;

	}
}
