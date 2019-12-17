import java.util.Scanner;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int seqCount = 0;
        int titleCount = 0;
        int T = sc.nextInt();

        for(int i = 666; ; i++) {
            String title = Integer.toString(i);
            for(int j = title.length() - 1; j >= 0; j--) {
                if(title.charAt(j) == '6') {
                    seqCount++;
                } else if(seqCount > 2){
                    break;
                } else {
                    seqCount = 0;
                }
            }
            if(seqCount >= 3) {
                titleCount++;
            }
            seqCount = 0;
            if(titleCount == T) {
                System.out.print(i);
                break;
            }
        }
    }
}
