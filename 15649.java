import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;
// 수 찾기

public class Main {
    static boolean[] visited = new boolean[9];
    static int M, N;
    static int[] arr = new int[9];

    public static void main(String[] args) {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        BackTracking(0);
    }
    public static void BackTracking(int cnt) {
        if(cnt == M) {
            for(int i = 0; i < M; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[cnt] = i;
                BackTracking(cnt + 1);
                visited[i] = false;
            }
        }
    }

}