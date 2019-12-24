import java.lang.Math;
import java.lang.reflect.Array;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int[] A = {1, 2, 4};
        int T = sc.nextInt();
        int[] countingNum = new int[11];
        countingNum[0] = 1;
        countingNum[1] = 2;
        countingNum[2] = 4;

        for(int i = 3; i < 11; i++) {
            countingNum[i] = countingNum[i - 1] + countingNum[i - 2] + countingNum[i - 3];
        }

        for(int i = 0; i < T; i++) {
            int num = sc.nextInt();
            System.out.println(countingNum[num - 1]);
        }

    }
}
