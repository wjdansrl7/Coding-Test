import java.util.*;
import java.io.*;
public class Main {
    static class Hell {
        int x, y, cnt;
        String str;

        public Hell(int x, int y, int cnt, String str) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.str = str;
        }
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        char[][] arr = new char[n][m];
        HashMap<String, Integer> map = new HashMap<>();
        int[] dx = {-1,0,1,0, -1, -1, 1, 1}, dy = {0, 1, 0, -1, -1, 1,-1, 1};

        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
            }
        }

        String[] target = new String[k];
        ArrayDeque<Hell> q = new ArrayDeque<>();
        for (int i = 0; i < k; i++) {
            target[i] = br.readLine();
            map.put(target[i], 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q.offer(new Hell(i, j, 1, arr[i][j]+""));

                while (!q.isEmpty()) {
                    Hell p = q.poll();

                    if (p.cnt > 5) continue;
                    if (map.containsKey(p.str)) map.put(p.str, map.get(p.str) + 1);

                    for (int d = 0; d < 8; d++) {
                        int nx = (p.x + dx[d]) % n;
                        int ny = (p.y + dy[d]) % m;

                        if (nx < 0) nx += n;
                        if (ny < 0) ny += m;

                        q.offer(new Hell(nx, ny, p.cnt + 1, p.str + arr[nx][ny]));
                    }
                }
            }
        }
        for (int i = 0; i < k; i++) sb.append(map.get(target[i])).append('\n');
        System.out.println(sb);
    }
}