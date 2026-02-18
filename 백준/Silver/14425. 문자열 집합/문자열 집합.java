
import java.util.*;
import java.io.*;

/**
 *packageName    : _260218
 * fileName       : BOJ_S4_14425_문자열집합
 * author         : moongi
 * date           : 2/18/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		String str = "";
		HashSet<String> set = new HashSet<>();
		for (int i = 0; i < N; i++) {
			// str += br.readLine() + " ";
			set.add(br.readLine());
		}

		int result = 0;
		for (int i = 0; i < M; i++) {
			String target = br.readLine();

			if (set.contains(target)) {
				result++;
			}
		}

		System.out.println(result);

	}
}