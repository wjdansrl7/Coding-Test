import java.io.*;

/**
 *packageName    : _250721
 * fileName       : BOJ_G5_17609_회문
 * author         : moongi
 * date           : 7/21/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {

			String str = br.readLine();
			sb.append(solve(str)).append('\n');

		}

		System.out.println(sb);
	}

	static int solve(String str) {

		int start = 0, end = str.length() - 1;

		while (start < end && str.charAt(start) == str.charAt(end)) {
			start++;
			end--;
		}
		if (start >= end) return 0;
		if (isPal(str, start + 1, end) || isPal(str, start, end - 1)) return 1;
		return 2;
	}

	static boolean isPal(String str, int start, int end) {
		while (start < end) {
			if (str.charAt(start++) != str.charAt(end--)) return false;
		}
		return true;
	}
}