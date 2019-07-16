#include <iostream>

using namespace std;

class Stack {
    private:
        int size;
        int *arr;
        int tip;
    public:
        Stack(int size);
        ~Stack();
        void add(int val);
        int pop();
};

Stack::Stack(int size) {
    this->size = size;
    this->arr = new int[size];
    this->tip = -1;
}

Stack::~Stack() {
    delete[] this->arr;
}

void Stack::add(int value) {
    this->tip++;
    *(this->arr + this->tip) = value;
}

int Stack::pop() {
    int v = *(this->arr + this->tip);
    this->tip--;
    return v;
}

int main() {
    Stack s(10);
    s.add(1);
    s.add(2);
    s.add(3);
    s.add(4);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    s.add(5);

    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
