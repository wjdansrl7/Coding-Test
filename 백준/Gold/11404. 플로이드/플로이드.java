
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int[][] dist = new int[n][n];
		int INF = 1_000_000_000;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) dist[i][j] = 0;
				else dist[i][j] = INF;
			}
		}

		int m = Integer.parseInt(br.readLine());

		int a, b, c;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());

			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());

			if(dist[a-1][b-1] == INF) dist[a-1][b-1] = c;
			else dist[a - 1][b - 1] = dist[a - 1][b - 1] > c ? c : dist[a - 1][b - 1];
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == INF) sb.append(0).append(' ');
				else sb.append(dist[i][j]).append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
