import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] mat;
    static int[][] check;
    static int W, H;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
            int T = sc.nextInt();
            while(T-- > 0) {
                H = sc.nextInt();
                W = sc.nextInt();
                int input = sc.nextInt();
                mat = new int[H][W];
                check = new int[H][W];
                int count = 0;
                for (int i = 0; i < input; i++) {
                    int X = sc.nextInt();
                    int Y = sc.nextInt();
                    mat[X][Y] = 1;
                }
                for (int i = 0; i < H; i++) {
                    for (int j = 0; j < W; j++) {
                        if (mat[i][j] == 1 && check[i][j] == 0) {
                            DFS(i, j, ++count, W, H);
                        }
                    }
                }
                System.out.println(count);
            }
    }
    private static void DFS(int x, int y, int count, int w, int h) {
        check[x][y] = count;

        for (int i = 0; i < dx.length; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                if (mat[nx][ny] == 1 && check[nx][ny] == 0)
                    DFS(nx, ny, count, w, h);
            }
        }
    }
}