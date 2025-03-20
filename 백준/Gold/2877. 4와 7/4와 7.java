
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = Integer.toBinaryString(Integer.parseInt(br.readLine()) + 1).replace('0', '4').replace('1', '7');

		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < s.length(); i++) {
			sb.append(s.charAt(i));
		}
		System.out.println(sb);
	}
}
