#pragma once
#include "Node.h"

template <typename T>
class Tree {
	Node<T>* root;

	void leftRotate(Node<T>* x) {
		Node<T>* someParent = x->right;
		if (x == root)
			root = someParent;
		x->moveDown(someParent);
		x->right = someParent->left;
		if (someParent->left != NIL)
			someParent->left->parent = x;
		someParent->left = x;
	}

	void rightRotate(Node<T>* x) {
		Node<T>* someParent = x->left;
		if (x == root)
			root = someParent;
		x->moveDown(someParent);
		x->left = someParent->right;
		if (someParent->right != NIL)
			someParent->right->parent = x;
		someParent->right = x;
	}

	void changeColors(Node<T>* x, Node<T>* y) {
		Colors tmp;
		tmp = x->color;
		x->color = y->color;
		y->color = tmp;
	}

	void swapValues(Node<T>* x, Node<T>* y) {
		T tmp;
		tmp = x->value;
		x->value = y->value;
		y->value = tmp;
	}

	void fixBBColors(Node<T>* x) {
		if (x == root)
			return;

		Node<T>* sibling = x->sibling(), * parent = x->parent;
		if (sibling == NIL) {
			fixBBColors(parent);
		}
		else {
			if (sibling->color == RED) {
				parent->color = RED;
				sibling->color = BLACK;
				if (sibling->isOnLeft()) {
					rightRotate(parent);
				}
				else {
					leftRotate(parent);
				}
				fixBBColors(x);
			}
			else {
				// Sibling black
				if (sibling->hasRedChild()) {
					// at least 1 red children
					if (sibling->left != NIL and sibling->left->color == RED) {
						if (sibling->isOnLeft()) {
							// left left
							sibling->left->color = sibling->color;
							sibling->color = parent->color;
							rightRotate(parent);
						}
						else {
							// right left
							sibling->left->color = parent->color;
							rightRotate(sibling);
							leftRotate(parent);
						}
					}
					else {
						if (sibling->isOnLeft()) {
							// left right
							sibling->right->color = parent->color;
							leftRotate(sibling);
							rightRotate(parent);
						}
						else {
							// right right
							sibling->right->color = sibling->color;
							sibling->color = parent->color;
							leftRotate(parent);
						}
					}
					parent->color = BLACK;
				}
				else {
					// 2 black children
					sibling->color = RED;
					if (parent->color == BLACK)
						fixBBColors(parent);
					else
						parent->color = BLACK;
				}
			}
		}
	}

	void fixRRColors(Node<T>* x) {
		if (x == root) {
			x->color = BLACK;
			return;
		}

		Node<T>* parent = x->parent;
		Node<T>* grandparent = parent->parent;
		Node<T>* uncle = x->uncle();

		if (parent->color != BLACK) {

			if (uncle != NIL && uncle->color == RED) {
				parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				fixRRColors(grandparent);
			}
			else {

				if (parent->isOnLeft()) {

					if (x->isOnLeft()) {
						changeColors(parent, grandparent);
					}
					else {
						leftRotate(parent);
						changeColors(x, grandparent);
					}
					rightRotate(grandparent);
				}
				else {

					if (x->isOnLeft()) {
						rightRotate(parent);
						changeColors(x, grandparent);
					}
					else {
						changeColors(parent, grandparent);
					}
					leftRotate(grandparent);
				}
			}
		}
	}

	Node<T>* successor(Node<T>* x) {
		Node<T>* tmp = x;
		while (tmp->left != NIL)
			tmp = tmp->left;
		return tmp;
	}

	Node<T>* searchForReplace(Node<T>* x) {
		if (x->left != NIL and x->right != NIL) // if tree has 2 childs
			return successor(x->right);

		if (x->left == NIL and x->right == NIL) // is it leaf
			return NIL;

		if (x->left != NIL) // if 1 child
			return x->left;
		else
			return x->right;
	}

