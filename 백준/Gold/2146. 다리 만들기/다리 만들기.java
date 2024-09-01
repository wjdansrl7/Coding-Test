import javax.imageio.metadata.IIOMetadataFormatImpl;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, res = 100010;
    static int[][] arr, area;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

    static class Point {
        int x, y, idx, dist;
        public Point(int x, int y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }
        public Point(int x, int y, int idx, int dist) {
            this.x = x;
            this.y = y;
            this.idx = idx;
            this.dist = dist;
        }
    }
    static List<Point>[] points;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        arr = new int[N][N];
        area = new int[N][N];
        visited = new boolean[N][N];
        points = new List[N * N + 1];
        for (int i = 0; i < N * N + 1; i++) points[i] = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 각각의 섬에 대해 영역 설정
        int idx = 2;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1 && !visited[i][j]) {
                    color(i, j, idx++);
                }
            }
        }

//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < N; j++) {
//                System.out.print(arr[i][j]+ " ");
//            }
//            System.out.println();
//        }
        for (int i = 1; i < idx; i++) BFS(i);

        System.out.println(res);
    }
    static void BFS(int idx) {
        ArrayDeque<Point> q = new ArrayDeque<>();
        for (Point p : points[idx]) {
            visited = new boolean[N][N];
            q.offer(new Point(p.x, p.y, p.idx, p.dist));
            visited[p.x][p.y] = true;

            while (!q.isEmpty()) {
                Point cur = q.poll();

                if (arr[cur.x][cur.y] != 0 && arr[cur.x][cur.y] != idx) {
                    res = Math.min(res, cur.dist-1);
                }
                if (cur.dist > res) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    // 범위를 벗어나지 않고, 자신의 섬이 아닌 경우와 해당 지역이 바다인 경우
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && area[nx][ny] != cur.idx && !visited[nx][ny]) {
                        // 바다인 경우
                        q.offer(new Point(nx, ny, idx, cur.dist+1));
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    static void color(int x, int y, int idx) {
        ArrayDeque<int[]> q = new ArrayDeque<>();

        q.offer(new int[]{x, y});
        visited[x][y] = true;
        arr[x][y] = idx;

        while (!q.isEmpty()) {
            int[] p = q.poll();

            boolean flag = false;
            for (int d = 0; d < 4; d++) {
                int nx = p[0] + dx[d];
                int ny = p[1] + dy[d];

                // 이후에 다리만들기에 들어갈 경계선 쪽에 섬
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                    if (arr[nx][ny] == 1) {
                        arr[nx][ny] = idx;
                        q.offer(new int[]{nx, ny});
                        visited[nx][ny] = true;
                    } else flag = true;
                }
            }
            if (flag) points[idx].add(new Point(p[0], p[1], idx, 0));
        }
    }
}