class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        // head
        if (index < 0 || index > size) return;
        Node* newNode = new Node(val);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }else{
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return ;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }else{
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
        size--;
    }
};
