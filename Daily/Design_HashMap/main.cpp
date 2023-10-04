#include<bits/stdc++.h>

using namespace std;

class MyHashMap {

    unordered_map<int, int> umap;

public:

    MyHashMap() {}
    
    void put(int key, int value) { umap[key] = value; }
    
    int get(int key) { return (umap.find(key) == umap.end()) ? -1 : umap[key]; }
    
    void remove(int key) { umap.erase(key); }
};

int main() {}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */