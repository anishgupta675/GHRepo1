import java.util.*;

class Solution {
    public int[] circularGameLosers(int n, int k) {
        int ball = 0, index = 1;
        List<Integer> res = new ArrayList<Integer>();
        HashSet<Integer> hset = new HashSet<Integer>();
        while(true) {
            if(hset.contains(ball)) break;
            hset.add(ball);
            ball = (ball + (index * k)) % n;
            index++;
        }
        for(int i = 0; i < n; i++) if(!hset.contains(i)) res.add(i + 1);
        return res.stream().mapToInt(i -> i).toArray();
    }
    public static void main(String[] args) throws Exception {}
}