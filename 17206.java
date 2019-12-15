import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long[] arr = new long[80002]; // 3과 7의 배수를 모두 담는 배열
        int T = sc.nextInt();
        int num;
        long temp = 0;

        for(int i = 1; i < 80001; i++) {
            if(i % 3 == 0) {
                arr[i] = i + temp;
                temp = arr[i];
            } else if(i % 7 == 0) {
                arr[i] = i + temp;
                temp = arr[i];
            } else {
                arr[i] = temp;
            }
        }
        for(int i = 0; i < T; i++) {
            num = sc.nextInt();
            System.out.println(arr[num]);
        }

    }
}
