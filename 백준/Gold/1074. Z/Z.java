
import java.io.*;
import java.util.*;

/**
 *packageName    : _250910
 * fileName       : BOJ_G5_1074_Z
 * author         : moongi
 * date           : 9/10/25
 * description    :
 */
public class Main {
	static int N, R, C, ans;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		ans = 0;

		recur(0, 0, (int)Math.pow(2, N));
	}

	static void recur(int r, int c, int size) {

		if (size == 1) {
			System.out.println(ans);
			return;
		}

		int newSize = size / 2;
		if (R < r + newSize && C < c + newSize) {
			recur(r, c, newSize);
		}
		if (R < r + newSize && c + newSize <= C) {
			ans += (size * size) / 4;
			recur(r, c + newSize, newSize);
		}
		if (r + newSize <= R && C < c + newSize) {
			ans += (size * size) / 4 * 2;
			recur(r + newSize, c, newSize);
		}
		if (r + newSize <= R && c + newSize <= C) {
			ans += (size * size) / 4 * 3;
			recur(r + newSize, c + newSize, newSize);
		}
	}
}
