import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N = sc.nextInt();
        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= T; i++) {
            q.add(i);
        }
        System.out.print("<");
        while(q.size() > 0) {
            if(q.size() == 1) {
                System.out.print(q.peek() + ">");
                q.poll();
                break;
            }
            for(int i = 1; i < N; i++) {
                q.add(q.peek());
                q.poll();
            }
            System.out.print(q.peek() + ", ");
            q.poll();
        }

    }
}
