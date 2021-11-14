// Longest Palindromic Substring

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public String longestPalindrome(String s) {
    //special cases
    if (s == null || s.length() < 1) {
      return "";
    }
    //record every palindromic string location
    int left = 0, right = 0, length = 0;
    for (int i = 0; i < s.length(); i++) {
      //odd number
      int len1 = findLength(s, i, i);
      //even number
      int len2 = findLength(s, i, i + 1);
      length = Math.max(len1, len2);
      if (length > right - left) {
        //-1 is distinguish between odd and even cases
        left = i - (length - 1) / 2;
        right = i + length / 2;
      }
    }
    return s.substring(left, right + 1);
  }

  private int findLength(String s, int left, int right) {
    while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
      left--;
      right++;
    }
    //if there is only have a character,if do not -1,it will return false
    return right - left - 1;
  }

  public static void main(String[] args) throws IOException {}
}
