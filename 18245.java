import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.*;
        import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int index = 2;
        while(true) {
            String str = br.readLine();
            if(str.equals("Was it a cat I saw?")) break;
            for(int i = 0; i < str.length(); i += index) {
                System.out.print(str.charAt(i));
            }
            System.out.println();
            index++;
        }
    }
}
