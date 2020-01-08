import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, String> list = new HashMap<String, String>();
        String[] input = br.readLine().split(" ");
        int M = Integer.parseInt(input[0]);
        int N = Integer.parseInt(input[1]);

        for(int i = 1; i <= M; i++) {
            String name = br.readLine();
            String number = Integer.toString(i);
            list.put(name, number);
            list.put(number, name);
        }
        for(int i = 0; i < N; i++) {
            String name = br.readLine();
            System.out.println(list.get(name));
        }
    }

}