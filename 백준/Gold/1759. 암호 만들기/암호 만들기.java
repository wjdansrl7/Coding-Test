import java.io.*;
import java.util.*;
/*
 * 4 6
a t c i s w
 */
public class Main {
	static int l,c;
	static char[] password;
	static boolean[] v;
	static StringBuilder sb = new StringBuilder();
	static List<String> res = new ArrayList<>();
	static void Perm(int cnt, String str) {
		if(str.length()==l || cnt==c) {
			if(isChecked(str)) {
				res.add(str);
				return;				
			}
		}
		for (int i = cnt; i < c; i++) {
			if(v[i]) continue;
			v[i]=true;
			Perm(i+1, str+password[i]);
			v[i]=false;
		}
	}
	static boolean isChecked(String str) {
		int cnt = 0, cnt2=0;
		for(int i = 0; i < str.length(); i++ ) {
			if(str.charAt(i)=='a' || str.charAt(i)=='e' || str.charAt(i)=='i' || str.charAt(i)=='o' || str.charAt(i)=='u') {
				cnt++;
			} else cnt2++;
		}
		if(cnt>=1 && cnt2 >=2 && str.length()==l) return true;
		return false;
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		l = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		password = new char[c];
		v = new boolean[c];

		String str = br.readLine();
		int idx = 0;
		for (int i = 0; i < str.length(); i++) {
			if(str.charAt(i) == ' ') continue;
			else password[idx++] = str.charAt(i);
		}
		
		Arrays.sort(password);
		
		Perm(0, "");
		for(String s : res) System.out.println(s);
	}
}