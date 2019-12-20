import java.util.Hashtable;
import java.util.Scanner;
import java.lang.*;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        String part, nonPart;

        HashMap<String, Integer> participant = new HashMap<String, Integer>(T);

        for(int i = 0; i < T; i++) {// 입력
            part = sc.nextLine();
            if(participant.containsKey(part)) {
                Integer value = participant.get(part);
                participant.put(part, ++value);
            } else {
                participant.put(part, 0);
            }
        }
        for(int i = 0; i < T - 1; i++) {
            nonPart = sc.nextLine();
            if(participant.containsKey(nonPart)) {
                Integer value = participant.get(nonPart);
                participant.put(nonPart, ++value);
            }
        }
        participant.forEach((key, v) -> {
            if(v % 2 == 0) System.out.print(key);
        });


    }
}
