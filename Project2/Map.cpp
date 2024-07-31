// Map.cpp

#include "Map.h"
#include<iostream>
using namespace std;

Map::Map()
    : m_size(0)


{
    head = new Node;
    head->next = head;
    head->previous = head;

}

bool Map::erase(const KeyType& key)
{
    if (m_size == 0) { return false; }
    int pos = findFirstAtLeast(key);
    if (pos == m_size || findNthNode(pos)->m_data.m_key != key)  // not found
        return false;

    // Shift pairs left to replace the one erased 
    // will this go to the dummy node?

    Node* temp = findNthNode(pos);
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;

    m_size--;



    return true;
}

bool Map::get(const KeyType& key, ValueType& value) const
{

    int pos = findFirstAtLeast(key);
    if (pos == m_size || findNthNode(pos)->m_data.m_key != key)  // not found
        return false;
    value = findNthNode(pos)->m_data.m_value;

    return true;
}

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if (i < 0 || i >= m_size)
        return false;
    key = findNthNode(i)->m_data.m_key;
    value = findNthNode(i)->m_data.m_value;


    return true;
}

void Map::swap(Map& other)
{
    Node* temp = other.head;
    other.head = head;
    head = temp;



    // Swap sizes

    int t = m_size;
    m_size = other.m_size;
    other.m_size = t;
}

Map::Node* Map::findNthNode(int pos) const {
    Node* p = head->next;
    int count = 0;

    for (p; p != head && count < pos; p = p->next) {
        count++;
    }
    return p;

}

int Map::findFirstAtLeast(const KeyType& key) const
{
    // Do a binary search through the array.

    int begin = 0;
    int end = m_size;

    while (begin < end)
    {
        int mid = (begin + end) / 2;

        if (key < findNthNode(mid)->m_data.m_key)
            end = mid;
        else if (findNthNode(mid)->m_data.m_key < key)
            begin = mid + 1;
        else
            return mid;
    }
    return begin;
}

bool Map::doInsertOrUpdate(const KeyType& key, const ValueType& value,
    bool mayInsert, bool mayUpdate)
{


    int pos = findFirstAtLeast(key);
    if (pos < m_size && findNthNode(pos)->m_data.m_key == key)  // found
    {
        if (mayUpdate)
            findNthNode(pos)->m_data.m_value = value;
        return mayUpdate;
    }
    if (!mayInsert)  // not found, and not allowed to insert
        return false;


    if (head->next == head) {
        Node* add = new Node;
        add->m_data.m_key = key;
        add->m_data.m_value = value;
        Node* temp = head;
        add->next = temp->next;
        add->next->previous = add;
        add->previous = temp;
        temp->next = add;
        m_size++;
        return true;
    }
    // Shift pairs right to make room for the one to be inserted
    if (pos != 0) {
        Node* add = new Node;
        add->m_data.m_key = key;
        add->m_data.m_value = value;
        Node* temp = findNthNode(pos - 1);
        add->next = temp->next;
        add->next->previous = add;
        add->previous = temp;
        temp->next = add;
    }
    else {
        Node* add = new Node;
        add->m_data.m_key = key;
        add->m_data.m_value = value;
        Node* temp = head;
        add->next = temp->next;
        add->next->previous = add;
        add->previous = temp;
        temp->next = add;

    }

    m_size++;

    return true;
}




Map::Map(const Map& object)
{
    m_size = object.m_size;

    head = new Node;
    head->next = head;
    head->previous = head;
    for (int i = 0; i != object.m_size; i++) {
        Node* add = new Node;
        add->m_data.m_key = object.findNthNode(i)->m_data.m_key;
        add->m_data.m_value = object.findNthNode(i)->m_data.m_value;
        Node* temp;
        if (head->next == head) {
            temp = findNthNode(i);
        }
        else {
            temp = findNthNode(i - 1);
        }
        add->next = temp->next;
        add->next->previous = add;
        add->previous = temp;
        temp->next = add;
    }


}

Map& Map::operator=(const Map& copy) {
    if (this != &copy) {
        Map temp(copy);
        swap(temp);
    }
    return *this;
}

Map:: ~Map() {
    Node* p = head->next;

    while (p != head) {
        Node* temp = p->next;
        delete p;

        p = temp;
    }
    delete p;



}


void reassign(const Map& m, Map& result) { // values shifted left once in reassign
    Map newMap;
    if (m.size() == 0 || m.size() == 1) {
        result = m;
        return;
    }

    ValueType firstval;
    KeyType firstkey;
    m.get(0, firstkey, firstval);

    ValueType lastval;
    KeyType lastkey;
    m.get(m.size() - 1, lastkey, lastval);

    ValueType assignVal;
    KeyType assignKey;

    KeyType assignkey2;
    ValueType assignVal2;
    for (int i = 0; i < m.size() - 1; i++) {
        m.get(i, assignKey, assignVal);
        m.get(i + 1, assignkey2, assignVal2);
        newMap.insert(assignKey, assignVal2);
    }
    newMap.insert(lastkey, firstval);
    result = newMap;

}

bool merge(const Map& m1, const Map& m2, Map& result) {
    Map copyResult = m1;


    bool check = true;

    ValueType valm1;
    KeyType keym2;
    ValueType valm2;

    for (int i = 0; i < m2.size(); i++) {
        m2.get(i, keym2, valm2);
        if (copyResult.contains(keym2) == true) {
            copyResult.get(keym2, valm1);
            if (valm1 != valm2) {
                copyResult.erase(keym2);
                check = false;
            }
        }
        else {
            copyResult.insert(keym2, valm2);
        }
    }

    result = copyResult;
    return check;
}