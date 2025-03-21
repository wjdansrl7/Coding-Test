
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] dist = new int[N + 1];

		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			dist[i] = Integer.parseInt(st.nextToken());
		}

		int start, end, k;
		int[] dists = new int[N + 2];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			dists[start] += k;
			dists[end + 1] -= k;
		}

		for (int i = 1; i < N + 1; i++) {
			dists[i] = dists[i - 1] + dists[i];
		}

		for (int i = 1; i < N + 1; i++) {
			dist[i] = dists[i] + dist[i];
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < N + 1; i++) {
			sb.append(dist[i]).append(' ');
		}
		System.out.println(sb);
	}
}
