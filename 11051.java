
import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.ArrayList;
        import java.util.Arrays;
        import java.util.Collections;
        import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[][] binoCoef = new long[1002][1002];
        for(int i = 0; i < 1002; i++) {
            binoCoef[i][0] = 1;
            binoCoef[i][i] = 1;
        }
        for(int i = 1; i < 1001; i++) {
            for(int j = 1; j <= i; j++) {
                binoCoef[i][j] = (binoCoef[i - 1][j] + binoCoef[i - 1][j - 1]) % 10007;
            }
        }
        System.out.println(binoCoef[n][k]);
    }
}
