import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int money = sc.nextInt();
        int count = 0;

        int[] standard = new int[T];

        for(int i = T - 1; i >= 0; i--) {
            standard[i] = sc.nextInt();
        }

        for(int i = 0; i < T; i++) {
            if(money == 0) break;
            if(money / standard[i] != 0); {
                count += money / standard[i];
                money -= (money / standard[i]) * standard[i];
            }
        }
        System.out.println(count);
    }
}
