import java.io.*;
import java.util.*;


public class StampGrid {
    static char[][] canvas, stamp, my;
    static int N, K;
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(f.readLine());
        while(T-- > 0){
            f.readLine();
            N = Integer.parseInt(f.readLine());
            canvas = new char[N][N];
            for (int i = 0; i < N; i++) {
                canvas[i] = f.readLine().toCharArray();
            }
            K = Integer.parseInt(f.readLine());
            stamp = new char[K][K];
            for (int i = 0; i < K; i++) {
                stamp[i] = f.readLine().toCharArray();
            }
            my = new char[N][N];
            for(int i = 0; i < N; i++) Arrays.fill(my[i], '.');
            boolean flag = false;
            for (int t = 0; t < 4; t++) {
                for (int i = 0; i < N-K+1; i++) {
                    for (int j = 0; j < N-K+1; j++) {
                        paint(i, j);
                    }
                }
                if(equal()) { flag = true; break;}
                rotate();
            }
            if (flag) System.out.println("YES");
            else System.out.println("NO");
        }
    }

    static void paint(int x, int y){
        boolean flag = true;
        for(int i = x; i < x + K; i++){
            for(int j = y; j < y + K; j++){
                if(canvas[i][j] == '.' && stamp[i-x][j-y] == '*') flag = false;
            }
        }
        if(flag){
            for(int i = x; i < x + K; i++){
                for(int j = y; j < y + K; j++){
                    if(my[i][j] == '.') my[i][j] = stamp[i-x][j-y];
                }
            }
        }
    }

    static void rotate(){
        char[][] c = new char[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                c[j][N-i-1] = canvas[i][j];
            }
        }
        canvas = c;
        char[][] m = new char[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                m[j][N-i-1] = my[i][j];
            }
        }
        my = m;
    }

    static boolean equal(){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(canvas[i][j] != my[i][j]) return false;
            }
        }
        return true;
    }
}
