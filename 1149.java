//import java.util.Scanner;
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        int[][] dp = new int[T + 1][3];
        for(int i = 1; i <= T; i++) {
            dp[i][0] = sc.nextInt(); // RED;
            dp[i][1] = sc.nextInt(); // GREEN;
            dp[i][2] = sc.nextInt(); // BLUE;
        }
        for(int i = 2; i <= T; i++) {
            dp[i][0] += Math.min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] += Math.min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] += Math.min(dp[i - 1][1], dp[i - 1][0]);
        }

        System.out.println(Math.min(dp[T][0], Math.min(dp[T][1], dp[T][2])));
    }
}
