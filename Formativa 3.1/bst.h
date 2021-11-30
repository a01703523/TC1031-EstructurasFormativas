//Salvador Santana Blanco - A01703523

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T);

	void preorder(std::stringstream&) const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void levels(std::stringstream&) const;

	int height() const;
	bool ancestors(T, std::stringstream&) const;
	int whatlevelamI(T) const;

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
	return false;
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
		aux << " ";
	}
	if (right != 0) {
		right->postorder(aux);
		aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::levels(std::stringstream &aux) const {
    aux << value;
    if (left != 0) {
    	aux << " ";
        left->levels(aux);
    }
    if (right != 0) {
    	aux << " ";
        right->levels(aux);
    }
}

template <class T>
int Node<T>::height() const {
	int le = 0, ri = 0;
	if (left != 0) {
		le = left->height() + 1;
	}
	if (right != 0) {
		ri = right->height() + 1;
	}
	if (le == 0 && ri == 0) {
		return 1;
	}
	return (ri > le) ? ri:le;

}

template <class T>
bool Node<T>::ancestors(T val, std::stringstream &aux) const {
	if (val == value) {
	  return true;
	}
	else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	}
	else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
	return false;
}

template <class T>
int Node<T>::whatlevelamI(T val) const {
	if (val == value) {
		return 1;
	}
	else if (val < value) {
		if (left != 0) {
			return left->whatlevelamI(val) + 1;
		}
	}
	else if (val > value) {
		if (right != 0) {
			return right->whatlevelamI(val) + 1;
		}
	}
	return 0;
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	bool empty() const;
	void add(T);
	bool find(T) const;

	std::string preorder() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string levels() const;

	std::string visit() const;
	int height() const;
	std::string ancestors(T) const;
	int whatlevelamI(T) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levels() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levels(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() const {
	std::stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levels();
	return aux.str();
}

template <class T>
int BST<T>::height() const {
	return root->height();
}

template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;

	aux << "[";
    if (root) {
        if (root->find(val)){
            root->ancestors(val, aux);
		}
    }	
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	return root->whatlevelamI(val);
}


#endif /* BST_H_ */