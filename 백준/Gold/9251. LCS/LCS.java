
import java.util.*;
import java.io.*;
/**
 *packageName    : _260405
 * fileName       : BOJ_G4_9251_LCS
 * author         : moongi
 * date           : 4/5/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str1 = br.readLine();
		String str2 = br.readLine();

		int length1 = str1.length();
		int length2 = str2.length();

		int[][] dp = new int[length1 + 1][length2 + 1];
		
		for (int i = 1; i <= length1; i++) {
			for (int j = 1; j <= length2; j++) {

				if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		System.out.println(dp[length1][length2]);
	}
}