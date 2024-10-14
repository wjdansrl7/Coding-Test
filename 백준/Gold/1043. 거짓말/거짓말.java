import java.util.*;
import java.io.*;

public class Main {
    static int N, M, res;
    static int[] p; // 진실을 아는 사람들
    static List<Integer> believer;
    static List<Integer>[] parties;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        res = M;

        p = new int[N+1];
        parties = new List[M+1];

        // 각각의 파티에 대한 번호 저장
        for (int i = 0; i < M + 1; i++) {
            parties[i] = new ArrayList<>();
        }

        // 각각의 노드를 초기화한다.
        for (int i = 0; i < N + 1; i++) {
            p[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        believer = new ArrayList<>();

        if (n > 0) {
            // 진실을 아는 사람들의 번호를 저장한다.
            int idx = 0;
            for (int i = 0; i < n; i++) {
                idx = Integer.parseInt(st.nextToken());
                believer.add(idx);
            }
        }
        int a = 0, b = 0;
        // M개의 파티에 대해서
        for (int i = 1; i < M + 1; i++) {
            st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            parties[i].add(a);

            // 각각의 파티에 대해서 union-find 를 이용한다.
            for (int j = 1; j < n; j++) {
                b = Integer.parseInt(st.nextToken());
                union(a, b);
                parties[i].add(b);
            }
        }

        for (int i = 1; i < M + 1; i++) {
            for(Integer p : parties[i]) {
                if(believer.contains(find(p))) {
                    res--;
                    break;
                }
            }
        }
        System.out.println(res);
    }
    // 부모 노드 찾기
    static int find(int a) {
        if (p[a] == a) {
            return a;
        }
        else {
            return p[a] = find(p[a]);
        }
    }
    // 루트 노드를 거짓말칠 수 없는 사람들로 설정하면 아래의 노드들은 모두 거짓말 할 수 없으므로 계산하기 편하다.
    static boolean union(int a, int b) {
        a = find(a);
        b = find(b);

        if (believer.contains(b)) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        p[b] = a;
        return true;
    }
}