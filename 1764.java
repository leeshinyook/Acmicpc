import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();
        String name;
        ArrayList<String> duplicate = new ArrayList<String>(N+M);
        HashMap<String, Integer> map = new HashMap<String, Integer>(M + N);
        for(int i = 0; i < M + N; i++) {
            name = sc.nextLine();
            if(map.containsKey(name)) {
                duplicate.add(name);
            }
            map.put(name, 0);
        }
        System.out.println(duplicate.size());
        Collections.sort(duplicate);
        for(int i = 0; i < duplicate.size(); i++) {
            System.out.println(duplicate.get(i));
        }
//        Set<String, Integer> set = map.keySet();



    }

}