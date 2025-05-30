class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
       unordered_map<string,int> hm; 
       
       for(string s:words){ // match to make pairs that can be taken in palindrome
           string p = s;
           reverse(p.begin(),p.end());
           if(hm[p]>0){ // reverse of current string found, these 2 strings can be added to palindrome 
               res+= 4;
               hm[p]--;  // remove occurence of string as we used it for palindrome
           }
           else{
               hm[s]++;   // reverse not fount , put it in hashmap
           }
       }
         //***** to take element at the center with both letters same
       for(auto i:hm){   // only strings with frequency 1 are left now  
           if(i.first[0]==i.first[1] && i.second>0){ // to place in center of palindrome we needs chars to be same
               return res+2;   
           }
       }

       return res;
    }
};