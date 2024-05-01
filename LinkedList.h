#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
using namespace std;

struct LinkedList {

private:
    Node* head;
    Node* tail;
    unsigned int count;

public:
    LinkedList();
    LinkedList(string word);
    ~LinkedList();
    Node* getHead() const;
    void setHead(Node* headNode);
    Node* getTail() const;
    void setTail(Node* tailNode);
    void push_back(string word);
    void push_back(Node* newWordNode);
    void pop();
    void erase(string word);
    void clear();
    void printWords();
    unsigned int size() const;
    Node* deleteWord(Node* desiredNode);
    Node* insert_before(string newWord, Node* knownNode);
    void mergeDicts(LinkedList* listB);


    void operator+=(LinkedList& list2);
};


#endif