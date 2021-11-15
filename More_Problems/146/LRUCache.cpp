// LRU Cache

#include<bits/stdc++.h>
#include<unordered_map>
#include<queue>

using namespace std;

class LRUCache {
 /* class LRUNode {
        int key, value;
        LRUCache *prev, *next;
        LRUNode(int key, value) {
            this.key = key;
            this.value = value;
            prev = NULL;
            next = NULL;
        }
    }
public:
    LRUNode *head, *tail, *temp;
    LRUCache(int capacity) {
        head = (LRUNode *)malloc(sizeof(LRUNode));
        tail = (LRUNode *)malloc(sizeof(LRUNode));
        for(int i = 1; i < capacity - 1; i++) {
            LRUNode *node = (LRUNode *)malloc(sizeof(LRUNode));
            node->prev = temp;
            temp->next = node;
            temp = temp->next;
        }
        tail->prev = temp;
        temp->next = tail;
        temp = head;
    }
    
    int get(int key) {
        LRUNode *p = head;
        while(p != NULL) {
            if(p.key == key) return p.value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(temp == NULL) {
            head = head->next;
            free(head->prev);
            temp = tail;
            LRUNode *node = (LRUNode *)malloc(sizeof(LRUNode));
            node.key = key;
            node.value = value;
            node->prev = temp;
            temp->next = node;
        }
        temp.key = key;
        temp.value = value;
        temp = temp->next;
    } */
    private:
    unordered_map<int,int> mp;
    queue<int> q;
    unordered_map<int,int> priority;
    int len;
    void addinqueue(int key) {
        q.push(key);
        priority[key]++;
    }
    public:
    LRUCache(int capacity) {
         len=capacity;
    }
    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end()) return -1;
        addinqueue(key);
        return it->second;
    }
    void put(int key, int value) {
         if(mp.size()<len) {
              mp[key]=value;
              addinqueue(key);
              return;
         }
         auto it=mp.find(key);
         if(it!=mp.end()) {
             it->second=value;
             addinqueue(key);
             return;
         }
         while(true) {
             int cur=q.front();
             q.pop();
             priority[cur]--;
             if(priority[cur]==0) {
                 mp.erase(cur);
                 break;
             }
         }
        mp[key]=value;
        addinqueue(key);
    }
};

int main() {}
