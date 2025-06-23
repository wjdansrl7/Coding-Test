
import java.io.*;
import java.util.*;

/**
 *packageName    : _250623
 * fileName       : BOJ_B5_AB
 * author         : moongi
 * date           : 6/23/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		System.out.println(a + b);
	}
}
