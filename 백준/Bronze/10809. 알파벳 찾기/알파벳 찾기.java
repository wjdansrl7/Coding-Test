
import java.util.*;
import java.io.*;

/**
 *packageName    : _250729
 * fileName       : BOJ_B2_10809_알파벳찾기
 * author         : moongi
 * date           : 7/29/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		String str = br.readLine();
		int[] alpha = new int[26];
		Arrays.fill(alpha, -1);

		for (int i = 0; i < str.length(); i++) {
			int target = str.charAt(i) - 'a';

			if(alpha[target] == -1) alpha[target] = i;
		}

		for (int i = 0; i < 26; i++) sb.append(alpha[i]).append(" ");

		System.out.println(sb);
	}
}