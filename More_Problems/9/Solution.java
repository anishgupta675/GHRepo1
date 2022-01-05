// Palindrome Number

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        String num = Integer.toString(x);
        StringBuilder rev = new StringBuilder(num).reverse();
        if(rev.toString().equals(num)) return true;
        return false;
    }
    public static void main(String[] args) throws IOException {}
}
