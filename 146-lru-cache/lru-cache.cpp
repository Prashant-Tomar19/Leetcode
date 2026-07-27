class LRUCache {
private:
    class ListNode {
    public:
        int key;
        int value;
        ListNode *prev;
        ListNode *next;

        ListNode(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

public:
    int capacity;
    unordered_map<int, ListNode*> mp;
    ListNode *head;
    ListNode *current;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        current = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        ListNode *node = mp[key];

        // Already most recently used
        if (node == current)
            return node->value;

        // Remove node from its current position
        if (node == head) {
            head = head->next;
            if (head)
                head->prev = nullptr;
        } else {
            node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
        }

        // Move node to end
        current->next = node;
        node->prev = current;
        node->next = nullptr;
        current = node;

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            get(key);          // Move to most recently used
            return;
        }

        // Cache full
        if (mp.size() == capacity) {

            mp.erase(head->key);

            ListNode *temp = head;
            head = head->next;

            if (head)
                head->prev = nullptr;
            else
                current = nullptr;

            delete temp;
        }

        // Insert new node
        ListNode *node = new ListNode(key, value);

        if (head == nullptr) {
            head = node;
            current = node;
        } else {
            current->next = node;
            node->prev = current;
            current = node;
        }

        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */