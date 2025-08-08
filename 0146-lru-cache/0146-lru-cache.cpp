class LRUCache {
private:
    struct Node{
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k) , value(v), prev(nullptr) , next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* node){
        // add right after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node){
        removeNode(node);
        addNode(node);
    }

    Node* popTail(){
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
public:
    
    LRUCache(int cap){
        this->capacity = cap;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);

        }
        else{
            Node* node = new Node(key, value);
            mp[key] = node;
            addNode(node);

            if(mp.size() > capacity){
                Node* tail = popTail(); // remove the least recent
                mp.erase(tail->key);
                delete tail;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */