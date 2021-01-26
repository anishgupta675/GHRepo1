import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;
import java.util.regex.*;
import java.util.concurrent.*;
class Solution {
    public int xorOperation(int n, int start) {
        if(n == 1) return start;
        int res = 0;
        List<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
            list.add(start + (i * 2));
        for(int i = 0; i < list.size(); i++)
            res^= list.get(i);
        return res;
    }
    // Driver Code
    public static void main(String[] args) throws IOException {
	DataInputStream in = new DataInputStream(System.in);
	int n = Integer.parseInt(in.readLine()); int start = Integer.parseInt(in.readLine());
	Solution sol = new Solution();
	System.out.println(sol.xorOperation(n, start));
    }
}