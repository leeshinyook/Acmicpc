import java.util.Scanner;
import java.text.DecimalFormat;
public class Main {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("0.0000000");
        Scanner sc = new Scanner(System.in);


        int radius = sc.nextInt();
        double pi = Math.PI;

        System.out.println(df.format(radius * radius * pi));
        System.out.println(df.format(radius * radius * 2));

    }
}
