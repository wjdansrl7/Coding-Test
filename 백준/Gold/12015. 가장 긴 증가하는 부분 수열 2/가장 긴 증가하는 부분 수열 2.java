import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
LIS에 대한 구현 방식 -> 이진 탐색을 활용하여 O(nlogN)을 이용하여 해결한다.
배열을 이용하여 시간 비교해보기.
 */
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        int[] LIS = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

        LIS[0] = arr[0];
        int len = 1;

        for (int i = 1; i < N; i++) {
            int key = arr[i];

            if (LIS[len - 1] < key) LIS[len++] = key;
            else {
                int start = 0, end = len;

                while (start < end) {
                    int mid = (start+end) >> 1;

                    if (LIS[mid] >= key) end = mid;
                    else start = mid + 1;
                }
                LIS[end] = key;
            }
        }
        System.out.println(len);
    }
}