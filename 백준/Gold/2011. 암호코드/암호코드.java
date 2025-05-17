
import java.util.*;
import java.io.*;
/**
 *packageName    : _250517
 * fileName       : BOJ_G5_2011_암호코드
 * author         : moongi
 * date           : 5/17/25
 * description    :
 *
 * input: 5000자리 이하의 암호인데 숫자 형태
 *
 * output: 나올 수 있는 경우의 수
 *
 * 앞에서부터 숫자를 하나 혹은 두 개를 이용하여 판별한다.
 *
 * 경우의 수 1_000_000를 나눠서 출력한다. 해석할 수 없는 경우에는 0을 출력한다.
 *
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();

		long[] dp = new long[str.length()+1];

		dp[0] = 1;

		for (int i = 1; i <= str.length(); i++) {

			int first = str.charAt(i -1) - '0';

			if (first >= 1 && first <= 9) {
				dp[i] += dp[i - 1];
				dp[i] %= 1_000_000;
			}

			if (i == 1) continue;

			int second = str.charAt(i - 2) - '0';

			if (second == 0) continue;

			int sum = second * 10 + first;

			if (sum >= 10 && sum <= 26) {
				dp[i] += dp[i - 2];
				dp[i] %= 1_000_000;
			}
		}

		System.out.println(dp[str.length()]);
	}
}
