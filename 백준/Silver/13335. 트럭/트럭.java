import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n, w, l;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());

        ArrayDeque<Integer> truck = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            truck.offer(Integer.parseInt(st.nextToken()));
        }

        ArrayDeque<Integer> q = new ArrayDeque<>();

        for (int i = 0; i < w; i++) {
            q.offer(0);
        }

        int time = 0, sum = 0;
        while (!q.isEmpty()) {
            time++;
            sum -= q.poll();

            if (!truck.isEmpty()) {
                if (truck.peek() + sum <= l) {
                    sum += truck.peek();
                    q.offer(truck.poll());
                } else {
                    q.offer(0);
                }
            }
        }

        System.out.println(time);

    }
}