 class Node {
    public:
        int key;
        int val;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }
    };
class LRUCache {

private:
//Declaration
    int capacity;

    unordered_map<int, Node*> mpp;

    Node* head;
    Node* tail;


public:

    LRUCache(int capacity) {

        this->capacity = capacity;

        // Dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    // Remove node from linked list
    void deleteNode(Node* node) {

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    // Insert node just after head
    void insert(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }


    int get(int key) {

        // Key doesn't exist
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        // Remove from current position
        deleteNode(node);

        // Move to front = recently used
        insert(node);

        return node->val;
    }


    void put(int key, int value) {

        // Key already exists
        if (mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            // Update value
            node->val = value;

            // Move to front
            deleteNode(node);
            insert(node);

            return;
        }


        // Cache is full
        if (mpp.size() == capacity) {

            // Least recently used node
            Node* lru = tail->prev;

            // Remove from map
            mpp.erase(lru->key);

            // Remove from linked list
            deleteNode(lru);

            // Free memory
            delete lru;
        }


        // Create new node
        Node* newNode = new Node(key, value);

        // Add to map
        mpp[key] = newNode;

        // Insert at front
        insert(newNode);
    }
};