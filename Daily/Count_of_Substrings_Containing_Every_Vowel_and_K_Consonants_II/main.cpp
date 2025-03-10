#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    long countOfSubstrings(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0, end = 0, consonantCount = 0;
        unordered_map<char, int> vowelCount;
        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        for(int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if(!isVowel(word[i])) nextConsonantIndex = i;
        }
        while(end < word.size()) {
            char newLetter = word[end];
            if(isVowel(newLetter)) vowelCount[newLetter]++;
            else consonantCount++;
            while(consonantCount > k) {
                char startLetter = word[start];
                if(isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if(vowelCount[startLetter] == 0) vowelCount.erase(startLetter);
                } else consonantCount--;
                start++;
            }
            while(start < word.size() && vowelCount.size() == 5 &&
                   consonantCount == k) {
                numValidSubstrings += nextConsonant[end] - end;
                char startLetter = word[start];
                if(isVowel(startLetter)) {
                    vowelCount[startLetter]--;
                    if(vowelCount[startLetter] == 0) vowelCount.erase(startLetter);
                } else consonantCount--;
                start++;
            }
            end++;
        }
        return numValidSubstrings;
    }
};

int main() {}
