
import java.util.*;
import java.io.*;
/**
 *packageName    : _260218
 * fileName       : BOJ_S4_1302_베스트셀러
 * author         : moongi
 * date           : 2/18/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		TreeMap<String, Integer> map = new TreeMap<>();

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			map.put(str, map.getOrDefault(str, 0) + 1);
		}

		int max = 0;
		String bestSeller = "";
		for (Map.Entry<String, Integer> entry : map.entrySet()) {
			if (entry.getValue() > max) {
				max = entry.getValue();
				bestSeller = entry.getKey();
			}
		}

		System.out.println(bestSeller);
	}
}