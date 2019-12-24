import java.util.Scanner;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int p[] = new int[n+1];
        int dp[] = new int[n+1];

        for(int i=1; i<=n; i++){
            p[i] = sc.nextInt();
        }
        //점화식에서 i-3까지 가기때문에 1,2는 편의상 초기화 해준다.
        dp[1] = p[1];
        if(n > 1) // 1인 경우 터지기 때문에 예외처리
            dp[2] = p[1] + p[2];
        for(int i=3; i<=n; i++){
            dp[i] = Math.max(dp[i-1],Math.max(dp[i-2]+p[i],dp[i-3]+p[i-1]+p[i]));

        }

        System.out.println(dp[n]);



    }

}