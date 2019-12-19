import java.util.Scanner;
import java.lang.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for(;;) {
            String str;
            String s = "";
            for(;;) {
                str = sc.nextLine();
                if(str.charAt(str.length() - 1) != '.') {
                    s += (str);
                }
                else if (str.charAt(str.length() - 1) == '.'){
                    s += str;
                    break;
                }
            }
            if(s.length() == 1 && s.charAt(0) == '.') return;
            System.out.println(judgeString(s) ? "yes" : "no");

        }
    }
    public static  boolean judgeString(String str) {
        Stack<Character> stack = new Stack<Character>();

        for(int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '(') stack.push('(');
            if(str.charAt(i) == ')') {
                if(stack.isEmpty() || stack.pop() != '(') return false;
            }
            if(str.charAt(i) == '[') stack.push('[');
            if(str.charAt(i) == ']') {
                if(stack.isEmpty() || stack.pop() != '[' ) return false;
            }
        }
        if(!stack.isEmpty()) return false;
        return true;
    }
}
