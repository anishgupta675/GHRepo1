// Insert Delete GetRandom O(1)

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class RandomizedSet {

    private final Map<Integer, Integer> indexByNum = new HashMap<>();
    private final List<Integer> list = new ArrayList<>();
    private final Random randomGenerator = new Random();
    public RandomizedSet() {
        
    }
    
    public boolean insert(int val) {
        if(indexByNum.containsKey(val)) return false;
        list.add(val);
        indexByNum.put(val, list.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!indexByNum.containsKey(val)) return false;
        var index = indexByNum.get(val);
        var tail = list.get(list.size() - 1);
        list.set(list.size() - 1, val);
        list.set(index, tail);
        indexByNum.put(tail, index);
        list.remove(list.size() - 1);
        indexByNum.remove(val);
        return true;
    }
    
    public int getRandom() {
        return list.get(randomGenerator.nextInt(list.size()));
    }

    public static void main(String[] args) throws IOException {}
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