	void deleteNode(Node<T>* x) {
		Node<T>* y = searchForReplace(x);

		bool uvBlack = ((y == NIL || y->color == BLACK) && (x->color == BLACK));
		Node<T>* parent = x->parent;

		if (y == NIL) {

			if (x == root)
				root = NIL;
			else {
				if (uvBlack)
					fixBBColors(x);
				else
					if (x->sibling() != NIL)
						x->sibling()->color = RED;

				if (x->isOnLeft())
					parent->left = NIL;
				else
					parent->right = NIL;
			}
			delete x;
			return;
		}

		if (x->left == NIL or x->right == NIL) {

			if (x == root) { // 1 child
				x->value = y->value;
				x->left = x->right = NIL;
				delete y;
			}
			else {

				if (x->isOnLeft())
					parent->left = y;
				else
					parent->right = y;
				delete x;
				y->parent = parent;

				if (uvBlack)
					fixBBColors(y);
				else
					y->color = BLACK;
			}
			return;
		}

		// if 2 childs -> recursion
		swapValues(y, x);
		deleteNode(y);
	}

	void levelOrder(Node<T>* x) {
		if (x == NIL)
			return;

		queue<Node<T>*> que;
		Node<T>* current;

		que.push(x);

		while (!que.empty()) {
			current = que.front();
			que.pop();

			cout << current->value << " ";

			if (current->left != NIL)
				que.push(current->left);
			if (current->right != NIL)
				que.push(current->right);
		}
	}

	void inorder(Node<T>* x) {
		if (x == NIL)
			return;
		inorder(x->left);
		cout << x->value << " ";
		inorder(x->right);
	}

public:
	Tree() { root = NIL; }

	Node<T>* getRoot() {
		return root;
	}

	Node<T>* search(T n) {
		Node<T>* tmp = root;
		while (tmp != NIL) {
			if (n < tmp->value) {
				if (tmp->left == NIL)
					break;
				else
					tmp = tmp->left;
			}
			else if (n == tmp->value) {
				break;
			}
			else {
				if (tmp->right == NIL)
					break;
				else
					tmp = tmp->right;
			}
		}
		return tmp;
	}

	void insert(T n) {
		Node<T>* newNode = new Node<T>(n);
		if (root == NIL) {
			newNode->color = BLACK;
			root = newNode;
		}
		else {
			Node<T>* tmp = search(n);

			if (tmp->value == n) {
				return;
			}

			newNode->parent = tmp;

			if (n < tmp->value)
				tmp->left = newNode;
			else
				tmp->right = newNode;

			fixRRColors(newNode);
		}
	}

	void deleteByValue(T n) {
		if (root == NIL) // if tree is empty
			return;

		Node<T>* x = search(n), * y;

		if (x->value != n) {
			cout << "Key \"" << n << "\" isnt found in the tree!" << endl;
			return;
		}

		deleteNode(x);
	}

	void printInOrder() { 
		cout << "In order: " << endl;
		if (root == NIL)
			cout << "Empty tree!" << endl;
		else
			inorder(root);
		cout << endl;
	}

	void searchIter(T n) {
		cout << "For key: " << n << endl;
		Node<T>* tmp = search(n);
		Node<T>* ourValue = tmp;
		//ourValue = predecessorIter(tmp);
		if (ourValue->parent == NULL)
			cout << "No parent!" << endl;
		else
			cout << "Parent: " << ourValue->parent->value << endl;
		//ourValue = successorIter(tmp);
		if (ourValue->left == NULL)
			cout << "No left child!" << endl;		
		else
			cout << "Left Child: " << ourValue->left->value << endl;
		if (ourValue->right == NULL)
			cout << "No right child!" << endl;
		else
			cout << "Right Child: " << ourValue->right->value << endl;

	}

	void printLevelOrder() {
		cout << "By heights: " << endl;
		if (root == NIL)
			cout << "Empty tree!" << endl;
		else
			levelOrder(root);
		cout << endl;
	}
};