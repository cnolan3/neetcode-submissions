struct ListNode {
    ListNode* next;
    int val;
};

class MyLinkedList {
private:
    ListNode* head;
    ListNode* tail;
    int len;

public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= len) return -1;
        ListNode* p = head;
        int i = 0;
        while (p) {
            if (i == index) return p->val;
            p = p->next;
            i++;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        if (!head) {
            head = new ListNode;
            head->val = val;
            tail = head;
        } else {
            ListNode* tmp = new ListNode;
            tmp->val = val;
            tmp->next = head;
            head = tmp;
        }

        len++;
    }
    
    void addAtTail(int val) {
        if (!tail) {
            head = new ListNode;
            head->val = val;
            tail = head;
        } else {
            ListNode* tmp = new ListNode;
            tmp->val = val;
            tail->next = tmp;
            tail = tmp;
        }

        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == len) return this->addAtTail(val);
        if (index == 0) return this->addAtHead(val);

        ListNode* p = head;
        int i = 0;

        while (p) {
            if (i == index - 1) {
                ListNode* n = new ListNode;
                n->val = val;
                n->next = p->next;
                p->next = n;

                len++;

                return;
            }

            p = p->next;
            i++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;

        ListNode* dummy = new ListNode;
        ListNode* p = dummy;
        int i = -1;

        dummy->next = head;

        while (p) {
            if (i == index - 1) {
                if (p->next == head) {
                    head = p->next->next;
                }

                if (p->next == tail) {
                    tail = p;
                }

                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
                len--;

                break;
            }

            p = p->next;
            i++;
        }

        if (!head) {
            tail = nullptr;
        }

        delete dummy;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */