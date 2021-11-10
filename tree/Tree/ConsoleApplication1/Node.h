#pragma once

#include <iostream>
#include <queue>
using namespace std;

#define NIL 0

enum Colors {
	RED,
	BLACK
};

template <typename T>
class Node {
public:
	T value;
	Colors color;

	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;

	Node(T valueInNode) : value(valueInNode) {
		parent = NIL;
		left = NIL;
		right = NIL;
		color = RED;
	}

	bool isOnLeft() {
		return this == parent->left;
	}

	Node<T>* uncle() {
		if (parent == NIL || parent->parent == NIL)
			return NIL;

		if (parent->isOnLeft())
			return parent->parent->right;
		else
			return parent->parent->left;
	}

	Node<T>* sibling() {
		if (parent == NIL)
			return NIL;

		if (isOnLeft())
			return parent->right;
		else
			return parent->left;
	}

	void moveDown(Node<T>* someParent) {
		if (parent != NIL) {
			if (isOnLeft())
				parent->left = someParent;
			else
				parent->right = someParent;
		}
		someParent->parent = parent;
		parent = someParent;
	}

	bool hasRedChild() {	// проверка на красного потомка
		return (left != NIL and left->color == RED) || (right != NIL and right->color == RED);
	}

};
