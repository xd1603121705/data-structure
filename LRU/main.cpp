#include <iostream>
#include "LRUcache.h"

int main()
{
    LRUCache *cache = new LRUCache( 2 /* capacity */ );

    cache->put(2, 1);
    cache->put(2, 2);
    std::cout << cache->get(2) << std::endl;       // returns 1
    cache->put(1, 1);    // evicts key 2
    //cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 1);    // evicts key 1
    //cout << cache->get(1) << endl;       // returns -1 (not found)
    //cout << cache->get(3) << endl;       // returns 3
    std::cout << cache->get(2) << std::endl;       // returns 4
    return 0;
}
/* leetcode 146:LRU cache Acceped code
#include <iostream>
#include <unordered_map>

using namespace std;

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

        LRUCache(int capacity) {
            cap = capacity;
            head = nullptr;
        }

        // move node to head
        void moveToHead(CacheNode* node) {
            if (node->prev == nullptr)
                return;
            else
                node->prev->next = node->next;
            if (node->next != nullptr) {
                node->next->prev = node->prev;
            }
            node->prev = nullptr;
            node->next = head;
            head->prev = node;
            head = node;
        }

        // delete last node
        void deleteLastNode() {
            CacheNode* node = head;
            while (node->next != nullptr) // locate last node
                node = node->next;
            nodes.erase(node->key);       // update nodes
            if (node == head)  // only one node
                head = nullptr;
            else {
                node->prev->next = nullptr;
                delete node;
                node = nullptr;
            }
        }

        int get(int key) {
            auto it = nodes.find(key);
            if (it != nodes.end()) {
                CacheNode* curr = it->second;
                moveToHead(curr);
                return head->value;
            }
            else
                return -1;
        }

        void put(int key, int value) {
            CacheNode* node = new CacheNode(key, value);
            if (get(key) == -1) {
                if (nodes.size() == 0)
                    head = node;
                else {
                    if (nodes.size() >= cap)
                        deleteLastNode();
                    if (head == nullptr)
                        head = node;
                    else {
                        head->prev = node;
                        node->next = head;
                        head = node;
                    }
                }
                nodes.insert(make_pair(key, node)); // update nodes
            }
            else if (nodes[key]->value != value) {  // update value
                nodes[key]->value = value;
            }

        }
        
    private:
        int cap;
        CacheNode* head;
        std::unordered_map<int, CacheNode*> nodes; // mem node 
};

int main()
{
    LRUCache *cache = new LRUCache( 2 );

    cache->put(2, 1);
    cache->put(2, 2);
    cout << cache->get(2) << endl;       // returns 1
    cache->put(1, 1);    // evicts key 2
    //cout << cache->get(2) << endl;       // returns -1 (not found)
    cache->put(4, 1);    // evicts key 1
    //cout << cache->get(1) << endl;       // returns -1 (not found)
    //cout << cache->get(3) << endl;       // returns 3
    cout << cache->get(2) << endl;       // returns 4
    return 0;
}
*/