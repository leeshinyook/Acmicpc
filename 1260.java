import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] mat = new int[1001][1001];
    static boolean[] visited = new boolean[1001];
    static int M, N, V;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         String[] input = br.readLine().split(" ");
         N = Integer.parseInt(input[0]);
         M = Integer.parseInt(input[1]);
         V = Integer.parseInt(input[2]);
         int X, Y;
         for(int i = 0; i < M; i++) {
            String[] line = br.readLine().split(" ");
            X = Integer.parseInt(line[0]);
            Y = Integer.parseInt(line[1]);
            mat[X][Y] = mat[Y][X] = 1; // 인접행렬 그래프
         }
         DFS(V);
        System.out.println();
        BFS(V);
    }
    public static void DFS(int v) {
        System.out.print(v + " ");
        visited[v] = true;
        for(int i = 1; i <= N; i++) {
            if(visited[i] == false && mat[v][i] == 1) {
                DFS(i);
            }
        }
    }
    public static void BFS(int v) {
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(v);
        visited[v] = false;
        while(!q.isEmpty()) {
            v = q.peek();
            System.out.print(v + " ");
            q.poll();
            for(int i = 1; i <= N; i++) {
                if(visited[i] == true && mat[v][i] == 1) {
                    visited[i] = false;
                    q.offer(i);
                }
            }
        }

    }
}
