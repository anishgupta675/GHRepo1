#include<bits/stdc++.h>

using namespace std;

class LRUCache {
    int len;
    queue<int> q;
    unordered_map<int, int> umap;
    unordered_map<int, int> priority;
    void add(int key) {
        q.push(key);
        priority[key]++;
    }
public:
    LRUCache(int capacity) {
        len = capacity;
    }
    
    int get(int key) {
        unordered_map<int, int>::iterator i = umap.find(key);
        if(i == umap.end()) return -1;
        add(key);
        return i->second;
    }
    
    void put(int key, int value) {
        if(umap.size() < len) {
            umap[key] = value;
            add(key);
            return;
        }
        unordered_map<int, int>::iterator i = umap.find(key);
        if(i != umap.end()) {
            i->second = value;
            add(key);
            return;
        }
        while(true) {
            int cur = q.front();
            q.pop();
            priority[cur]--;
            if(!priority[cur]) {
                umap.erase(cur);
                break;
            }
        }
        umap[key] = value;
        add(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main() {}