import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
//        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            String[] input = br.readLine().split(" ");
            for(int j = 0; j < input.length; j++) {
                System.out.print(reverseString(input[j]) + " ");
            }
            System.out.println();
        }
    }
    public static String reverseString(String str) {
        return (new StringBuffer(str)).reverse().toString();
    }
}
