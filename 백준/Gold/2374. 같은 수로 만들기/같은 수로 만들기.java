
import java.util.*;
import java.io.*;
/**
 *packageName    : _250910
 * fileName       : BOJ_G4_2374_같은수로만들기
 * author         : moongi
 * date           : 9/10/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		long ans = 0;

		List<Integer> lists = new ArrayList<>();
		lists.add(arr[0]);
		for (int i = 1; i < N; i++) {
			if (lists.get(lists.size()-1) != arr[i]) lists.add(arr[i]);
		}

		int m = lists.get(0);
		int gmax = lists.get(0);

		for (int i = 1; i < lists.size(); i++) {
			int x = lists.get(i);
			if (x < m) {
				m = x;
			} else if (x > m) {
				ans += (long)(x - m);
				m = x;
			}
			if (x > gmax) gmax =x;
		}

		ans += (long)(gmax - m);
		System.out.println(ans);
		
	}
}