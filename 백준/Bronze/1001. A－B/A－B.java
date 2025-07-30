
import java.io.*;
import java.util.*;

/**
 *packageName    : _250730
 * fileName       : BOJ_B5_1001_AB
 * author         : moongi
 * date           : 7/30/25
 * description    :
 */
public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());

		System.out.println(A - B);
	}
}