import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int top_ring = sc.nextInt();
        int ring;

        for(int i = 0; i < T - 1; i++) {
            ring = sc.nextInt();
            if(top_ring % ring == 0) {
                System.out.println(top_ring / ring + "/" + 1);
            } else {
                int cd = gcd(top_ring, ring);
                System.out.println(top_ring / cd + "/" + ring / cd );
            }
        }

    }

    private static int gcd(int a, int b) {
        while(b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return Math.abs(a);
    }
}
