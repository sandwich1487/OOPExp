#include "Stack.h"
#include <iostream>

using namespace std;

Stack::~Stack()
{
    empty();
}


void Stack::push(int val)
{
    size_++;
    Node* node = new Node(val);
    node->next = top_;
    top_ = node;
}

int Stack::pop()
{
    int val = 0;
    if (size_ > 0)
    {
        size_--;
        Node* target = top_;
        val = target->data;
        top_ = top_->next;
        delete target;
    }
    else
    {
        throw out_of_range("The stack is empty.");
    }
    return val;
}

void Stack::empty()
{
    size_ = 0;
    while (top_ != nullptr)
    {
        Node* target = top_;
        top_ = top_->next;
        delete target;
    }
}

int Stack::top() const
{
    if (top_ != nullptr)
    {
        return top_->data;
    }
    else
    {
        throw out_of_range("The stack is empty.");
    }
}