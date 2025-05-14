
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		boolean[][] small = new boolean[N + 1][N + 1];
		boolean[][] large = new boolean[N + 1][N + 1];

		int a, b;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			small[a][b] = true;
			large[b][a] = true;

		}

		for (int k = 1; k < N + 1; k++) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if (small[i][k] && small[k][j]) small[i][j] = true;
				}
			}
		}

		for (int k = 1; k < N + 1; k++) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					if (large[i][k] && large[k][j]) large[i][j] = true;
				}
			}
		}

		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				small[i][j] |= large[i][j];
			}
		}

		int res = 0;
		for (int i = 1; i < N + 1; i++) {

			boolean flag = false;

			for (int j = 1; j < N + 1; j++) {
				if (i == j) continue;
				
				if (!small[i][j]) {
					flag = true;
					break;
				}
			}
			
			if (!flag) res++;
		}

		System.out.println(res);

	}
}