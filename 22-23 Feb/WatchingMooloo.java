import java.io.*;
import java.util.*;

public class WatchingMooloo {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long[] arr = new long[N];
        st = new StringTokenizer(f.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);
        long ans = K+1;
        for (int i = 1; i < N; i++) {
            long distance = arr[i] - arr[i - 1];
            if(distance <= K+1) ans += distance;
            else ans += K + 1;
        }
        System.out.println(ans);
    }
}
