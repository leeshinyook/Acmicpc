import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[][] dp = new int[31][31];

        for(int i = 1; i < 31; i++) {
            dp[1][i] = i;
        }
        for(int i = 2; i < 31; i++) {
            for(int j = i; j < 31; j++) {
                for(int k = j; k >= i ; k--) {
                    dp[i][j] += dp[i -1][k -1];
                }
            }
        }
        for(int i = 0; i < T; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            System.out.println(dp[x][y]);
        }
    }
}
