import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int res = Integer.MAX_VALUE;
	static int[][] arr;
	static boolean[] v;

	static void subs(int cnt, int sin_sum, int dan_sum) {
		if (cnt == n) {
			int falseCnt = 0;
			for (int i = 0; i < n; i++) {
				if (!v[i])
					falseCnt++;
			}
			if (falseCnt == n)
				return;
			res = Math.min(res, Math.abs(dan_sum - sin_sum));
			return;
		}
		
		v[cnt] = true;
		subs(cnt + 1, sin_sum * arr[cnt][0], dan_sum + arr[cnt][1]);
		v[cnt] = false;
		subs(cnt + 1, sin_sum, dan_sum);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		n = Integer.parseInt(br.readLine());
		arr = new int[n][2];
		v = new boolean[n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());

		}
		subs(0, 1, 0);

		System.out.println(res);

	}
}