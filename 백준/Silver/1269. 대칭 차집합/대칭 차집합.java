import java.util.*;
import java.io.*;

/**
 *packageName    : _260218
 * fileName       : BOJ_S4_1269_대칭차집합
 * author         : moongi
 * date           : 2/18/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		HashSet<Integer> set = new HashSet<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < A; i++) {
			set.add(Integer.parseInt(st.nextToken()));
		}

		int sum = 0; // 합집합의 개수
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < B; i++) {
			int target = Integer.parseInt(st.nextToken());

			if (set.contains(target)) {
				sum++;
			}
		}

		sb.append(A + B - sum * 2);
		System.out.println(sb);
	}
}