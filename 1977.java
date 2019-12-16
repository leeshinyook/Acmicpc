import java.util.Scanner;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int M = sc.nextInt();
        int N = sc.nextInt();
        int sum = 0, min = 10000;

        for(int i = 0;;i++) {
            if(Math.pow(i, 2) >= M  && Math.pow(i, 2) <= N) {
                if(min > i * i) {
                    min = i * i;
                }
                sum += Math.pow(i, 2);
            }
            if(Math.pow(i, 2) > N) {
                break;
            }
        }
        if(sum == 0) {
            System.out.println(-1);
            return;
        }
        System.out.println(sum);
        System.out.println(min);
    }
}
