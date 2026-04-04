import java.util.*;
import java.io.*;
/**
 *packageName    : _260404
 * fileName       : BOJ_S3_3273_두수의합
 * author         : moongi
 * date           : 4/4/26
 * description    :
 *
 * 1 2 3 5 7 9 10 11 12
 * a[i] + a[j] = x
 * a[i] = x - a[j]
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		Map<Integer, Integer> map = new HashMap<>();

		for (int i = 0; i < N; i++) map.put(Integer.parseInt(st.nextToken()), i);

		int x = Integer.parseInt(br.readLine());
		int res = 0;

		for (Integer key : map.keySet()) if (map.getOrDefault(x - key, -1) != -1) res++;
		System.out.println(res >> 1);
	}
}
