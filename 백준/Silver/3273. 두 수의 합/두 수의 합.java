
import java.util.*;
import java.io.*;

/**
 *packageName    : _250701
 * fileName       : BOJ_S3_3273_두수의합
 * author         : moongi
 * date           : 7/1/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(br.readLine());
		HashMap<Integer, Integer> map = new HashMap<>();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			map.put(Integer.parseInt(st.nextToken()), 1);
		}

		int x = Integer.parseInt(br.readLine());
		int res = 0;

		for (Integer k : map.keySet()) {
			if (map.containsKey(x - k)) {
				res++;
			}
		}

		sb.append(res / 2);
		System.out.println(sb);
	}
}