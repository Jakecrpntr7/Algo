//
// Created by Jacob Carpenter on 2/4/23.
//

#include <algorithm>
#include <gtest/gtest.h>
#include "../../../src/datastructures/linkedList/doublyLinkedList/DoublyLinkedList.h";

using testType = int;
std::vector<testType> testData {5, 7, 9};

TEST(DoublyLinkedList, InsertHead) {
    DoublyLinkedList<testType> linkedList{};
    for (const auto& val : testData)
    {
        linkedList.insertHead(val);
    }
    EXPECT_EQ(linkedList.getSize(), testData.size());
    std::vector<testType> results = linkedList.toVector();
    std::reverse(results.begin(), results.end());
    for(int i{}; i < testData.size(); ++i)
    {
        EXPECT_EQ(results.at(i), testData.at(i));
    }
}

TEST(DoublyLinkedList, InsertTail) {
    DoublyLinkedList<testType> linkedList{};
    for (const auto& val : testData)
    {
        linkedList.insertTail(val);
    }
    EXPECT_EQ(linkedList.getSize(), testData.size());
    std::vector<testType> results = linkedList.toVector();
    for(int i{}; i < testData.size(); ++i)
    {
        EXPECT_EQ(results.at(i), testData.at(i));
    }
}

TEST(DoublyLinkedList, RemoveHead)
{
    DoublyLinkedList<testType> linkedList{};
    for (const auto& val : testData)
    {
        linkedList.insertTail(val);
    }
    EXPECT_EQ(linkedList.getSize(), testData.size());
    for (size_t i{}; i < testData.size(); i++)
    {
        linkedList.removeHead();
    }
    EXPECT_EQ(linkedList.getSize(), 0);
}

TEST(DoublyLinkedList, RemoveTail)
{
    DoublyLinkedList<testType> linkedList{};
    for (const auto& val : testData)
    {
        linkedList.insertHead(val);
    }
    EXPECT_EQ(linkedList.getSize(), testData.size());
    for (size_t i{}; i < testData.size(); i++)
    {
        linkedList.removeTail();
    }
    EXPECT_EQ(linkedList.getSize(), 0);
}