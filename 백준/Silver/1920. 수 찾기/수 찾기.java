import java.io.*;
import java.util.*;

/**
 * packageName    : _241223
 * fileName       : BOJ_S4_수찾기
 * author         : moongi
 * date           : 12/23/24
 * description    :
 */
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        HashMap<Integer, Integer> A = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) A.put(Integer.parseInt(st.nextToken()), 1);

        int M = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) sb.append(A.getOrDefault(Integer.parseInt(st.nextToken()), 0)).append('\n');
        System.out.println(sb);
    }
}