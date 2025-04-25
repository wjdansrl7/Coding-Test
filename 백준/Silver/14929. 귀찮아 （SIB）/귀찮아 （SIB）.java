import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		long res1 = 0, res2 = 0;
		int x = 0;
		for (int i = 0; i < N; i++) {
			x = Integer.parseInt(st.nextToken());
			res1 += x;
			res2 += x * x;
		}

		sb.append((res1 * res1 - res2) >> 1);
		System.out.println(sb);
	}
}
