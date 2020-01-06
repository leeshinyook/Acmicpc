import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] mat;
    static int[][] check;
    static int M, N;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        sc.nextLine();
        mat = new int[M + 1][N + 1];
        check = new int[M + 1][N + 1];

        for (int i = 0; i < M; i++) {
            String[] num = sc.nextLine().split("");
            for(int j = 0; j < N; j++) {
                mat[i][j] = Integer.parseInt(num[j]);
                check[i][j] = 0;
            }
        }
        check[0][0] = 1;
        BFS(0,0);
        System.out.println(mat[M - 1][N - 1]);
    }
    private static void BFS(int x, int y) {
        Queue<Point> q = new LinkedList<Point>();
        q.add(new Point(x,y));
        while(!q.isEmpty()) {
            Point d = q.poll();
            for(int i = 0; i < 4; i++) {
                // 다음에 방문 좌표
                int nextX = d.x + dx[i];
                int nextY = d.y + dy[i];

                // 다음 좌표가 범위이탈시 건너뜀
                if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N ) {
                    continue;
                }

                // 이미 방문했던 좌표도 건너뛰어
                if(check[nextX][nextY] == 1 || mat[nextX][nextY] == 0) {
                    continue;
                }

                // 다음에 방문할 좌표를 큐에 추가
                q.add(new Point(nextX, nextY));

                // 다음에 방문할 곳은 방문했던 점보다 +1;
                mat[nextX][nextY] = mat[d.x][d.y] + 1;
                // 다음좌표 방문체크
                check[nextX][nextY] = 1;
            }
        }

    }
}
