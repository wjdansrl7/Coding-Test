
import java.util.*;
import java.io.*;

public class Main {
	static int n, m;
	static int[] p;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		p = new int[n];

		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		int a, b;
		int res = 0;
		boolean flag = false;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			if (!flag && !union(a, b)) {
				res = i + 1;
				flag = true;
			}
		}
		System.out.println(res);
	}

	static int find(int a) {
		if (p[a] == a) return a;

		return p[a] = find(p[a]);
	}

	static boolean union(int a, int b) {

		a = find(a);
		b = find(b);

		if (a < b) p[b] = a;
		else if (a > b) p[a] = b;
		else return false;

		return true;
	}
}
