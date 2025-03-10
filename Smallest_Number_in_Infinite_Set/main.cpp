#include<bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
    int cur;
    set<int> heap;
public:
    SmallestInfiniteSet() {
        cur = 0;
    }
    
    int popSmallest() {
        if(!heap.size()) {
            int smallest = *heap.begin();
            heap.erase(heap.begin());
            return smallest;
        }
        cur++;
        return cur - 1;
    }
    
    void addBack(int num) {
        if(num < cur) heap.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {}
