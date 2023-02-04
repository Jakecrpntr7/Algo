//
// Created by Jacob Carpenter on 2/4/23.
//

#ifndef ALGO_DOUBLYLINKEDLIST_H
#define ALGO_DOUBLYLINKEDLIST_H

#include "ListNode.h"
#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class DoublyLinkedList {

    int size;
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

public:

    DoublyLinkedList();

    T get(int index);
    std::vector<T> toVector();
    void insertHead(T value);
    void insertTail(T value);
    void insert(int index, T value);

    int find(T value);

    void removeHead();
    void removeTail();
    void remove(int index);

    void print();

    int getSize() {return size;}
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

template <typename T>
T DoublyLinkedList<T>::get(int index)
{
    if (index < 0 || index > size)
    {
        return NULL;
    }
    std::shared_ptr<ListNode<T>> current = head;
    for (int i = 0; i < index; ++i)
    {
        current = current->getNext();
    }
    return current->getValue();
}

template <typename T>
std::vector<T> DoublyLinkedList<T>::toVector()
{
    std::shared_ptr<ListNode<T>> node = head;
    std::vector<T> result{};
    while (node != nullptr)
    {
        result.push_back(node->getValue());
        node = node->getNext();
    }
    return result;
}

template <typename T>
void DoublyLinkedList<T>::insertHead(T value)
{
    std::shared_ptr<ListNode<T>> node{std::make_shared<ListNode<T>>(value)};
    node->setNext(head);
    if (head != nullptr)
    {
        head->setPrevious(node);
    }
    head = node;
    if (size == 0)
    {
        tail = head;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insertTail(T value)
{
    if (size == 0)
    {
        return insertHead(value);
    }
    std::shared_ptr<ListNode<T>> node{std::make_shared<ListNode<T>>(value)};
    tail->setNext(node);
    node->setPrevious(tail);
    tail = node;
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T value)
{
    if(index < 0 || index > size)
    {
        return;
    }
    if (index == 0)
    {
        return insertHead(value);
    }
    else if (index == size)
    {
        return insertTail(value);
    }

    std::shared_ptr<ListNode<T>> previousNode = head;
    for (int i{}; i < index - 1; ++i)
    {
        previousNode = previousNode.getNext();
    }
    std::shared_ptr<ListNode<T>> nextNode = previousNode->getNext();
    std::shared_ptr<ListNode<T>> node{std::make_shared<ListNode<T>>(value)};
    node->setNext(nextNode);
    node->setPrevious(previousNode);
    previousNode->setNext(node);
    nextNode->setPrevious(node);
    size++;
}

template <typename T>
int DoublyLinkedList<T>::find(T value)
{
    if (size == 0) return -1;
    int index{};
    std::shared_ptr<ListNode<T>> current = head;
    while(current->getValue() != value)
    {
        index++;
        current = current->getNext();
        if (current == nullptr)
        {
            return -1;
        }
    }

    return index;
}

template <typename T>
void DoublyLinkedList<T>::removeHead()
{
    if (size == 0) return;
    std::shared_ptr<ListNode<T>> node = head;
    head = head->getNext();

    if (head != nullptr)
    {
        head->setPrevious(nullptr);
    }

    size--;
}

template <typename T>
void DoublyLinkedList<T>::removeTail()
{
    if (size == 0) return;
    if (size == 1)
    {
        return removeHead();
    }
    tail = tail->getPrevious();
    tail->setNext(nullptr);
    size--;
}

template <typename T>
void DoublyLinkedList<T>::remove(int index)
{
    if (size == 0 || index < 0 || index >= size) return;
    if (index == 0) return removeHead();
    else if (index == size - 1) return removeTail();
    std::shared_ptr<ListNode<T>> previousNode = head;
    for (int i{}; i < index - 1; ++i)
    {
        previousNode = previousNode->getNext();
    }
    std::shared_ptr<ListNode<T>> nodeToRemove = previousNode.getNext();
    std::shared_ptr<ListNode<T>> nextNode = nodeToRemove.getNext();
    previousNode->setNext(nextNode);
    nextNode->setPrevious(previousNode);
    size--;
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    std::shared_ptr<ListNode<T>> current = head;
    while (current != nullptr)
    {
        std::cout << current->getValue() << std::endl;
        current = current->getNext();
    }
}

#endif //ALGO_DOUBLYLINKEDLIST_H
