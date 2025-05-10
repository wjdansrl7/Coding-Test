
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());


		int p1 = Integer.parseInt(st.nextToken());
		int p2 = Integer.parseInt(st.nextToken());

		int res = 0;
		while(p1 != p2) {

			if ((p1 & 1) != 0) {
				p1 =  p1 / 2 + 1;
			} else {
				p1 /= 2;
			}

			if ((p2 & 1) != 0) {
				p2 = p2 / 2 + 1;
			} else {
				p2 /= 2;
			}

			res++;
		}

		System.out.println(res);

	}
}
