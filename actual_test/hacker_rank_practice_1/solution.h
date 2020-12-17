#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <iostream>
using namespace std;
struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : Cache{
public:
    LRUCache(int capacity){
        cp = capacity;
    }
    virtual void set(int, int); //set function
    virtual int get(int); //get function
};

void LRUCache::set(int key, int val){
    // insert the key at the beginning. Then search thru the list. If the value exists, erase it. Else, erase the tail.
    // traverse thru all nodes, find the current node, erase it. Else, if the capacity is reached, erase the tail.
    auto temp = head;
    if(temp == NULL ){cout<<"yayy";}
    while(temp != NULL){
        if(temp -> key == key){
            temp -> prev = temp -> next;
            temp -> next = temp -> prev;
            break;
        }
    }
    if(temp == NULL){
        temp = tail;
        tail = tail -> prev;
    }
    if ( mp.size() == cp){
        delete temp;
    }
    else{
        ++cp;
    }

    // insert the key at the beginning.
    head -> prev = new Node(NULL, head, key, val);
    head = head -> prev;
    mp[key] = head;
}

int LRUCache::get(int key){
    if (mp.find(key) != mp.end()){return mp[key]-> value; }
    else{return -1; }
}