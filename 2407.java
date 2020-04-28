import java.math.BigInteger;
        import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigInteger[] dp = new BigInteger[101];
        dp[1] = BigInteger.ONE;
        for(int i = 2; i <= 100; i++) {
            dp[i] = dp[i - 1].multiply(BigInteger.valueOf(i));
        }
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        BigInteger son = dp[a].divide(dp[a - b]);
        System.out.println(son.divide(dp[b]));
    }
}
