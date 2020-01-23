import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int len = String.valueOf(n).length();
        int ROLE = 9;
        int result = 0;

        for(int i = 1; i < len; i++) {
            result += ROLE * i;
            ROLE *= 10;
        }
        ROLE /= 9;
        result += (n - ROLE + 1) * len;
        System.out.println(result);
    }
}
