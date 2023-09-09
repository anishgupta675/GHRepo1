import java.util.*;

class Solution {
    
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res.add(new ArrayList<Integer>());
        res.get(0).add(1);
        for(int i = 1; i < numRows; i++) {
            res.add(new ArrayList<Integer>());
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) res.get(i).add(1);
                else res.get(i).add(res.get(i - 1).get(j - 1) + res.get(i - 1).get(j));
            }
        }
        return res;
    }

    public static void main(String[] args) throws Exception {}
}