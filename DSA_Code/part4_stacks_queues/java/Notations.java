import java.util.Stack;

public class Notations {
    static int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;                         // '(' has the lowest priority
    }

    // strict = false -> postfix rule (pop when >=), strict = true -> used for prefix (pop when >)
    static String toPostfix(String infix, boolean strict) {
        StringBuilder out = new StringBuilder();
        Stack<Character> st = new Stack<>();
        for (char c : infix.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                out.append(c);
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.isEmpty() && st.peek() != '(') out.append(st.pop());
                st.pop();                 // discard '('
            } else {
                while (!st.isEmpty() && (strict ? prec(st.peek()) > prec(c)
                                                : prec(st.peek()) >= prec(c)))
                    out.append(st.pop());
                st.push(c);
            }
        }
        while (!st.isEmpty()) out.append(st.pop());
        return out.toString();
    }

    static String toPrefix(String infix) {
        StringBuilder rev = new StringBuilder(infix).reverse();
        for (int i = 0; i < rev.length(); i++) {          // swap the brackets
            if (rev.charAt(i) == '(') rev.setCharAt(i, ')');
            else if (rev.charAt(i) == ')') rev.setCharAt(i, '(');
        }
        return new StringBuilder(toPostfix(rev.toString(), true)).reverse().toString();
    }

    public static void main(String[] args) {
        String infix = "(A+B)*C";
        System.out.println("Infix  : " + infix);
        System.out.println("Postfix: " + toPostfix(infix, false));   // AB+C*
        System.out.println("Prefix : " + toPrefix(infix));            // *+ABC
    }
}
