// Roman to Integer

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int romanToInt(String s) {
        int res = 0, n = s.length();
        HashMap<Character, Integer> roman = new HashMap<Character, Integer>(7);
        roman.put('I', 1); roman.put('V', 5); roman.put('X', 10); roman.put('L', 50); roman.put('C', 100); roman.put('D', 500); roman.put('M', 1000);
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && roman.get(s.charAt(i + 1)) > roman.get(s.charAt(i))) res-= roman.get(s.charAt(i));
            else res+= roman.get(s.charAt(i));
        }
        return res;
    }
    public static void main(String[] args) throws IOException {}
}
