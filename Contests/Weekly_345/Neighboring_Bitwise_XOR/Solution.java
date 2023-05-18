import java.util.*;

class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int count = 0;
        for(int i : derived) if(i == 1) count++;
        return count % 2 == 0;
    }
    public static void main(String[] args) throws Exception {}
}