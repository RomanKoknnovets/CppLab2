#pragma once
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

template<typename T>
struct SingleLinkedList
{
    template<typename T>
    struct SLListNode
    {
        T value;
        SLListNode<T>* next = nullptr;
        SLListNode(T value) : value(value) {}
    };
    int count = 0;
    SLListNode<T>* head = nullptr;
    void append(const T value)
    {
        SLListNode<T>* newHead = new SLListNode<T>(value);
        if (head)
        {
            newHead->next = head;
        }
        head = newHead;
        count++;
    }
    void distinct()
    {
        SLListNode<T>* selected = head;
        while (selected)
        {
            SLListNode<T>* node1 = selected;
            while (node1->next)
            {
                if (selected->value == node1->next->value)
                {
                    count--;
                    if (node1->next->next)
                    {
                        node1->next = node1->next->next;
                    }
                    else
                    {
                        node1->next = nullptr;
                        break;
                    }
                }
                else node1 = node1->next;
            }
            selected = selected->next;
        }
    }
    //так как не очень понятно, с конца это с какой стороны, то сделал с этой, т.к. от неё сложнее
    //а с другой это функция element(int)
    T elementFromTheEnd(const int backIndex) const
    {
        int normalIndex = count - backIndex - 1;
        return element(normalIndex);
    }
    T element(const int index) const
    {
        auto node1 = head;
        for (int i = 0; i < index; i++)
        {
            node1 = node1->next;
        }
        return node1->value;
    }
};

#endif // !SINGLELINKEDLIST_H
