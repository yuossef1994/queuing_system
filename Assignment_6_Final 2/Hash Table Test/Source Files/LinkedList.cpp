#include "LinkedList.h"

LinkedList::LinkedList()
{
    _head = new Item;
    _head->next = NULL;
    _length = 0;
}

void LinkedList::insertItem(Item * newItem)
{
    if (!_head->next)
    {
        _head->next = newItem;
        _length++;
        return;
    }

    Item *p = _head;
    Item *q = _head;
    while (q)
    {
        p = q;
        q = p->next;
    }
    p->next = newItem;
    newItem->next = NULL;
    _length++;
}

bool LinkedList::removeItem(int itemKey)
{
    if (!_head->next) return false;
    Item *p = _head;
    Item *q = _head;
    while (q)
    {
        if (q->key == itemKey)
        {
            p->next = q->next;
            delete q;
            _length--;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

Item * LinkedList::getItem(int itemKey)
{
    Item *p = _head;
    Item *q = _head;
    while (q)
    {
        p = q;
        if ((p != _head) && (p->key == itemKey))
            return p;
        q = p->next;
    }
    return nullptr;
}

void LinkedList::printList()
{
    if (_length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Item *p = _head;
    Item *q = _head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != _head)
        {
            cout << p->key;
            if (p->next) cout << ", ";
            else cout << " ";
        }
        q = p->next;
    }
    cout << "}\n";
}

int LinkedList::getLength()
{
    return _length;
}
