#include "SingleLinkedList.h"
void SingleLinkedList::append(const int value)
{
    SLListNode* newHead = new SLListNode(value);
    if (head)
    {
        newHead->next = head;
    }
    head = newHead;
    count++;
}
void SingleLinkedList::distinct()
{
    SLListNode* selected = head;
    while (selected)
    {
        SLListNode* node1 = selected;
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
int SingleLinkedList::elementFromTheEnd(const int backIndex)
{
    int normalIndex = count - backIndex - 1;
    return element(normalIndex);
}
int SingleLinkedList::element(const int index) const
{
    auto node1 = head;
    for (int i = 0; i < index; i++)
    {
        node1 = node1->next;
    }
    return node1->value;
}