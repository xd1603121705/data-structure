#include "LRUcache.h"

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    head = nullptr;
}

// move node to head
void LRUCache::moveToHead(CacheNode* node) {
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
void LRUCache::deleteLastNode() {
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

int LRUCache::get(int key) {
    auto it = nodes.find(key);
    if (it != nodes.end()) {
        CacheNode* curr = it->second;
        moveToHead(curr);
        return head->value;
    }
    else
        return -1;
}

void LRUCache::put(int key, int value) {
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
        nodes.insert(std::make_pair(key, node)); // update nodes
    }
    else if (nodes[key]->value != value) {  // update value
        nodes[key]->value = value;
    }
}