import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = 0;
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int K = Integer.parseInt(input[2]);

        while(K > 0) {
            if(N / M < 2) {
                M--;
                K--;
            } else if(N / M > 2) {
                N--;
                K--;
            } else {
                N--;
                K--;
            }
        }
        if(N == 0 || M == 0) {
            System.out.println(0);
        } else {
            while(true) {
                if(M <= 0 || N <= 1) break;
                N -= 2;
                M -= 1;
                count++;
            }
        }
        System.out.println(count);

    }
}
