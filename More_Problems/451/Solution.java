// Sort Characters By Frequency

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

class Solution {
    class CharacterFreq{
        char c;
        int freq;
        CharacterFreq(char c,int freq){
            this.c=c;
            this.freq=freq;
        }
        public char getChar(){
            return c;
        }
        public int getFreq(){
            return freq;
        }
    }
    
    class CharacterComparator implements Comparator<CharacterFreq>{
        public int compare(CharacterFreq ob1, CharacterFreq ob2){
            if(ob1.getFreq()<ob2.getFreq())
                return 1;
            else if(ob1.getFreq()>ob2.getFreq())
                return -1;
            else{
                // if(ob1.getChar() < ob2getChar())
                //     return -1;
                // return 1;
                return 0;
            }
        }
    }
    public String frequencySort(String s) {
        PriorityQueue<CharacterFreq> pq = new PriorityQueue<CharacterFreq>(new CharacterComparator());
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0;i< s.length();i++){
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
         for(Map.Entry<Character,Integer>e:map.entrySet()){
            CharacterFreq charFreq = new CharacterFreq(e.getKey(), e.getValue());
             pq.add(charFreq);
        }
        StringBuilder sb = new StringBuilder();
        while(pq.peek()!=null){
            char c = pq.poll().getChar();
            int count = map.get(c);
            while(count>0){
                sb.append(c);
                count--;
            }
        }
        return sb.toString();
    }
    public static void main(String[] args) throws IOException {}
}
