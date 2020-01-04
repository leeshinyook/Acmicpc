import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] mat;
    static int[] check;
    static int count = 0, T;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        int N = sc.nextInt();
        mat = new int[T + 1][T + 1];
        check = new int[T + 1];
        for(int i = 0; i < N; i++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            mat[X][Y] = mat[Y][X] = 1;
        }
        DFS(1);
        System.out.println(count);
    }
    private static void DFS(int v) {
        check[v] = 1;
        for(int i = 0; i <= T; i++) {
            if(check[i] != 1 && mat[v][i] == 1) {
                DFS(i);
                count++;
            }
        }
    }
}