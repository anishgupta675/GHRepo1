import java.util.*;

class Solution {
    public int countSeniors(String[] details) {
        int count = 0;
        for(String i : details) if(Integer.parseInt(i.substring(11, 13)) > Integer.valueOf(60)) count++;
        return count;
    }
    public static void main(String[] args) throws Exception {}
}