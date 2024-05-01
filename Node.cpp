#include <iostream>
using namespace std;

#include "Node.h"

Node::Node() {
	(*this).data = "";
	(*this).prev = NULL;
	(*this).next = NULL;
}

Node::Node(string word) {
	(*this).data = word;
	(*this).prev = NULL;
	(*this).next = NULL;
}

Node::Node(string word, Node* prev, Node* next) {
	(*this).data = word;
	(*this).prev = prev;
	(*this).next = next;
}



string Node::getData() const {
	return (*this).data;
}

void Node::setData(string word) {
	(*this).data = word;
}



void Node::setNext(Node* next) {
	(*this).next = next;
}

Node* Node::getNext() const {
	return (*this).next;
}



void Node::setPrev(Node* prev) {
	(*this).prev = prev;
}

Node* Node::getPrev() const {
	return (*this).prev;
}




bool Node::operator==(const Node& rhs) {
	return (data == rhs.data);
}

bool Node::operator!=(const Node& rhs) {
	return (data != rhs.data);
}

bool Node::operator>(const Node& rhs) {
	return (data > rhs.data);
}

bool Node::operator<(const Node& rhs) {
	return (data < rhs.data);
}

bool Node::operator>=(const Node& rhs) {
	return (data >= rhs.data);
}

bool Node::operator<=(const Node& rhs) {
	return (data <= rhs.data);
}




bool Node::operator==(const string& rhs) {
	return (data == rhs);
}

bool Node::operator!=(const string& rhs) {
	return (data != rhs);
}

bool Node::operator>(const string& rhs) {
	return (data > rhs);
}

bool Node::operator<(const string& rhs) {
	return (data < rhs);
}

bool Node::operator>=(const string& rhs) {
	return (data >= rhs);
}

bool Node::operator<=(const string& rhs) {
	return (data <= rhs);
}




bool operator==(const string& lhs, const Node& rhs) {
	return (lhs == rhs.getData());
}

bool operator!=(const string& lhs, const Node& rhs) {
	return (lhs != rhs.getData());
}

bool operator>(const string& lhs, const Node& rhs) {
	return (lhs > rhs.getData());
}

bool operator<(const string& lhs, const Node& rhs) {
	return (lhs < rhs.getData());
}

bool operator>=(const string& lhs, const Node& rhs) {
	return (lhs >= rhs.getData());
}

bool operator<=(const string& lhs, const Node& rhs) {
	return (lhs <= rhs.getData());
}