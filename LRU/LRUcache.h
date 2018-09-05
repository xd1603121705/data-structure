/*
 *      Author:Lijunjun(junlee_happy@163.com)
 *    Datetime:2018/09/05-18:00
 * Description: LRUcache C++ implenment
 * 
 * */
#ifndef LRU_LRUCACHE_H
#define LRU_LRUCACHE_H


#include <unordered_map>

struct CacheNode
{
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;
    CacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
    public:
        
        LRUCache(int capacity);

        // move node to head
        void moveToHead(CacheNode* node);

        // delete last node
        void deleteLastNode();

        // get the value of key, return -1 if not find
        int get(int key);

        // put(key, value), if find key update value
        void put(int key, int value);

    private:
        int cap;
        CacheNode* head;
        std::unordered_map<int, CacheNode*> nodes; // mem node
};

#endif