import java.util.Stack;

public class PostfixEval {
    static int evaluate(String exp) {
        Stack<Integer> st = new Stack<>();
        for (char c : exp.toCharArray()) {
            if (Character.isDigit(c)) {
                st.push(c - '0');         // character '7' -> number 7
            } else {
                int b = st.pop();         // right operand first
                int a = st.pop();
                switch (c) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                }
            }
        }
        return st.pop();
    }

    public static void main(String[] args) {
        System.out.println("Result = " + evaluate("23*54*+9-"));   // 17
    }
}
