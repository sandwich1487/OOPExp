#ifndef STACK_H
#define STACK_H

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack
{
private:
    Node* top_;
    int size_;

public:
    Stack(): top_(nullptr), size_(0) {}
    ~Stack();
    
    void push(int);
    int pop();
    void empty();
    int top() const;
    
    int size() const { return size_; }
};

#endif // STACK_H