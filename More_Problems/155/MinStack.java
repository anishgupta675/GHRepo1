// Min Stack

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class MinStack {

    /** initialize your data structure here. */
    Stack<Integer> stack = new Stack<Integer>();
    Stack<Integer> min_val = new Stack<Integer>();
    
    public void push(int val) {
        if(stack.isEmpty() || val <= min_val.peek()) min_val.push(val);
        stack.push(val);
    }
    
    public void pop() {
        if(stack.peek().equals(min_val.peek())) min_val.pop();
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return min_val.peek();
    }

    public static void main(String[] args) throws IOException {}
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
