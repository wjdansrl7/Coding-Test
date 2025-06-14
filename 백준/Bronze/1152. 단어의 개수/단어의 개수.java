
import java.util.*;
import java.io.*;
/**
 *packageName    : _250614
 * fileName       : BOJ_B2_1152_단어의개수
 * author         : moongi
 * date           : 6/14/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] str = br.readLine().split(" ");
		int cnt = 0;

		for (int i = 0; i < str.length; i++) {
			if (str[i].length() > 0)
				cnt++;
		}
		System.out.println(cnt);
	}
}
