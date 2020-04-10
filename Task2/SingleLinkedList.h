#pragma once
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

struct SLListNode
{
    int value;
    SLListNode* next = nullptr;
    SLListNode(int value) : value(value) {}
};

struct SingleLinkedList
{
    int count = 0;
    SLListNode* head = nullptr;
    void append(const int value);
    void distinct();
    int elementFromTheEnd(const int backIndex);
    int element(const int index) const;
};

#endif // !SINGLELINKEDLIST_H
