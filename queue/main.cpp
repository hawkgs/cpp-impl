#include <iostream>

using namespace std;

struct Element {
    public:
        int val;
        Element *next;
        Element(int val);
};

Element::Element(int val) {
    this->val = val;
    this->next = NULL;
}

class Queue {
    private:
        Element *root;
        Element *last;
    public:
        Queue();
        ~Queue();
        void que(int val);
        int deque();
};

Queue::Queue() {
    this->root = NULL;
    this->last = NULL;
}

Queue::~Queue() {
    Element *curr = this->root;
    Element *next;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void Queue::que(int val) {
    Element *newVal = new Element(val);
    if (!this->root) {
        this->root = newVal;
    } else {
        this->last->next = newVal;
    }
    this->last = newVal;
}

int Queue::deque() {
    int val = this->root->val;
    Element *newRoot = this->root->next;
    delete this->root;
    this->root = newRoot;

    return val;
}

int main() {
    Queue q;

    q.que(1);
    q.que(2);
    q.que(3);
    q.que(4);
    q.que(5);

    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    q.que(6);

    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;

    return 0;
}
