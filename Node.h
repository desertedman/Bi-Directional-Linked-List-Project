#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;    //this makes stuff work for no reason and idk why

struct Node {

private:
    string data;
    Node* prev;
    Node* next;

public:
    Node();
    Node(string word);
    Node(string word, Node* prev, Node* next);
    string getData() const;
    void setData(string word);
    void setNext(Node* next);
    Node* getNext() const;
    void setPrev(Node* prev);
    Node* getPrev() const;

    bool operator==(const Node& rhs);
    bool operator!=(const Node& rhs);
    bool operator>(const Node& rhs);
    bool operator<(const Node& rhs);
    bool operator>=(const Node& rhs);
    bool operator<=(const Node& rhs);

    bool operator==(const string& rhs);
    bool operator!=(const string& rhs);
    bool operator>(const string& rhs);
    bool operator<(const string& rhs);
    bool operator>=(const string& rhs);
    bool operator<=(const string& rhs);

};

bool operator==(const string& lhs, const Node& rhs);
bool operator!=(const string& lhs, const Node& rhs);
bool operator>(const string& lhs, const Node& rhs);
bool operator<(const string& lhs, const Node& rhs);
bool operator>=(const string& lhs, const Node& rhs);
bool operator<=(const string& lhs, const Node& rhs);

#endif