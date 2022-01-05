// Valid Parentheses

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        int i = 0;
        while (i < s.length()) {
            char ch = s.charAt(i);
            if (ch == '{' || ch == '(' || ch == '[' ) {
                stack.push(ch);
                i++;
            }
            else {
                if (!stack.isEmpty() && ch == closing(stack.pop()))  i++;
                else return false;
            }
        }
        return stack.isEmpty();
    }
    
    public char closing(char ch) {
        if (ch == '(') return ')';
        if (ch == '[') return ']';
        if (ch == '{') return '}';
        return 'a';
    }

    public static void main(String[] args) throws IOException {}
}
