
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		int[][] medal = new int[3][N + 1];

		int idx, n1, n2, n3;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			idx = Integer.parseInt(st.nextToken());
			n1 = Integer.parseInt(st.nextToken());
			n2 = Integer.parseInt(st.nextToken());
			n3 = Integer.parseInt(st.nextToken());

			medal[0][idx] = n1;
			medal[1][idx] = n2;
			medal[2][idx] = n3;
		}

		int rank = 1;
		for (int i = 1; i < N + 1; i++) {

			if (i == K) {
				continue;
			}

			if (medal[0][i] > medal[0][K]) {
				rank++;
			} else if (medal[0][i] == medal[0][K]) {
				if (medal[1][i] > medal[1][K]) {
					rank++;
				} else if (medal[1][i] == medal[1][K]) {
					if (medal[2][i] > medal[2][K]) {
						rank++;
					}

				}
			}
		}

		System.out.println(rank);

	}
}