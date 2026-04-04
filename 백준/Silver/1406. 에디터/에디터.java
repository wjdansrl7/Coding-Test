
import java.util.*;
import java.io.*;
/**
 *packageName    : _260404
 * fileName       : BOJ_S2_1406_에디터
 * author         : moongi
 * date           : 4/4/26
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		String str = br.readLine();
		LinkedList<Character> list = new LinkedList<>();

		for (int i = 0; i < str.length(); i++) {
			list.add(str.charAt(i));
		}

		ListIterator<Character> iter = list.listIterator();
		while (iter.hasNext()) {
			iter.next();
		}

		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());

			switch (st.nextToken()) {
				case "L":
					if (iter.hasPrevious()) {
						iter.previous();
					}
					break;
				case "D":
					if (iter.hasNext()) {
						iter.next();
					}
					break;
				case "B":
					if (iter.hasPrevious()) {
						iter.previous();
						iter.remove();
					}
					break;
				case "P":
					iter.add(st.nextToken().charAt(0));
					break;
			}
		}

		for (Character c : list) {
			sb.append(c);
		}

		System.out.println(sb);
	}
}
