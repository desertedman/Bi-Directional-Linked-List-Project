#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList() {
    (*this).head = NULL;
    (*this).tail = NULL;
    (*this).count = 0;
}

LinkedList::LinkedList(string word) {
    Node* newNode = new Node(word);

    (*this).head = newNode;
    (*this).tail = newNode;
    (*this).count = 1;
}

LinkedList::~LinkedList() {

    Node* currNode = (*this).head;
    Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = (*currNode).getNext();
        delete currNode;


        if (nextNode != NULL) {      //if list is not empty
            currNode = nextNode;
            nextNode = (*currNode).getNext();
        }

        else if (nextNode == NULL) {
            currNode = NULL;
            break;                    //probably dont need to do both, but good to set currNode to NULL just for safety
        }

    }

    (*this).count = 0;
    (*this).head = NULL;
    (*this).tail = NULL;

}

Node* LinkedList::getHead() const {
    return (*this).head;
}

void LinkedList::setHead(Node* headNode) {
    (*this).head = headNode;
}

Node* LinkedList::getTail() const {
    return (*this).tail;
}

void LinkedList::setTail(Node* tailNode) {
    (*this).tail = tailNode;
}

void LinkedList::push_back(string word) {
    Node* newNode = new Node(word, (*this).tail, NULL);

    if ((*this).count == 0) {     //empty list
        (*this).head = newNode;
        (*this).tail = newNode;
    }

    else {      //nonempty list
        (*(*this).tail).setNext(newNode);
        (*this).tail = newNode;
    }

    (*this).count++;
}

void LinkedList::push_back(Node* newNode) {

    if ((*this).count == 0) {     //empty list
        (*this).head = newNode;
        (*this).tail = newNode;
    }

    else {      //nonempty list
        (*(*this).tail).setNext(newNode);
        (*this).tail = newNode;
    }

    (*this).count++;

}

void LinkedList::pop() {
    cout << "Not implemented yet!" << endl;
}

void LinkedList::erase(string word) {
    cout << "Not implemented yet!" << endl;
}

void LinkedList::clear() {

    Node* currNode = (*this).head;
    Node* prevNode = NULL;

    while (currNode != NULL) {

        if ((*currNode).getPrev() != NULL) {         //we need to set a pointer to the previous node and delete that rather than currNode
            //because once currNode is deleted, we cant get to the nextNode
            prevNode = (*currNode).getPrev();
            delete prevNode;
        }

        currNode = (*currNode).getNext();

    }

    (*this).count = 0;
    (*this).head = NULL;
    (*this).tail = NULL;

}

void LinkedList::printWords() {

    Node* currNode = (*this).head;

    while (currNode != NULL) {
        cout << (*currNode).getData() << endl;
        currNode = (*currNode).getNext();
    }

}


unsigned int LinkedList::size() const {
    return (*this).count;
}

Node* LinkedList::deleteWord(Node* currNode) {

    Node* nextNode = (*currNode).getNext();
    Node* prevNode = (*currNode).getPrev();

    if (prevNode == NULL && nextNode == NULL) {       //1 word list
        (*this).setHead(NULL);
        (*this).setTail(NULL);
    }

    else if ((*currNode).getPrev() == NULL) {    //node at head of list
        (*nextNode).setPrev(NULL);
        (*this).setHead(nextNode);
    }

    else if ((*currNode).getNext() == NULL) {    //node at end of list
        (*prevNode).setNext(NULL);
        (*this).setTail(prevNode);
    }

    else {      //node in middle of list
        (*prevNode).setNext(nextNode);
        (*nextNode).setPrev(prevNode);
    }

    delete currNode;
    currNode = NULL;
    (*this).count--;

    return nextNode;
}

Node* LinkedList::insert_before(string newWord, Node* currNode) {

    Node* newNode = new Node(newWord, NULL, NULL);
    Node* prevNode = (*currNode).getPrev();
    Node* nextNode = (*currNode).getNext();      //probably dont need this


    if (prevNode != NULL && nextNode != NULL) {      //middle of list

        (*newNode).setNext(currNode);
        (*newNode).setPrev(prevNode);

        (*currNode).setPrev(newNode);
        (*prevNode).setNext(newNode);

    }

    else if (prevNode == NULL && nextNode != NULL) {      //beginning of list

        (*newNode).setNext(currNode);
        (*newNode).setPrev(NULL);

        (*currNode).setPrev(newNode);
        (*this).setHead(newNode);
    }

    (*this).count++;

    return newNode;
}


void LinkedList::mergeDicts(LinkedList* listB) {


    Node* currNodeA = (*this).getHead();
    Node* prevNodeA = (*currNodeA).getPrev();
//    Node* nextNodeA = NULL;

    Node* currNodeB = (*listB).getHead();
//    Node* prevNodeB = NULL;
    Node* nextNodeB = (*currNodeB).getNext();


    
    while (currNodeB != NULL) {

        while (currNodeA != NULL) {

            if (*currNodeA == *currNodeB) {    //nodes are equal
                delete currNodeB;

                (*this).count--;
                break;
            }

            else if (*currNodeB < *currNodeA && (*currNodeA).getPrev() == NULL) {        //beginning of list
                (*currNodeA).setPrev(currNodeB);
                (*this).setHead(currNodeB);

                (*currNodeB).setPrev(NULL);
                (*currNodeB).setNext(currNodeA);

                break;
            }

            else if (*currNodeB < *currNodeA && (*currNodeA).getPrev() != NULL) {      //middle of list

                prevNodeA = (*currNodeA).getPrev();
                (*prevNodeA).setNext(currNodeB);
                (*currNodeA).setPrev(currNodeB);

                (*currNodeB).setPrev(prevNodeA);
                (*currNodeB).setNext(currNodeA);

                break;
            }

            
            else if (*currNodeB > *currNodeA && (*currNodeA).getNext() == NULL) {      //end of list

                (*currNodeA).setNext(currNodeB);
                (*this).setTail(currNodeB);

                (*currNodeB).setPrev(prevNodeA);
                (*currNodeB).setNext(NULL);

                break;
            }
            

            currNodeA = (*currNodeA).getNext();
        }

        currNodeB = nextNodeB;
        if (nextNodeB != NULL) {
            nextNodeB = (*nextNodeB).getNext();
        }

    }

    (*this).count += (*listB).count;
}


void LinkedList::operator+=(LinkedList& list2) {

    Node* currNode;

    currNode = (*this).getTail();
    (*currNode).setNext(list2.getHead());

    (*this).setTail(list2.getTail());

    (*this).count += list2.size();

    list2.setHead(NULL);
    list2.setTail(NULL);
    list2.count = 0;

}