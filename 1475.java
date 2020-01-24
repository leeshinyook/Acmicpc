import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static HashMap<String, Integer> map = new HashMap<>();
    private static int except_count = 0;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split("");

        int max = 0;
        for(String e : str) {
            if(map.containsKey(e)) {
                int v = map.get(e);
                map.put(e, ++v);
            } else {
                map.put(e, 1);
            }
            if(e.equals("9") || e.equals("6")) {
                except_count++;
            }
        }

        if(except_count % 2 > 0) {
            except_count = except_count / 2 + 1;
        } else {
            except_count /= 2;
        }

        max = except_count;
        map.remove("9");
        map.remove("6");
        for(Integer v : map.values()) {
            if(max < v) {
                max = v;
            }
        }
        System.out.println(max);
    }

}
