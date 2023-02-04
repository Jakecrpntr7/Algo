//
// Created by Jacob Carpenter on 2/4/23.
//

#ifndef ALGO_LISTNODE_H
#define ALGO_LISTNODE_H

#include <memory>

template <typename T>
class ListNode {
public:

    ListNode(T val)
    {
        value = val;
        previous = nullptr;
        next = nullptr;
    }

    T getValue() {return this->value;}
    void setPrevious(ListNode<T> node)
    {
        previous = std::make_shared<ListNode<T>>(node);
    }
    void setPrevious(const std::shared_ptr<ListNode<T>>& node)
    {
        previous = node;
    }
    void setNext(ListNode<T> node)
    {
        next = std::make_shared<ListNode<T>>(node);
    }
    void setNext(std::shared_ptr<ListNode<T>> node)
    {
        next = node;
    }
    std::shared_ptr<ListNode<T>> getPrevious() {return this->previous;}
    std::shared_ptr<ListNode<T>> getNext() {return this->next;}

private:

    T value;
    std::shared_ptr<ListNode<T>> previous;
    std::shared_ptr<ListNode<T>> next;

};


#endif //ALGO_LISTNODE_H
