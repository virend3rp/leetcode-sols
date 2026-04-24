// Last updated: 4/24/2026, 10:11:34 PM
struct MyListNode {
    int val;
    MyListNode *next;
    MyListNode() : val(0), next(nullptr) {}
    MyListNode(int x) : val(x), next(nullptr) {}
    MyListNode(int x, MyListNode *next) : val(x), next(next) {}
};

class MyHashSet {
public:
    MyListNode* head;
    
    MyHashSet() {
        head = new MyListNode(-1);
    }
    
    void add(int key) {
        if (!contains(key)) {
            MyListNode* newNode = new MyListNode(key);
            newNode->next = head->next;
            head->next = newNode;
        }
    }
    
    void remove(int key) {
        MyListNode* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->val == key) {
                MyListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }
    }
    
    bool contains(int key) {
        MyListNode* temp = head->next;
        while (temp != nullptr) {
            if (temp->val == key) return true;
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */