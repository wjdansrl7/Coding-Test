import java.util.*;
import java.io.*;
/**
 * packageName    : _250105
 * fileName       : BOJ_S1_16139_인간컴퓨터상호작용
 * author         : moongi
 * date           : 1/5/25
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        String S = br.readLine();
        int[][] sum = new int[S.length()][26];

        for (int i = 0; i < S.length(); i++) {
            if(i == 0) sum[i][S.charAt(i) - 97]++;
            else {
                // 이전 값의 누적을 합해주고
                for (int j = 0; j < 26; j++) {
                    sum[i][j] += sum[i - 1][j];
                }
                // 현재 자리 수에 있는 문자를 더해준다.
                sum[i][S.charAt(i) - 97]++;
            }
        }
        int q = Integer.parseInt(br.readLine());
        char a;
        int l = 0, r = 0;
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            a = st.nextToken().charAt(0);
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());

            if (S.charAt(l) == a) sb.append(sum[r][a-97] - sum[l][a-97] + 1).append('\n');
            else sb.append(sum[r][a-97] - sum[l][a-97]).append('\n');
        }
        System.out.println(sb);
    }
}
